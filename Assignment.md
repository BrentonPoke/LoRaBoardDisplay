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
Example for Linux:
```sh
pio run -t upload -e ttgo-lora32-v21 --upload-port /dev/ttyUSB0
```
When the process finishes, you should see the logo of Project OWL on the screen. 
## The API
The API is a set of functions that are used to interact with the OLED screen. It is defined in a class named `DuckDisplay`.
The API is defined in the file `DuckDisplay.h` and implemented in `DuckDisplay.cpp`. You are encouraged to look at the implementation to see how it works, but you should not need to modify it.
Below are the functions currently defined in the API:
```cpp
  void setupDisplay(int duckType, std::vector<byte> name)
  void powerSave(bool save)
  void drawString(uint8_t x, uint8_t y, const char* text)
  void drawString(bool cls, uint8_t x, uint8_t y, const char* text)
  void setCursor(uint8_t x, uint8_t y)
  void print(String text)
  void clear(void)
  void sendBuffer(void)
  void log(String text)
  uint8_t getWidth()
  uint8_t getHeight()
  void showDefaultScreen()
```
Before the `DuckDisplay` class can be used, it must be instantiatied. This is typically don in the global scope pointing to `NULL` like so:
```cpp
DuckDisplay* display = NULL;
```
In the `setup()` function, the display is initialized with the following line:
```cpp
display = DuckDisplay::getInstance();
```
Notice that you are manipulating the display through a pointer to an object. This is done to minimize memory usage From here, the API can be used by calling the functions on the `display` pointer.
## Deliverable
The deliverable will be printing your name, UMID and course number on the screen under the following conditions:
* Your name will be printed in the top left corner of the screen
* Your UMID will be printed under your name
* Your course number & class section will be printed under your UMID (on the same line)
* There must be some blank space between each line (so as to be clearly legible)
The screen does not have to be cleared once the text is printed, but it should be done at least once to show that you can do it.
You may keep the `showDefaultScreen()` function call in the `setup()` function, but it is not required.
## Challenge
If you have completed the deliverable, you are encouraged to play around with the API and see what you can do.
In this spirit, you are challenged to print the same information as the deliverable, but each line individually and singularly in a loop.
The screen should only show each line in isolation for a maximum of 3 seconds before showing the next piece of information. The location can be the same or different.