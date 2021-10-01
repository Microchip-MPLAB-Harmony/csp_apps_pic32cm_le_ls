---
parent: Harmony 3 peripheral library application examples for PIC32CM LE00/LS00/LS60 family
title: SERCOM USART Start of Frame (SOF) interrupt 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SERCOM USART Start of Frame (SOF) interrupt 

This example application demonstrates how to use the SERCOM peripheral in USART ring buffer mode with SoF to wake-up device from sleep mode.

For this example:
- Performance Level 2 (PL2) is selected

## Description

This example demonstrates how to wake-up from sleep mode using USART + Start of Frame feature. The USART is configured in ring-buffer mode (interrupts enabled). The example asks the user to enter 1 character. Once received, the device wake-up from sleep, displays a message then go back to sleep. For this example the Standby mode is default sleep mode used.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is as shown below:

| Type        | Path                         |
|:-----------:|:----------------------------:|
| Project group | apps/trustZone/sercom/usart_sof_irq_ls00 |
|Secure Project|  apps/trustZone/usart_sof_irq_ls00/Secure/firmware |
|Non-Secure Project|  apps/trustZone/usart_sof_irq_ls00/NonSecure/firmware |
||||

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_ls00_cpro.X <br> pic32cm_ls00_cpro_NonSecure.X | Secure and Non-Secure MPLABX projects for MPLABX project for [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_ls00_cpro_Secure.X <br> pic32cm_ls00_cpro_NonSecure.X | [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

### Setting up [PIC32CM LS00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the EDBG Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application using its IDE
4. The console displays the following message

    ![output](images/output_sercom_usart_sof_interrupt_1.png)

    - Console displays the application header followed by message
	- The message asks user to "Enter character to wake-up from sleep mode"
    - *NOTE: For this example, the sleep mode used is Standby mode*

5. Enter 1 character on terminal
6. The device will wake-up and display message below:

    ![output](images/output_sercom_usart_sof_interrupt_2.png)

7. Then device will go back to sleep until new character is entered
