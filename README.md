# ATMEGA32U4 USB Microchip on Linux - PopOs
> cbarange | September 16th 2020
---

## Setup Development Environment
[Source](https://learn.adafruit.com/atmega32u4-breakout/setup)

1. Plug ATMEGA32U4 on USB port

2. > Install [arduino IDE](https://www.arduino.cc/en/Main/Software)
```bash
wget https://downloads.arduino.cc/arduino-1.8.13-linux64.tar.xz
tar xf arduino-1.8.13-linux64.tar.xz
cd arduino-1.8.13
sudo ./install.sh
# Run IDE as root to allow acces to serial port
sudo arduino
```

3. Go in **File > Preferences > Additional Boards Manager URLs** and insert 
`https://adafruit.github.io/arduino-board-index/package_adafruit_index.json`

4. Go in **Tools > Boards > Boards Manager** and install Install `Adafruit AVR Boards`

5. Go in **Tools > Get Boards Info** and check result
```
BN: Arduino Micro
VID: 2341
PID: 8037
SN: HIDPC
```

6. Go in **Tools > Ports** and select **Serial Port /dev/ttyACMO**

7. Go in **Tools > Boards** and select **Arduino Micro**

## First Programme

```c
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println("Hello world !");
  delay(1);// delay in between reads for stability
}
```

## Basic Usage
```c
/* TODO */
```
## Rubber Ducky - Hello World Windows10
> Example [here](https://www.youtube.com/watch?v=peyG24r4sjA) same with [ATtiny85](https://www.youtube.com/watch?v=fGmGBa-4cYQ)
```c
// Use Ducky Script
// https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payloads
/*
DELAY 3000
GUI r
DELAY 500
STRING cmd.exe
ENTER
DELAY 750
STRING echo Hello World
ENTER 
*/
// Use Rubber to Arduino converter to generate code
// https://d4n5h.github.io/Duckuino/

// Install Keyboard and KeyboardAzertyFr librairies
#include <KeyboardAzertyFr.h>
#include <HID.h>

// Utility function
void typeKey(int key){
  KeyboardAzertyFr.press(key);
  delay(50);
  KeyboardAzertyFr.release(key);
}

void setup(){
  // Start KeyboardAzertyFrAzertyFr
  KeyboardAzertyFr.begin();
  // Start Payload
  delay(3000);
  KeyboardAzertyFr.press(KEY_LEFT_GUI);
  KeyboardAzertyFr.press(114);
  KeyboardAzertyFr.releaseAll();
  delay(500);
  KeyboardAzertyFr.print("cmd.exe");
  typeKey(KEY_RETURN);
  delay(750);
  KeyboardAzertyFr.print("echo Hello World");
  typeKey(KEY_RETURN);
  // End Payload
  // Stop KeyboardAzertyFr
  KeyboardAzertyFr.end();
}
// Unused
void loop() {}
```

## Rubber Ducky - Screen Orientation Windows10
```c
#include <KeyboardAzertyFr.h>
#include <HID.h>

// Utility function
void typeKey(int key) {
  KeyboardAzertyFr.press(key);
  delay(50);
  KeyboardAzertyFr.release(key);
}

void setup() {
  // Start KeyboardAzertyFr and Mouse
  KeyboardAzertyFr.begin();
  // Start Payload
  delay(500);
  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_RIGHT_ARROW);
  KeyboardAzertyFr.releaseAll();
  delay(500);
  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_DOWN_ARROW);
  KeyboardAzertyFr.releaseAll();
  delay(500);
  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_LEFT_ARROW);
  KeyboardAzertyFr.releaseAll();
  delay(500);
  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_UP_ARROW);
  KeyboardAzertyFr.releaseAll();
  // Stop KeyboardAzertyFr and Mouse
  KeyboardAzertyFr.end();

}
// Unused
void loop() {}
```


## Advanced Usage

```c
/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}
```

## Microchip References

### Title 

HiLetgo BadUsb Beetle Bad USB Microcontroller ATMEGA32U4 Development Board Virtual Keyboard for Arduino Leonardo R3 DC 5V 16MHz

### Specifications
```
Microcontroller: ATmega32u4
Clock Speed: 16 MHz
Operating Voltage: 5V DC
Digital I/O Pins: 10
PWM Channels: 4
Analog Input Channels: 5
UART: 1
I2C: 1
Micro USB: 1
Flash Memory: 32 KB of which 4KB used by bootloader
SRAM: 2.5 KB
EEPROM: 1 KB
```

### Comments

#### From Fabien :

```
A clone from arduino Leonardo under USB key format. 
Program as Arduino Leonardo card, but contrary to Leonardo, there is not RESET button to swithc in bootloader  mode. 
```
