/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#include "trustZone/nonsecure_entry.h"

/* Maximum number of DMA transfer allowed */
#define MAX_DMA_TRANSFER 10
#define DMAC_BITCOUNT_VALUE 10

SECTION_DMAC_DESCRIPTOR volatile uint16_t adc_result_store;

/* Application Modes' Definitions*/
typedef enum
{
    IDLE_MODE_IRQ,
    STANDBY_MODE_IRQ,
    STANDBY_MODE_SLPWKG,
    OFF_MODE
}APP_MODES;

extern void Light_sensor_to_data_streamer ( void );
        
// Global 8-bit array for the DGI communication
uint8_t DataStream_buf[4] = {0x03, 0x00, 0x00, 0xFC};

// Global variables for DMA descriptors
uint32_t srcBuffer = (uint32_t)(&ADC_REGS->ADC_RESULT);
uint32_t destBuffer = (uint32_t)(&adc_result_store) + (DMAC_BITCOUNT_VALUE * (DMAC_BTCTRL_STEPSIZE_X1_Val + 1));

APP_MODES app_current_mode = IDLE_MODE_IRQ;

// Global Variables
volatile bool DMAC_Flag = false;
volatile bool SW0_Flag = false;
volatile bool read_light_sensor = true;
volatile bool led0_state = false;

// *****************************************************************************
// *****************************************************************************
// Section: Function Definitions
// *****************************************************************************
// *****************************************************************************

// *** DMAC Functions *** //
// Program enters this Interrupt Handler when DMAC transfer is completed
static void TransmitCompleteCallback (DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    DMAC_Flag = true;
}

// Program enters this Interrupt Handler when on-board switch button is pressed
static void ButtonPressedCallback (uintptr_t context)
{
    SW0_Flag = true;
}

// *** EIC Functions *** //
// Program enters this Interrupt Handler when RTC counter reach 0xCCC
static void RTCCountFinished (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    ADC_ConversionStart (); 
}

// *** Application Functions *** //
// Collect light sensor results, make an average and sent it to the data streamer
void Light_sensor_to_data_streamer ( void )
{
    uint16_t average = 0;
    uint32_t light = 0;
    uint32_t light2 = 0;

    // Global 8-bit array for the DGI communication
    DataStream_buf[1] = 0;
    DataStream_buf[2] = 0;

    // Light sensor data streamer formating data
    for (uint8_t i = 0; i < (MAX_DMA_TRANSFER / 2); i++)
    {
        light = *(unsigned short*)(&adc_result_store + (i * 2));
        light2 = light + light2;
    }

    average = light2 / (MAX_DMA_TRANSFER / 2);

    // Send the average value of the last 10 ADC results
    DataStream_buf[1] = (uint8_t)average;
    DataStream_buf[2] = (uint8_t)(average>>8);
    
    // Send data through the SPI enabled channel
    SERCOM4_SPI_Write (DataStream_buf, 4);
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

// *** Non-Secure Main Function *** //
int main ( void )
{
    // Initialize all modules
    SYS_Initialize ( NULL );
    
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, TransmitCompleteCallback, 0);
    EIC_CallbackRegister (EIC_PIN_12, ButtonPressedCallback, 0);
    RTC_Timer32CallbackRegister (RTCCountFinished, 0);
    
    // Enable ADC peripheral
    ADC_Enable ();
    
    // Enable RTC peripheral
    RTC_Timer32Start ();
    
    //Replace with your SECURE application code
    while (1) 
    {
        // Start DMA Channel Transfer
        DMAC_ChannelTransfer (DMAC_CHANNEL_0, (const void*)srcBuffer, (const void*)destBuffer, 2*DMAC_BITCOUNT_VALUE );
        
		if (SW0_Flag)
        {
            SW0_Flag = false;
            if (app_current_mode == OFF_MODE)
            {
                app_current_mode = IDLE_MODE_IRQ;
            }
            else
            {
                app_current_mode++;
            }
        }

        switch (app_current_mode)
        {
            case IDLE_MODE_IRQ:
                // Unset DMA Flag
                DMAC_Flag = false;

                while (!DMAC_Flag)
                {
                    // Enter in IDLE Sleep Mode
                    nsc_pm_idle_mode_enter ();
                }
                
                // DGI Transfer to the Data Streamer
                Light_sensor_to_data_streamer ();
                break;

            case STANDBY_MODE_IRQ:
                // Unset DMA Flag
                DMAC_Flag = false;

                while (!DMAC_Flag)
                {
                    // Enter in STANDBY Sleep Mode
                    nsc_pm_standby_mode_enter ();
                }

                // DGI Transfer to the Data Streamer
                Light_sensor_to_data_streamer ();
                break;

            case STANDBY_MODE_SLPWKG:
                // Unset DMA Flag
                DMAC_Flag = false;
                
                // Disable RTC_IRQ for Sleepwalking
                RTC_Timer32InterruptDisable (RTC_TIMER32_INT_MASK_CMP0);
                NVIC_DisableIRQ (RTC_IRQn);

                // Initialize Event System for SleepWalking
                nsc_evsys_initialize ();

                while (!DMAC_Flag)
                {
                    // Enter in IDLE Sleep Mode
                    nsc_pm_standby_mode_enter ();
                }

                // DGI Transfer to the Data Streamer
                Light_sensor_to_data_streamer ();
                break;

            case OFF_MODE:
                // Unset DMA_Flag
                DMAC_Flag = false;
                
                // Disable ADC peripheral
                ADC_Disable ();
                
                // Disable RTC peripheral
                RTC_Timer32Stop ();

                // Enter in OFF Sleep Mode
                nsc_pm_off_mode_enter ();
                break;
        }
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/