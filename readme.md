---
title: Harmony 3 peripheral library application examples for PIC32CM LE/LS family
nav_order: 1
has_children: true
has_toc: false
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Harmony 3 peripheral library application examples for PIC32CM LE/LS family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 peripheral library application examples for PIC32CM LE/LS family

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

## Contents Summary

| Folder     | Description                             |
| ---        | ---                                     |
| apps       | Contains peripheral library example applications |
| docs       | Contains documentation in html format for offline viewing (to be used only after cloning this repository onto a local machine). Use [github pages](https://microchip-mplab-harmony.github.io/csp_apps_pic32cm_le_ls/) of this repository for viewing it online. |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of one or more peripheral libraries.

| Name | Description |
| ---- | ----------- |
| [AC Sleepwalking](apps/ac/ac_sleepwalk_singleshot/readme.md) | This example application shows how to use the AC Peripheral library to perform a single shot comparison in standby sleep mode periodically and wake up the device at the end of a successful comparison |
| [ADC DMA sleepwalking](../../../../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/adc/adc_dmac_sleepwalking/readme.md) | This application shows how to configure the ADC in a sleepwalking operation, where the input voltage is measured at a fixed interval, and then the device is woken from sleep after conversion of 16 samples |
| [ADC Sample](../adc_sample/readme.md) | This example application shows how to sample an analog input using the ADC and displays the converted samples on a serial terminal |
| [ADC window sleepwalking](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/adc/adc_window_sleepwalking/readme.md) | This application shows how to configure ADC in a sleepwalking operation, where input voltage is measured at a fixed interval, but device is not woken from sleep until the measured value is below a given threshold |
| [CCL Manchester Encoder](../../ccl/manchester_encoder/readme.md) | This example application shows how to use the CCL peripheral library and generate a Manchester-encoded output |
| [Clock configuration](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/clock/clock_config/readme.md) | This example application shows how to configure the clock system to run the device at maximum frequency. It also outputs a prescaled clock signal on a GPIO pin for measurement and verification |
| [DAC waveform generation](../../dac/dac_wav_gen/readme.md) | This example application shows how to use the DAC to generate a 1 KHz Sine or Sawtooth wave with a lookup table |
| [DAC waveform generation with DMA](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/dac/dac_wav_gen_dma/readme.md) | This example application shows how to use the DAC with the DMA to generate a 5 KHz sinusoidal waveform without CPU intervention |
| [DMAC memory transfer](../../dmac/dmac_memory_transfer/readme.md) | This example application demonstrates how to use the DMAC peripheral to do a memory to memory transfer |
| [DMAC USART echo](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/dmac/dmac_usart_echo/readme.md) | This example application demonstrates USART transfer with DMA to receive 10 bytes and echo back the received bytes |
| [DSU compute CRC32](../../dsu/dsu_crc32_generate/readme.md) | This example application demonstrates how to use the DSU Peripheral library to compute 32-bit Cyclic Redundancy Checksum (CRC) |
| [EIC Interrupt](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/eic/eic_led_on_off/readme.md) | This example application demonstrates how to generate interrupt using the EIC on switch press and indicate it through an LED |
| [EVSYS trigger](../../evsys/evsys_trigger/readme.md) | This example application demonstrates how to use the EVSYS Peripheral library to setup autonomous, low-latency and configurable communication between peripherals |
| [FREQM measurement](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/freqm/freqm_measure_clock_freq/readme.md) | This example application demonstrates how to use the FREQM peripheral to measure the frequency of the internal RC Oscillator |
| [NVMCTRL data flash](../../nvmctrl/nvmctrl_data_flash/readme.md) | This example application demonstrates code execution from the main Flash memory while performing erase operation in data flash section |
| [NVMCTRL read write](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/nvmctrl/nvmctrl_flash_read_write/readme.md) | This example application demonstrates how to use the NVMCTRL to erase and program the internal Flash memory |
| [OPAMP ADC gain](../../opamp/opamp_adc_gain/readme.md) | This application shows how OPAMP can be used as gain stage for the internal ADC peripheral |
| [PM wakeup using EIC](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/pm/pm_wakeup_eic/readme.md) | This application demonstrates entering the low power modes and exiting it using the EIC |
| [PM wakeup using RTC](../pm_wakeup_rtc/readme.md) | This example demonstrates entering the low power modes and exiting it using the RTC |
| [PORT polling](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/port/port_led_on_off_polling/readme.md) | This example application demonstrate how to poll the switch input, and indicate the switch status using the LED |
| [RSTC reset cause](../../rstc/rstc_reset_cause/readme.md) | This example shows how to use the RSTC peripheral to indicate the cause of the device reset |
| [RTC alarm interrupt](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/rtc/rtc_alarm/readme.md) | This example shows how to use the RTC to configure the time and generate the alarm |
| [RTC periodic interrupt](../rtc_periodic_timeout/readme.md) | This example application shows how to use the RTC to generate periodic interrupts |
| [RTC tamper detect](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/rtc/rtc_tamper_detect/readme.md) | This example application shows how to configure and use tamper detect feature of RTC |
| [SERCOM I2C EEPROM read write](../../sercom/i2c/master/i2c_eeprom/readme.md) | This example application demonstrates how to use the SERCOM peripheral to write and read from the I2C serial EEPROM memory |
| [SERCOM I2C EEPROM emulation (I2C slave)](../../../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/sercom/i2c/slave/i2c_eeprom_emulation/readme.md) | This example application demonstrates how to use the SERCOM peripheral in slave mode |
| [SERCOM SPI EEPROM read write](../../../spi/spi_eeprom_write_read/readme.md) | This example application demonstrates how to use the SERCOM SPI peripheral to write and read from the SPI serial EEPROM memory |
| [SERCOM SPI ping pong with DMA](../../Projects/h3/csp_apps_pic32cm_le_ls/apps/sercom/spi/spi_ping_pong_with_dma/readme.md) | This example demonstrates how to continuously transmit and receive data over a SPI interface using ping pong buffers with DMA |
| [SERCOM USART blocking](../../../../../../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/sercom/usart/usart_echo_blocking/readme.md) | This example application demonstrates how to use the SERCOM peripheral in USART mode to transfer block of data in a blocking manner |
| [SERCOM USART interrupt](../usart_echo_interrupt/readme.md) | This example application demonstrates how to use the SERCOM peripheral in USART mode to transfer data in a non-blocking manner |
| [SERCOM USART ring buffer](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/sercom/usart/usart_ring_buffer_interrupt/readme.md) | This example application demonstrates how to use the SERCOM peripheral in USART ring buffer mode to transfer data in a non-blocking manner |
| [Systick periodic interrupt](../../../systick/systick_periodic_timeout/readme.md) | This example shows how to use the SysTick to generate periodic interrupts |
| [TC capture mode](../../Projects/h3/csp_apps_pic32cm_le_ls/apps/tc/tc_capture_mode/readme.md) | This example shows how to use the TC module in capture mode to measure duty cycle and frequency of an external input |
| [TC compare mode](../../../../../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/tc/tc_compare_mode/readme.md) | This example shows how to use the TC module in compare mode to generate an active low, active high, and toggle output on compare match |
| [TC timer mode](../tc_timer_mode/readme.md) | This example shows how to use the TC module in timer mode to generate periodic interrupt |
| [TCC PWM generation](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/tcc/tcc_synchronous_pwm_channels/readme.md) | This example application shows how to use the TCC to generate a 2 or 3 phase PWM signals for motor control with dead time |
| [TRAM erase on tamper detect](../../tram/tram_tamper_erase/readme.md) | This example application shows how to configure and use tamper detect feature of RTC and TrustRam |
| [TRNG random number](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/trng/random_number/readme.md) | This example shows how to use the TRNG Peripheral library to generate and read a random number |
| [TrustZone EIC pin toggle](../../trustZone/eic/eic_pin_toggle/readme.md) | This example application demonstrates handling of external pin interrupt in secure and non-secure project |
| [TrustZone EVSYS trigger](../../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/trustZone/evsys/evsys_trigger/readme.md) | This example application demonstrates peripheral event handling with event system in secure and non-secure project |
| [TrustZone Systick periodic timeout](../../systick/systick_periodic_timeout/readme.md) | This example application shows how to use the SysTick to generate periodic interrupts on both Secure and Non-secure modes |
| [TrustZone basic demonstration](../../../Projects/h3/csp_apps_pic32cm_le_ls/apps/trustZone/trustZone_basic/readme.md) | This example application performs Add and Multiply Math operations in secure mode and I/O operations in non-secure mode |
| [WDT timeout](../../wdt/wdt_timeout/readme.md) | This example shows how to generate a Watchdog timer reset by emulating a deadlock |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls.svg?style=social)]()