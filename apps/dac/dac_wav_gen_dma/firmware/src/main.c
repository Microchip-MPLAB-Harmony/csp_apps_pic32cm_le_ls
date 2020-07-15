/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project. The "main" function
    calls the "SYS_Initialize" function to initialize the state machines of all 
    modules in the system.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define NUM_OF_SAMPLES (100)

const uint16_t sine_wave[NUM_OF_SAMPLES] = {
0x800,0x880,0x900,0x97f,0x9fd,0xa78,0xaf1,0xb67,0xbda,0xc49,
0xcb3,0xd19,0xd79,0xdd4,0xe29,0xe78,0xec0,0xf02,0xf3c,0xf6f,
0xf9b,0xfbf,0xfdb,0xfef,0xffb,0xfff,0xffb,0xfef,0xfdb,0xfbf,
0xf9b,0xf6f,0xf3c,0xf02,0xec0,0xe78,0xe29,0xdd4,0xd79,0xd19,
0xcb3,0xc49,0xbda,0xb67,0xaf1,0xa78,0x9fd,0x97f,0x900,0x880,
0x800,0x77f,0x6ff,0x680,0x602,0x587,0x50e,0x498,0x425,0x3b6,
0x34c,0x2e6,0x286,0x22b,0x1d6,0x187,0x13f,0xfd,0xc3,0x90,
0x64,0x40,0x24,0x10,0x4,0x0,0x4,0x10,0x24,0x40,
0x64,0x90,0xc3,0xfd,0x13f,0x187,0x1d6,0x22b,0x286,0x2e6,
0x34c,0x3b6,0x425,0x498,0x50e,0x587,0x602,0x680,0x6ff,0x77f,
};


__attribute__((__aligned__(16))) static dmac_descriptor_registers_t pTxLinkedListDesc[1];

#define BUFFER_TX_BTCTRL    (DMAC_BTCTRL_STEPSIZE_X2 | DMAC_BTCTRL_SRCINC_Msk |     \
                             DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_BLOCKACT_INT | DMAC_BTCTRL_VALID_Msk)


void InitializeTxLinkedListDescriptor(void)
{
    pTxLinkedListDesc[0].DMAC_BTCTRL     = (uint16_t)BUFFER_TX_BTCTRL;
    pTxLinkedListDesc[0].DMAC_BTCNT      = NUM_OF_SAMPLES;
    pTxLinkedListDesc[0].DMAC_DESCADDR   = (uint32_t)&pTxLinkedListDesc[0];
    pTxLinkedListDesc[0].DMAC_DSTADDR    = (uint32_t)&DAC_REGS->DAC_DATA[0];
    pTxLinkedListDesc[0].DMAC_SRCADDR    = (uint32_t)sine_wave + sizeof(sine_wave);   
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

    InitializeTxLinkedListDescriptor();
    
    DMAC_ChannelLinkedListTransfer(DMAC_CHANNEL_0, &pTxLinkedListDesc[0]);         
    TC0_TimerStart();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */       
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

