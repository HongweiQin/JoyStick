# 5-pin JoyStick driver

This is an Arduino library for the use of the 5-pin JoyStick.

## About the 5-pin JoyStick

This kind of JoyStick is commonly available on [Taobao](http://www.taobao.com "http://www.taobao.com")

A tipical one looks like this:

![](https://github.com/HongweiQin/JoyStick/raw/master/JoyStick.png)

It contains 5 pins \(GND,+5V,VRx,VRy,SW\) to connect with your arduino board.

It contains two potentiometers that allow us to messure the movement of the stick in 2-D. 
Potentiometers are variable resistors and, in a way, they act as sensors providing us with a variable voltage depending on the rotation of the device around its shaft.

What is important is that it also contains a button which makes it able to capture the **press** activity. 
And this mechanism makes it differs from that on [arduino.cc](https://www.arduino.cc/en/Tutorial/JoyStick "https://www.arduino.cc/en/Tutorial/JoyStick")

Usually, the sellers in _Taobao_ will give you some documents about this JoyStick. It works, but:

* It's not ease using.
* It makes your code less comprehensive.
* It ***DOESNOT*** contain the usage of the button.

These are what make this driver meaningful.

Enjoy :D

## Goals of this driver
* Easy to use
* Able to capture button operations
* Able to trigger interrupts\(ToBeDone\)

## Connetcions

JoyStick | Arduino 
---|---
GND|GND
+5V|5V
VRx|AnalogInputPin
VRy|AnalogInputPin
SW|SeeBelow

### SW pin connection
If you want to use the INTR way to respond to button events, you need to connect your SW to an *External Interrupts pin*.\(See [About INTR](#About-INTR)\)

Otherwise, just connect to any *Digital IO Pin* or *Analog Input Pin* as you like.

### Direction
Usually, there is no sign on the joystick to indicate which the "right" direction is.

Just line it up and use the *serialPrintStatus.ino* example to give it a try.

## About INTR
Interrupt enables you to write your own Interrupt Service Routine \(ISR\) to respond to certain events. 
Correctly using interrupts can make your code more efficient.

If you decide to use INTR, you need to connect your sw with one pin that can trigger interrupts.
\(Usually pin 2 or 3, see [https://www.arduino.cc/en/Reference/AttachInterrupt](https://www.arduino.cc/en/Reference/AttachInterrupt)\)

Here are some tips about interrupts and ISR:

* Keep it short
* Don't use delay ()
* Don't do serial prints
* Make variables shared with the main code volatile
* Variables shared with main code may need to be protected by "critical sections"
* Don't try to turn interrupts off or on

For more information, you can visit [Arduino.cc](https://www.arduino.cc/en/Reference/AttachInterrupt) or [Nick Gammon's notes](http://gammon.com.au/interrupts).

### INTR Software filter

My tests shows that there are some glitches in SWpin. These glitches may cause unexpected INTR triggers.

Basically, we have two ways to address this issue:

+ We can parallel a capacitor to mitigate this issue.
+ We can use a software filter.

Uncomment/comment *SWfilter* in *Config.h* to use/unuse the software filter.

The software filter avoids the user ISR being called within a *certain time* since the last calling. 

The *certain time* can be defined by *SWFILTERTHRESHOLD* in *Config.h*\(The default value is 500 milliseconds\).

## Examples

* serialPrintStatus // This example may help you to use basic functions of this driver. Moreover, it helps you to determine your JoyStick's position.
* btnINTR //Use INTR to capture btn operations

## Licence

This repository (JoyStick) is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This repository (JoyStick) is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with iptablesTool. If not, see http://www.gnu.org/licenses/.
