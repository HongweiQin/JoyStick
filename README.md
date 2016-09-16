# 5-pin JoyStick driver

This is an Arduino library for the use of the 5-pin JoyStick.

## About the 5-pin JoyStick

This kind of JoyStick is commonly available on [Taobao](http://www.taobao.com "http://www.taobao.com")

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

### Direction
Usually, there is no sign on the joystick to indicate which the "right" position is.

Just line it up and use the *serialPrintStatus.ino* example to give it a try.

**ToBeDone**

## Some tips about INTR
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

## Examples

* serialPrintStatus // This example may help you to use basic functions of this driver. Moreover, it helps you to determine your JoyStick's position.



