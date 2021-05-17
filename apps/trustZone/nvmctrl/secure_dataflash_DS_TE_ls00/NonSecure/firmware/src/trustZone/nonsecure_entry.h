/*******************************************************************************
 Non-secure entry header File for non-secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.h

  Summary:
    Function prototype declarations for Non-secure callable functions

  Description:
    This file is used to declare non-secure callable functions in non-secure project.

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

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef NONSECURE_ENTRY_H_
#define NONSECURE_ENTRY_H_

typedef enum
{
    PAGE_NUMBER_0,
    PAGE_NUMBER_1
} PAGE_NUMBERS;

/* Non-secure callable functions */

// NSC to print data to terminal through SERCOM3 peripheral
extern bool nsc_secure_console_printf (char *buffer);

// NSC to erase Data Flash row
extern bool nsc_secure_dataflash_erase_row (void);

// NSC to write buffer content into Data Flash defined address
extern uint32_t nsc_secure_dataflash_write_page (PAGE_NUMBERS page_number, uint32_t *buffer);

// NSC to read content from Data Flash defined address
extern uint32_t nsc_secure_dataflash_read_page (PAGE_NUMBERS page_number);

// NSC to display Data Flash content
extern bool nsc_display_secure_dataflash_page_content (PAGE_NUMBERS page_number);

#endif /* NONSECURE_ENTRY_H_ */