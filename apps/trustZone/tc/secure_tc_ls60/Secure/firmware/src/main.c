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

#include <arm_cmse.h>

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

funcptr_void secure_tc0_match0_interrupt_callback = NULL;
funcptr_void secure_tc0_overflow_interrupt_callback = NULL;

void secure_tc0_match0_interrupt_callback_register (funcptr_void pFunction)
{
    void *ptr;
    
    ptr = cmse_check_pointed_object (pFunction, CMSE_NONSECURE);
    
    if (ptr != NULL)
        secure_tc0_match0_interrupt_callback = ptr;
    
    else
    {
        // ERROR: Forbidden callback address location - Application Halted
        while (true);
    }
        
    return;
}

void secure_tc0_overflow_interrupt_callback_register (funcptr_void pFunction)
{
    void *ptr;
    
    ptr = cmse_check_pointed_object (pFunction, CMSE_NONSECURE);
    
    if (ptr != NULL)
        secure_tc0_overflow_interrupt_callback = ptr;
    
    else
    {
        // ERROR: Forbidden callback address location - Application Halted
        while (true);
    }
        
    return;
}

static void tc0_compare_handler (TC_COMPARE_STATUS status, uintptr_t context)
{
    if (status & TC_COMPARE_STATUS_MATCH0)
        secure_tc0_match0_interrupt_callback ();
    
    else if (status & TC_COMPARE_STATUS_OVERFLOW)
        secure_tc0_overflow_interrupt_callback ();
    
    else
    {
        // ERROR: Forbidden callback address location - Application Halted
        while (true);
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    TC0_CompareCallbackRegister (tc0_compare_handler, 0);

    if (msp_ns != 0xFFFFFFFF)
    {
        /* Set non-secure main stack (MSP_NS) */
        __TZ_set_MSP_NS(msp_ns);

        /* Get non-secure reset handler */
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        /* Start non-secure state software application */
        NonSecure_ResetHandler();
    }

    while ( true )
    {
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

