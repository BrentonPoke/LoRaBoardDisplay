/**
 * @file main.cpp
 * @author
 * @brief This example creates a duck link that updates the display on a loop.
 *
 * It's using a pre-built DuckLink available from the ClusterDuck SDK
 */

#include <arduino-timer.h>
#include <string>
#include <DuckLink.h>

#ifdef SERIAL_PORT_USBVIRTUAL
#define Serial SERIAL_PORT_USBVIRTUAL
#endif

// create a built-in duck link
DuckLink duck;
DuckDisplay* display = NULL;
// create a timer with default settings
auto timer = timer_create_default();

// for sending the counter message
const int INTERVAL_MS = 3000;
int counter = 1;

//this is conventionally named runSensor(void *), but can be any name so long as it returns bool
//and takes a void pointer. The reason for this is that the function is passed 
bool runSensor(void *);

//The setup function is run only once on boot.
void setup() {
  // We are using a hardcoded device id here, but it should be retrieved or
  // given during the device provisioning then converted to a byte vector to
  // setup the duck NOTE: The Device ID must be exactly 8 bytes otherwise it
  // will get rejected
  display = DuckDisplay::getInstance();
  duck.setupSerial(115200);
  std::string deviceId("DUCK0001");
  std::vector<byte> devId;
  devId.insert(devId.end(), deviceId.begin(), deviceId.end());
  display->setupDisplay(duck.getType(), devId);
  duck.setupWithDefaults(devId);

  // Initialize the timer. The timer thread runs separately from the main loop
  // and will trigger sending a counter message.
  timer.every(INTERVAL_MS, runSensor);
  Serial.println("[LINK] Setup OK!");
  display->showDefaultScreen();
  
}

//This is the equivalent of an int main() function in a normal C++ command line program.
//With the Clusterduck Protocol SDK, all that's necessary inside loop() is the two lines below.
void loop() {
  timer.tick();
  duck.run();
}

//This is the function that is called by the timer class. We will use it to do the printing on an interval.
bool runSensor(void *) {
  bool result = false;
    //display a message on the OLED...
    display->clear();
    display->setCursor(0, 0);
    display->drawString(0,10,"New Message");
    display->drawString(0,20,"TEST");
    display->drawString(0,30,"test");
    display->sendBuffer();
    result = true;
  return result;
}
