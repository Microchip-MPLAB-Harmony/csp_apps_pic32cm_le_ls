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

#include "definitions.h"
#include <arm_cmse.h>

#define SECURE_BUFFERSIZE 16

typedef enum
{
    PAGE_NUMBER_0,
    PAGE_NUMBER_1
} PAGE_NUMBERS;

uint32_t secure_data_buffer [SECURE_BUFFERSIZE];
uint32_t* dataflash_addr_page0 = (uint32_t *) DATAFLASH_ADDR;
uint32_t* dataflash_addr_page1 = (uint32_t *) (DATAFLASH_ADDR + 0x40);


/* Non-secure callable (entry) function */
bool __attribute__((cmse_nonsecure_entry)) nsc_secure_console_printf (char *buffer)
{
    size_t buffer_length = sizeof(buffer);
    
    buffer = cmse_check_address_range (buffer, buffer_length * sizeof(int), CMSE_NONSECURE);
    if (!buffer)
        return false;
    
    printf ("%s", buffer);
    return true;
}

bool __attribute__((cmse_nonsecure_entry)) nsc_secure_dataflash_erase_row ( void )
{
    return NVMCTRL_RowErase ((uint32_t) dataflash_addr_page0);
}

uint32_t __attribute__((cmse_nonsecure_entry)) nsc_secure_dataflash_write_page (PAGE_NUMBERS page_number, uint32_t *buffer)
{
    size_t length = 16;
    
    buffer = cmse_check_address_range (buffer, length * sizeof(int), CMSE_NONSECURE);
    if (!buffer)
        return false;
    
    switch (page_number)
    {
        case (PAGE_NUMBER_0):
            return NVMCTRL_PageWrite (buffer, (uint32_t)dataflash_addr_page0);
            
        case (PAGE_NUMBER_1):
            return NVMCTRL_PageWrite (buffer, (uint32_t)dataflash_addr_page1);
            
        default:
            printf ("\n\r ! ERROR: Page number must be 0 or 1");
            return -1;
    }
}

int32_t __attribute__((cmse_nonsecure_entry)) nsc_secure_dataflash_read_page (PAGE_NUMBERS page_number)
{    
    switch (page_number)
    {
        case (PAGE_NUMBER_0):
            return NVMCTRL_Read (secure_data_buffer, 64, (uint32_t)dataflash_addr_page0);
            
        case (PAGE_NUMBER_1):
            return NVMCTRL_Read (secure_data_buffer, 64, (uint32_t)dataflash_addr_page1);
            
        default:
            printf ("\n\r ! ERROR: Page number must be 0 or 1");
            return -1;
    }
}

bool __attribute__((cmse_nonsecure_entry)) nsc_display_secure_dataflash_page_content (PAGE_NUMBERS page_number)
{    
    switch (page_number)
    {
        case (PAGE_NUMBER_0):
            for (uint32_t i = 0 ; i < 16 ; i++)
            {
                if (i%2 == 0)
                    printf ("\n\r Page 0 : 0x%X : ", (uint)(dataflash_addr_page0+i));
                
                printf ("%08X ", (uint)secure_data_buffer[i]);
            }
            return 0;
            
        case (PAGE_NUMBER_1):
            for (uint32_t i = 0 ; i < 16 ; i++)
            {
                if (i%2 == 0)
                    printf ("\n\r Page 1 : 0x%X : ", (uint)(dataflash_addr_page1+i));
                
                printf ("%08X ", (uint)secure_data_buffer[i]);
            }
            return 0;
            
        default:
            printf ("\n\r ! ERROR: Page number must be 0 or 1");
            return 1;
    }
}