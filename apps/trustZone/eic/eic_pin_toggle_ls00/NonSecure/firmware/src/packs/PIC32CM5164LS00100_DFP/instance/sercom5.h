/*
 * Instance header file for PIC32CM5164LS00100
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2022-09-09T06:09:06Z */
#ifndef _PIC32CMLS00_SERCOM5_INSTANCE_
#define _PIC32CMLS00_SERCOM5_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM5 peripheral ========== */
#define SERCOM5_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM5_DMA                              (1)        /* DMA support implemented? */
#define SERCOM5_DMAC_ID_RX                       (14)       /* Index of DMA RX trigger */
#define SERCOM5_DMAC_ID_TX                       (15)       /* Index of DMA TX trigger */
#define SERCOM5_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM5_FIFO_SIZE                        (8)        /* Rx-Tx FIFO size in bytes */
#define SERCOM5_FSYNC_IMPLEMENTED                (0)        /* SPI Frame Synch mode implemented? */
#define SERCOM5_GCLK_ID_CORE                     (22)       
#define SERCOM5_GCLK_ID_SLOW                     (16)       
#define SERCOM5_I2C_0_INT_SRC                    (51)       /* I2C 0 Interrupt */
#define SERCOM5_I2C_1_INT_SRC                    (52)       /* I2C 1 Interrupt */
#define SERCOM5_I2C_2_INT_SRC                    (53)       /* I2C 2 Interrupt */
#define SERCOM5_I2C_3_INT_SRC                    (54)       /* I2C 3 Interrupt */
#define SERCOM5_INSTANCE_ID                      (70)       /* Instance index for SERCOM5 */
#define SERCOM5_INT_MSB                          (6)        
#define SERCOM5_PMSB                             (3)        
#define SERCOM5_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM5_SPI_ERROR_INT_SRC                (54)       /* SPI ERROR Interrupt */
#define SERCOM5_SPI_RX_INT_SRC                   (53)       /* SPI RX Interrupt */
#define SERCOM5_SPI_TX_COMPLETE_INT_SRC          (52)       /* SPI TX COMPLETE Interrupt */
#define SERCOM5_SPI_TX_READY_INT_SRC             (51)       /* SPI TX READY Interrupt */
#define SERCOM5_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM5_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM5_TWI_HSMODE                       (1)        /* TWI HighSpeed mode implemented? */
#define SERCOM5_ULTRA_IMPLEMENTATION             (1)        /* ULTRA platform compatibility? */
#define SERCOM5_USART                            (1)        /* USART mode implemented? */
#define SERCOM5_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM5_USART_ERROR_INT_SRC              (54)       /* USART ERROR Interrupt */
#define SERCOM5_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM5_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM5_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM5_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM5_USART_RX_INT_SRC                 (53)       /* USART RX Interrupt */
#define SERCOM5_USART_TX_COMPLETE_INT_SRC        (52)       /* USART TX COMPLETE Interrupt */
#define SERCOM5_USART_TX_READY_INT_SRC           (51)       /* USART TX READY Interrupt */

#endif /* _PIC32CMLS00_SERCOM5_INSTANCE_ */
