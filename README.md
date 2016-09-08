# 5-pin JoyStick driver

This is an Arduino library for the use of the 5-pin JoyStick.

## About the 5-pin JoyStick

This kind of JoyStick is commonly available on [taobao](www.taobao.com)

It contains 5 pins \(GND,+5V,VRx,VRy,SW\) to connect with your arduino board.

It contains two potentiometers that allow us to messure the movement of the stick in 2-D. 
Potentiometers are variable resistors and, in a way, they act as sensors providing us with a variable voltage depending on the rotation of the device around its shaft.

What is important is that it also contains a button which makes it able to capture the **press** activity. 
And this mechanism makes it differs from that on [arduino.cc](https://www.arduino.cc/en/Tutorial/JoyStick)

Usually, the sellers in _Taobao_ will give you some documents about this JoyStick. It works, but:

* It's not ease using.
* It makes your code less comprehensive.
* It ***DOESNOT*** contain the usage of the button.

These are what make this driver meaningful.

## Goals of this driver
* Easy to use
* Able to capture button operations
* Able to trigger interrupts\(ToBeDone\)

## Connetcions
ToBeDone



