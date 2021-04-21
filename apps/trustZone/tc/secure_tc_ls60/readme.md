---
parent: Harmony 3 peripheral library application examples for PIC32CM LE00/LS00/LS60 family
title: Secure TC demonstration 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Secure TC demonstration

This example application performs a PWM signal applied on PC19 pin (LED0) based on TC0 peripheral.

## Description

This demonstrates TrustZone feature and uses two projects viz., Secure and Non-Secure Project that work together on the same
MCU and offering security isolation between the Trusted and the Non-trusted resources in the device.

- Secure project configures the TC0 peripheral to generate interrupts based on Match0 and Overflow IRQs.
- Secure project configures the SysTick to generates interrupts
- Non-secure project uses veneers to request from Secure project, the PWM signal (based on TC0 duty cycle management and delays from SysTICK) to apply to LED0 pin

## Components Used

- **TC0** - Configured as Secure peripheral
- **LED0** - Configured as Non-secure pin
- **SysTick** - Configured as Secure peripheral

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is as shown below:

| Type        | Path                         |
|:-----------:|:----------------------------:|
| Project group | apps/trustZone/tc/nonsecure_tc_ls60 |
|Secure Project|  apps/trustZone/tc/nonsecure_tc_ls60/Secure/firmware |
|Non-Secure Project|  apps/trustZone/tc/nonsecure_tc_ls60/NonSecure/firmware |
||||

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| :-----------------: | :----------------------------------------------: |
| pic32cm_ls60_cpro_Secure.X <br> pic32cm_ls60_cpro_NonSecure.X | Secure and Non-secure MPLABX project for [PIC32CM LS60 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_ls60_cpro_Secure.X <br> pic32cm_ls60_cpro_NonSecure.X | [PIC32CM LS60 Curiosity Pro Evaluation Kit]() |
|||

### Setting up [PIC32CM LS60 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the project group in the MPLAB X IDE and set the non-secure project as main project
2. Build and program the application
3. Observe the output for [PIC32CM LS60 Curiosity Pro Evaluation Kit]() as follows:
    - LED0(Green) luminosity is decreasing from maximum to minimum based on PWM signal applied by TC0 peripheral in Secure project with Non-Secure project requests through veneers