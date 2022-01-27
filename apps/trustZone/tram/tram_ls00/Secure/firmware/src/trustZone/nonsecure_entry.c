/*******************************************************************************
 Non-secure entry source file for secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.c

  Summary:
    Implements hooks for Non-secure application

  Description:
    This file is used to call specific API's in the secure world from the Non-Secure world.

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

#define TRAM_SIZE 128

#include "definitions.h"
#include <arm_cmse.h>

/* Non-secure callable (entry) function */
void __attribute__((cmse_nonsecure_entry)) nsc_TRAM_Fill ( uint16_t pattern )
{
    uint16_t* addr_b = (uint16_t*) &TRAM_REGS->TRAM_RAM[0];
    
    // Initialize TRAM content
    for (uint8_t i = 0; i < TRAM_SIZE/2; i++)
        *addr_b++ = pattern;
}

bool __attribute__((cmse_nonsecure_entry))nsc_secure_console_printf (char *buffer)
{
    size_t *s = (size_t *)sizeof(buffer);
    
    buffer = cmse_check_address_range (buffer, *s * sizeof(int), CMSE_NONSECURE);
    if (!buffer)
        return false;
    
    printf ("%s", buffer);
    return true;
}

void __attribute__((cmse_nonsecure_entry))nsc_display_TRAM_content ( void )
{
    uint8_t *addr_TRAM;
    addr_TRAM = (uint8_t *)&TRAM_REGS->TRAM_RAM[0];
    
    for (int i=0; i < TRAM_SIZE; i=i+2)
    {
        if (i%16 == 0)
            printf ("\n\r\r");
        
        printf ("0x%02x%02x ", *(addr_TRAM + i), *(addr_TRAM + i + 1));
    }
}

void __attribute__((cmse_nonsecure_entry)) nsc_RTC_Timer32Start ( void )
{
    RTC_Timer32Start ();
}