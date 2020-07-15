[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TC timer mode

This example shows how to use the TC module in timer mode to generate periodic interrupt.

## Description

TC channel is configured in timer mode and generates periodic interrupt. LED is toggled in the interrupt handler to indicate periodic callback.

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_le00_ls00) and click

![clone](../../../docs/images/clone.png)

Path of the application within the repository is **apps/tc/tc_timer_mode/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_le00_curiosity_pro | MPLABX project for [PIC32CM LE00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_le00_curiosity_pro | [PIC32CM LE00 Curiosity Pro Evaluation Kit]()
|||

### Setting up [PIC32CM LE00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program the application using its IDE
2. Observe that the LED blinks once every second

Following table provides the LED name:

| Board      | LED Name |
| ---------- | ---------------- |--------- |
| [PIC32CM LE00 Curiosity Pro Evaluation Kit]() | LED0 |
|||