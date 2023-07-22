So you want to flash using Platformio in CLion.

Well, you're in luck. I figured it out. The first thing you have to do is make sure Platformio is installed using ```pip install platformio```. After that, open up CLion and install the Platformio plugin. When you do this, you'll have to restart, and then you want to create a new project. A Platformio option will appear in the new project dialog, and you'll get options for dozens of boards. It will look like this:
![platformio plugin](https://imgur.com/chhgOF9.png)

Select the board you need, and choose "arduino" as the framework. The platformio.ini file you get will look something like this:
```[platformio]
src_dir = .

[env:heltec_wifi_lora_32_V2]
platform = espressif32
board = heltec_wifi_lora_32_V2
framework = arduino
```

To prepare to compile, you want to change the `src_dir` to where your own code resides. I want to point mine to main.cpp, which is currently in this directory structure:

![platformio directory tree](https://imgur.com/q2xCq51.png)

My platformio.ini now looks like this:
```
[platformio]
src_dir = src

[env:heltec_wifi_lora_32_V2]
platform = espressif32
board = heltec_wifi_lora_32_V2
framework = arduino
monitor_speed = 115200
monitor_filters = time
```
As you can see, I also set the `monitor_speed` and `monitor_filters` for the board. But now comes the part we're waiting for. The dependencies can be listed line-by-line like so, using either Platformio identifiers or github links!
```
lib_deps =
; ClusterDuck Protocol
;    https://github.com/Project-Owl/Crypto.git
     jgromes/RadioLib @ ^4.4.0
;    bblanchon/ArduinoJson @ ^6.17.3
    https://github.com/Call-for-Code/ClusterDuck-Protocol.git

; uncomment for OTA update
; upload_port = duck.local
```
This can go right under the rest of the platformio.ini. Here, the CDP is linked, which will take care of all the other libraries except for RadioLib. That is included with Platformio's own identifier for the library.

## Notes On Includes
* Platformio's plugin does not keep CLion from sounding the alarm on missing libraries immediately. So a poriton of the main.cpp for this project will look like this:
  
![main.cpp](https://imgur.com/hOm0F1F.png) ![main.cpp](https://imgur.com/aAaUA1d.png)

But there is a fix. run `platformio init --ide clion` to re-init the project, then restart the IDE. This was gleaned from [here](https://github.com/platformio/platformio-core/issues/1674).

Even if you don't do this, the code will still compile, given other conditions of C++ files are met.
* There is a way around this: editing the CMakeLists file to explicitely declare include directors. This could look something like below:
```
include_directories(lib/pubsubclient/src/ lib/arduino-timer/src)
```
The `lib` folder is in the top of your directory tree, and the libraries are right below, with typical C++ project structure. If you want to include directories from CMakeLists, then you will have to have all those libraries locally somewhere. But, you will have code completion working.

* One of those other conditions is typical C++ formatting helper functions. I noticed that `.ino` files from the Arduino IDE allow you to define helper functions in any order, meaning the parser will look first, compile later. CLion follows standard rules in that all helpers have to be defined before they're used, so many of the sketch files will have to be re-arranged. 
