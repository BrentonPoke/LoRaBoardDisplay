![CIT banner](CIT.Stamp.png)
# LoRa Board Display Exercise
An exercise for using either the TTGO or Heltec LoRa board OLED displays.

## Who this is for
This is a beginning exercise for displaying text on an ESP32 development board. The level of proficiency required is in alignment with CSC121 at University of Michigan - Flint, which is Programming I in C++. While this exercise can be done inside of a first C++ programming course, one will need to be familiar with command line tools and a CLI environment, especiallly if using Linux.

## Pre-requisites
To get started, you will need the C++ compiler, cmake and [platformio](platformio.org) installed. There are a few ways to do this, but the [Platformio IDE](https://platformio.org/platformio-ide) is the easiest. It is simply a distribution of VSCode with Platformio's CLI tools integrated within. There are also many other IDEs supported by Platformio, which can be viewed [here](https://platformio.org/install/integration). This service is a dependency manager that makes it easy to work with embeded software projects.

## Compatible Boards
The CDP currently supports the following boards:
* [LILYGO® ESP32 LoRa V1.3 SX1276](http://www.lilygo.cn/prod_view.aspx?TypeId=50003&Id=1253)
* [LILYGO® ESP32 LoRa V2.1_1.6 SX1276](https://github.com/LilyGO/TTGO-LoRa32-V2.1)
* [Heltec ESP32 LoRa V3 (SX1262)](https://www.amazon.com/MakerFocus-Development-Bluetooth-0-96inch-Display/dp/B076MSLFC9)
* [Heltec ESP32 LoRa V2 (SX1276)](https://heltec.org/project/wifi-lora-32)

## Assignment
The assignment is to print your name, UMID and course number on the screen. The instruction for the assignment can be found in the [assignment.md](assignment.md) file.