/*
  joystick.h - Library for using joystick.
  Created by Hongwei Qin (glqinhw@163.com), Febrary 21, 2016.
*/

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"
#include "Config.h"

#define JSPRESS FALLING
#define JSRELEASE RISING
#define JSCHANGE CHANGE


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



#ifdef JOYSTICK_INTR
static void (*__btnUsrISR)();//user btnISR handler
static void btnISR();
#endif

class JoyStick {
public:
#ifdef JOYSTICK_GETPOS
	int xPos;
	int yPos;
	int buttonPos;
#endif
	JoyStick(int rxPin, int ryPin, int buttonPin);
	JoyStick(int rxPin, int ryPin, int buttonPin, int xReverse, int yReverse);
	int getXPos();
	int getYPos();
	int getBtnPos();
#ifdef JOYSTICK_GETPOS
	void getPosition();
#endif
	void reverseX();
	void reverseY();
#ifdef JOYSTICK_INTR
	void registerBtnIntr(int op,void (*JoyStickISR)());
	void detachBtnIntr();
#endif
	
private:
	int _VRxPin;
	int _VRyPin;
	int _SwButtonPin;
	int _xReverse;// 1:reverse, 0:not reverse
	int _yReverse;// 1:reverse, 0:not reverse
};

#endif
