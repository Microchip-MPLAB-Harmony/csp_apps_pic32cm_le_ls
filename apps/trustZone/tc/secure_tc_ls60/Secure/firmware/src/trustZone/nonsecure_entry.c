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

#include <stdint.h>
#include <definitions.h>
#include <arm_cmse.h>

typedef void ( *secure_void_cb_t ) ( void );
typedef void ( *funcptr_void ) (void) __attribute__((cmse_nonsecure_call));

extern void secure_tc0_match0_interrupt_callback_register (funcptr_void pFunction);
extern void secure_tc0_overflow_interrupt_callback_register (funcptr_void pFunction);

void __attribute__((cmse_nonsecure_entry)) nsc_TC0_DutyCycle_Set ( uint8_t duty_cycle )
{
    TC0_Compare8bitMatch0Set (duty_cycle);
}

void __attribute__((cmse_nonsecure_entry)) nsc_TC0_CompareStart ( void )
{
    TC0_CompareStart ();
}

void __attribute__((cmse_nonsecure_entry)) nsc_SYSTICK_TimerStart ( void )
{
    SYSTICK_TimerStart ();
}

void __attribute__((cmse_nonsecure_entry)) nsc_SYSTICK_DelayMs ( uint8_t delay_ms )
{
    SYSTICK_DelayMs ( delay_ms );
}

void __attribute__((cmse_nonsecure_entry)) nsc_tc0_match0_interrupt_callback_register ( secure_void_cb_t pfunction )
{
	secure_tc0_match0_interrupt_callback_register ((funcptr_void) pfunction);
}

void __attribute__((cmse_nonsecure_entry)) nsc_tc0_overflow_interrupt_callback_register ( secure_void_cb_t pfunction )
{
	secure_tc0_overflow_interrupt_callback_register ((funcptr_void) pfunction);
}