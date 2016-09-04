/*
  joystick.h - Library for using joystick.
  Created by Hongwei Qin (glqinhw@163.com), Febrary 21, 2016.
*/

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"

/*
**The getPosition() method allows users to get all of the position information using only one function call.
**Good side: If you usually want to get all dimensions of the stick's position information at the same time, it can save your execution time.
**Bad side: It consumes more space, since we have to use some variebles to hold the position information. As you know, space matters in SOC systems.
**uncomment to use it.
*/
//#define GETPOS

#define JoyStickBtnPressed 0
#define JoyStickBtnReleased 1

#define JoyStickLeft 2
#define JoyStickRight 1
#define JoyStickMid 0
#define JoyStickUp 2
#define JoyStickDown 1

#define JoyStickUpThrottle 924
#define JoyStickDownThrottle 100
#define JoyStickLeftThrottle 924
#define JoyStickRightThrottle 100


class JoyStick 
{
public:
#ifdef GETPOS
	int xPos;
	int yPos;
	int buttonPos;
#endif
	JoyStick(int rxPin, int ryPin, int buttonPin);
	JoyStick(int rxPin, int ryPin, int buttonPin, int xReverse, int yReverse);
	int getXPos();
	int getYPos();
	int getBtnPos();
#ifdef GETPOS
	void getPosition();
#endif
	void reverseX();
	void reverseY();
	void registerReleaseBtnIntr(void (*BtnIsr)());
	void registerPressBtnIntr(void (*BtnIsr)());
	void detachBtnIntr();
	
private:
	int _VRxPin;
	int _VRyPin;
	int _SwButtonPin;
	int _xReverse;// 1:reverse, 0:not reverse
	int _yReverse;// 1:reverse, 0:not reverse
};

#endif
