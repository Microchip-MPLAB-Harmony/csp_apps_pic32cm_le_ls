[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# DSU compute CRC32

This example application demonstrates how to use the DSU Peripheral library to compute 32-bit Cyclic Redundancy Checksum (CRC).

## Description

The DSU unit provides support for calculating a 32-bit CRC value for a memory area. This example application computes the 32-bit hardware CRC value using the DSU Peripheral and validates it using a software-calculated CRC value.

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le00_ls00) and click

![clone](../../../docs/images/clone.png)

Path of the application within the repository is **apps/dsu/dsu_crc32_generate/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_le00_curiosity_pro.X | MPLABX project for [PIC32CM LE00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_le00_curiosity_pro.X | [PIC32CM LE00 Curiosity Pro Evaluation Kit]()
|||

### Setting up [PIC32CM LE00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program the application using its IDE
2. The LED indicates the success or failure:
    - LED is turned ON when the hardware CRC value matched with the software calculated CRC value
    - LED is turned OFF when the hardware CRC value did not match with the software calculated CRC value

The following table provides the LED name

| Board      | LED Name |
| ---------- | ---------|
| [PIC32CM LE00 Curiosity Pro Evaluation Kit]() | LED1 |
|||
