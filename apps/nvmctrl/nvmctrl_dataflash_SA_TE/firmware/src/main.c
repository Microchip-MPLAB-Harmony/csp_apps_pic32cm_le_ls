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

// *****************************************************************************
// *****************************************************************************
// Section: Data Inputs
// *****************************************************************************
// *****************************************************************************

#define data_buffer_length 16
uint32_t data_buffer[data_buffer_length];

uint32_t* dataflash_addr_page0 = (uint32_t *) DATAFLASH_ADDR;
uint32_t* dataflash_addr_page1 = (uint32_t *) (DATAFLASH_ADDR + 0x40);

bool tamper_detected = false;

typedef enum
{
    PAGE_NUMBER_0,
    PAGE_NUMBER_1
} PAGE_NUMBERS;

bool display_dataflash_page_content (PAGE_NUMBERS page_number)
{
    switch (page_number)
    {
        case (PAGE_NUMBER_0):
            for (uint32_t i = 0 ; i < 16 ; i++)
            {
                if (i%2 == 0)
                    printf ("\n\r Page 0 : 0x%X : ", (uint)(dataflash_addr_page0+i));
                
                printf ("%08X ", (uint)data_buffer[i]);
            }
            return 0;
            
        case (PAGE_NUMBER_1):
            for (uint32_t i = 0 ; i < 16 ; i++)
            {
                if (i%2 == 0)
                    printf ("\n\r Page 0 : 0x%X : ", (uint)(dataflash_addr_page1+i));
                
                printf ("%08X ", (uint)data_buffer[i]);
            }
            return 0;
            
        default:
            printf ("\n\r ! ERROR: Page number must be 0 or 1");
            return 1;
    }
}

void RTC_TamperDetected_Interrupt ( RTC_TIMER32_INT_MASK callback, uintptr_t context )
{
    if (callback & RTC_TIMER32_INT_MASK_TAMPER)
    {
        printf ("\n\n\r - RTC Tamper Detected !");
        printf ("\n\n\r - Press RESET button to wakeup the board\n\r");
        PM_OffModeEnter();
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    SYSTICK_TimerStart ();
    RTC_Timer32CallbackRegister (RTC_TamperDetected_Interrupt, 0);
    RTC_Timer32Start ();
    
    printf ("\33[H\33[2J");
    printf ("\n\n\r##########################################");
	printf ("\n\r#        Secure DataFlash example        #");
	printf ("\n\r##########################################");
    
    // Erase TEROW
    printf ("\n\n\r - Erase TEROW");
    NVMCTRL_RowErase ((uint32_t)dataflash_addr_page0);
    
    // Write pattern in TEROW
    printf ("\n\n\r - Write 0xCAFEDECA pattern in TEROW");
    
    // Prepare page pattern for the TEROW
    for (uint32_t i = 0; i < data_buffer_length; i++)
        data_buffer[i] = 0xCAFEDECA;
        
    // Write data_buffer's content in TEROW Page 0
    NVMCTRL_PageWrite (data_buffer, (uint32_t)dataflash_addr_page0);
    // Write data_buffer's contentTEROW Page 1
    NVMCTRL_PageWrite (data_buffer, (uint32_t)dataflash_addr_page1);

    while ( true )
    {
        printf ("\n\n\r - Print TEROW Page 0 & Page 1 content :");
        // Read TEROW Page 0 content
        NVMCTRL_Read (data_buffer, 64, (uint32_t)dataflash_addr_page0);
        // Display TEROW Page 0 content
        display_dataflash_page_content (PAGE_NUMBER_0);

        // Read TEROW Page 1 content
        NVMCTRL_Read (data_buffer, 64, (uint32_t)dataflash_addr_page1);
        // Display TEROW Page 1 content
        display_dataflash_page_content (PAGE_NUMBER_1);

        // Initiate a 1s delay using SysTick timer
        SYSTICK_DelayMs (1000);
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

