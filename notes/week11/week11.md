# WIFI

Working with the ESP8266

## Getting Started

This guide will cover getting stared with the two following devices:

* ESP8266 NodeMCU CP2102 **ESP-12E**
* ESP8266 **ESP-01** Module

### Resources

* [Getting Started with ESP8266 WiFi Transceiver](https://randomnerdtutorials.com/getting-started-with-esp8266-wifi-transceiver-review/)

## ESP8266 NodeMCU CP2102 **ESP-12E**

### Ingredients:

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [ESP8266 NodeMCU CP2102 **ESP-12E**](https://makeradvisor.com/tools/esp8266-esp-12e-nodemcu-wi-fi-development-board/)
* [1x Micro USB cable](https://www.amazon.com/AmazonBasics-Male-Micro-Cable-Black/dp/B0711PVX6Z/) 

Additional Resources: [Arduino core for ESP8266 WiFi chip](https://github.com/esp8266/arduino)

### Arduino core for ESP8266 WiFi chip

1. Install Arduino IDE 1.8.7 or later.
2. Start the Arduino IDE and open the **Preferences** window.
3. Enter `https://arduino.esp8266.com/stable/package_esp8266com_index.json` into the **Additional Board Manager URLs** field.
4. Click **"Tools"** in the menu bar, mouse over **"Boards: ..."**, then click **"Boards Manager"**
5. Enter **"esp8266"** in the filter field and install the board package.

Documentation: [Welcome to ESP8266 Arduino Core’s documentation!](https://arduino-esp8266.readthedocs.io/en/2.5.2/)

### Connecting to the ESP8266 NodeMCU ESP-12E

Depending on where you got your NodeMCU board, it might have one of a few different chipsets, which may or may not be automatically recognized as a USB device by your computer.

This just means we need to go through some extra steps.

#### Check to see if it's recognized

1. With the Arduino IDE open, connect the NodeMCU board to your computer.
2. Click **"Tools"** in the menu bar, mouse over **"Boards: ..."**, then click **"NodeMCU 1.0 (ESP-12E Module)"**
3. Click **"Tools"** in the menu bar, mouse over **"Port"**
4. If you don't see anything that looks like `/dev/tty.SLAB_USBtoUART` or `/dev/tty.wchusbserial14210` or anything else that could possibly be the board, then you need to install the drivers for the board.

#### Installing the SiliconLabs C2102 Driver [MOST LIKELY]

* [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

#### Installing the CH340 Driver

* [CH340 Drivers for Windows, Mac and Linux](https://sparks.gogo.co.nz/ch340.html)

### Hello World

1. Install the ESP8266 Library by clicking Sketch, mousing over Include Library, and clicking Manage Libraries
2. 

## ESP8266 **ESP-01** Module