/*******************************************************************************
  Analog Comparator PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ac.h

  Summary:
    AC Header File

  Description:
    This file defines the interface to the AC peripheral library.
    This library provides access to and control of the Analog Comparator.

  Remarks:
    None.

*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
#ifndef PLIB_AC_H    // Guards against multiple inclusion
#define PLIB_AC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "device.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef enum
{
    AC_CHANNEL0 = 0,
    AC_CHANNEL1 = 1,
    AC_CHANNEL2 = 2,
    AC_CHANNEL3 = 3,
}AC_CHANNEL;

typedef enum
{
    AC_POSINPUT_AIN0 = AC_COMPCTRL_MUXPOS_AIN0,
    AC_POSINPUT_AIN4 = AC_COMPCTRL_MUXPOS_AIN4,
    AC_POSINPUT_AIN1 = AC_COMPCTRL_MUXPOS_AIN1,
    AC_POSINPUT_AIN5 = AC_COMPCTRL_MUXPOS_AIN5,
    AC_POSINPUT_AIN2 = AC_COMPCTRL_MUXPOS_AIN2,
    AC_POSINPUT_AIN6 = AC_COMPCTRL_MUXPOS_AIN6,
    AC_POSINPUT_AIN3 = AC_COMPCTRL_MUXPOS_AIN3,
    AC_POSINPUT_AIN7 = AC_COMPCTRL_MUXPOS_AIN7,
}AC_POSINPUT;


typedef enum
{
    AC_NEGINPUT_AIN0 = AC_COMPCTRL_MUXNEG_AIN0,
    AC_NEGINPUT_AIN4 = AC_COMPCTRL_MUXNEG_AIN4,
    AC_NEGINPUT_AIN1 = AC_COMPCTRL_MUXNEG_AIN1,
    AC_NEGINPUT_AIN5 = AC_COMPCTRL_MUXNEG_AIN5,
    AC_NEGINPUT_AIN2 = AC_COMPCTRL_MUXNEG_AIN2,
    AC_NEGINPUT_AIN6 = AC_COMPCTRL_MUXNEG_AIN6,
    AC_NEGINPUT_AIN3 = AC_COMPCTRL_MUXNEG_AIN3,
    AC_NEGINPUT_AIN7 = AC_COMPCTRL_MUXNEG_AIN7,
}AC_NEGINPUT;

typedef void (*AC_CALLBACK) (uint8_t int_flags, uintptr_t context);

typedef struct
{
    uint8_t int_flags;
    AC_CALLBACK callback;
    uintptr_t    context;

} AC_OBJECT ;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void AC_Initialize (void);

void AC_Start( AC_CHANNEL channel_id );

void AC_SwapInputs( AC_CHANNEL channel_id );

bool AC_StatusGet (AC_CHANNEL channel);

void AC_CallbackRegister (AC_CALLBACK callback, uintptr_t context);

void AC_SetVddScalar( AC_CHANNEL channel_id , uint8_t vdd_scalar);

void AC_ChannelSelect( AC_CHANNEL channel_id , AC_POSINPUT positiveInput, AC_NEGINPUT negativeInput);

#ifdef __cplusplus // Provide C++ Compatibility
}
#endif

#endif /* PLIB_AC_H */
