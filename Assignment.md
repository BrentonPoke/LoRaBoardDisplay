In this exercise, you will be printing text to the OLED screen using the ClusterDuck Protocol's API. By the end, you should be able to print text in different areas of the screen as well as clearing it of any text. While there is a deliverable, this is meant to be exploratory in nature and you're encouraged to toy with parameters at your leisure.
## Getting Started
The first thing to do is open the file `main.cpp` where a sample program has been written that can be compiled and flashed to the board you've chosen. Do this with a terminal command as in the form below:
```
 pio run -t upload -e <ENV> --upload-port <PORT>
```
Where `<ENV>` is the environment in the `platformio.ini` that is included in this project and `<PORT>` is the serial port the board is connected on. You can find this port by the command `pio device list`. Note that port numbers in Windows an Linux are named very differently:
```PowerShell
pio run -t upload -e ttgo-lora32-v21 --upload-port COM3
```
```sh
pio run -t upload -e ttgo-lora32-v21 --upload-port /dev/ttyUSB0
```
