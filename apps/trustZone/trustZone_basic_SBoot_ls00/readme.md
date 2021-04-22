---
parent: Harmony 3 peripheral library application examples for PIC32CM LE00/LS00/LS60 family
title: TrustZone basic with Secure Boot demonstration 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TrustZone basic with Secure Boot demonstration

This example application performs Add and Multiply math operations in Secure Flash BOOT and APPLICATION regions called through veneers in Non Secure Flash APPLICATION region. The LED0 (Green) is switched on in BootSecure application and the LED1 (Red) in Secure application.

For this example:
- BOCOR.BOOTOPT = 0x3, which means the HMAC with BOOTKEY Secure Boot Verification Method is applied at start-up
- BOCOR.BOOTKEY filled with 1's
- Performance Level 2 (PL2) is selected

## Description
 
This example is based on trustZone_basic example and provides a BootSecure project in addition to the Secure and NonSeucre projects 
to demonstrate Secure Boot feature capability over TrustZone feature.

The TrustZone basic with Secure Boot demonstration then provides a three level project example:
- BootSecure project implements math functions (add and multiply as example) and switch on the on-board LED0 (Green) on the BOOT region.
- Secure project implements math functions (add and multiply as example) and switch on the on-board LED1 (Red) on the Secure APPLICATION region.
- Non-secure project uses the math functions on the Non-Secure APPLICATION region exposed by bootsecure and secure projects for math operations through veneers.

## Components Used

- **LED0 (Green)** Configured as Secure pin (in BOOT region)
- **LED1 (Red)** Configured as Secure pin (in APPLICATION region)

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le_ls) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is as shown below:

| Type        | Path                         |
|:-----------:|:----------------------------:|
| Project group | apps/trustZone/trustZone_basic_SBoot_ls00 |
|BootSecure Project|  apps/trustZone/trustZone_basic_SBoot_ls00/BootSecure/firmware |
|Secure Project|  apps/trustZone/trustZone_basic_SBoot_ls00/Secure/firmware |
|Non-Secure Project|  apps/trustZone/trustZone_basic_SBoot_ls00/NonSecure/firmware |
||||

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| :-----------------: | :----------------------------------------------: |
| pic32cm_ls00_BootSecure.X <br> pic32cm_ls00_cpro_Secure.X <br> pic32cm_ls00_cpro_NonSecure.X | BootSecure, Secure and Non-secure MPLABX projects for [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_ls00_BootSecure.X <br> pic32cm_ls00_cpro_Secure.X <br> pic32cm_ls00_cpro_NonSecure.X | [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

### Setting up [PIC32CM LS00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the project group in the MPLAB X IDE and set the non-secure project as main project
2. Build and program the application
3. The two on-board LEDs should switch on with a delay due to the Secure Boot Verification and the math operations are performed in Non-Secure application
**Note:** The application can be launched in debug mode to do step-by-step and observe how the jumps from non-secure project to bootsecure or secure project are performed