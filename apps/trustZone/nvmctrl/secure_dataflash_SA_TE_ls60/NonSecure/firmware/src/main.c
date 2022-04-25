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

// *****************************************************************************
// *****************************************************************************
// Section: Data Inputs
// *****************************************************************************
// *****************************************************************************

#define data_buffer_length 16
uint32_t data_buffer[data_buffer_length];


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
    
    nsc_secure_console_printf ("\33[H\33[2J");
    nsc_secure_console_printf ("\n\n\r##########################################");
	nsc_secure_console_printf ("\n\r#        Secure DataFlash example        #");
	nsc_secure_console_printf ("\n\r##########################################");
    
    // Erase TEROW
    nsc_secure_console_printf ("\n\n\r - Erase TEROW");
    nsc_secure_dataflash_erase_row ();
    
    // Write pattern in TEROW
    nsc_secure_console_printf ("\n\n\r - Write 0xCAFEDECA pattern in TEROW");    
    
    // Prepare page pattern for the TEROW
    for (uint32_t i = 0; i < data_buffer_length; i++)
        data_buffer[i] = 0xCAFEDECA;
        
    // Write data_buffer's content in TEROW Page 0
    nsc_secure_dataflash_write_page (PAGE_NUMBER_0, data_buffer);
    // Write data_buffer's contentTEROW Page 1
    nsc_secure_dataflash_write_page (PAGE_NUMBER_1, data_buffer);

    while ( true )
    {    
        nsc_secure_console_printf ("\n\n\r - Print TEROW Page 0 & Page 1 content :");
        // Read TEROW Page 0 content
        nsc_secure_dataflash_read_page (PAGE_NUMBER_0);
        // Display TEROW Page 0 content
        nsc_display_secure_dataflash_page_content (PAGE_NUMBER_0);

        // Read TEROW Page 1 content
        nsc_secure_dataflash_read_page (PAGE_NUMBER_1);
        // Display TEROW Page 1 content
        nsc_display_secure_dataflash_page_content (PAGE_NUMBER_1);
        
        SYSTICK_DelayMs (1000);
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

