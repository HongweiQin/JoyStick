/*
  joystick.h - Library for using joystick.
  Created by Hongwei Qin (glqinhw@163.com), Febrary 21, 2016.
*/

#include "Arduino.h"
#include "joyStick.h"

#define __isRight(x) (x < JoyStickRightThrottle)
#define __isLeft(x) (x > JoyStickLeftThrottle)
#define __isUp(y) (y > JoyStickUpThrottle)
#define __isDown(y) (y < JoyStickDownThrottle)

/*
rxPin: the pin VRx connects to (analogRead pin)
ryPin: the pin VRy connects to (analogRead pin)
buttonPin: the pin SW connnects to (pass zero if you don't use it!)
*/
JoyStick::JoyStick(int rxPin, int ryPin, int buttonPin){
	#ifdef JOYSTICK_GETPOS
	xPos = 0;
	yPos = 0;
	buttonPos = 0;
	#endif
	_VRxPin = rxPin;
	_VRyPin = ryPin;
	_SwButtonPin = buttonPin;
	_xReverse = 0;
	_yReverse = 0;
	if(buttonPin){
		pinMode(buttonPin,INPUT);
		digitalWrite(buttonPin,HIGH);//The buttonPin has to be pulled up in the initialization process, or it may not work!
	}
}

/*
rxPin: the pin VRx connects to (analogRead pin)
ryPin: the pin VRy connects to (analogRead pin)
buttonPin: the pin SW connnects to
xReverse: 
   whether we should reverse left and right
   0: do not reverse
   1: reverse
yReverse:
   whether we should reverse up and down
   0: do not reverse
   1: reverse
*/
JoyStick::JoyStick(int rxPin, int ryPin, int buttonPin, int xReverse, int yReverse){
	#ifdef JOYSTICK_GETPOS
	xPos = 0;
	yPos = 0;
	buttonPos = 0;
	#endif
	_VRxPin = rxPin;
	_VRyPin = ryPin;
	_SwButtonPin = buttonPin;
	_xReverse = xReverse;
	_yReverse = yReverse;
	if(buttonPin){
		pinMode(buttonPin,INPUT);
		digitalWrite(buttonPin,HIGH);//The buttonPin has to be pulled up in the initialization process, or it may not work!
	}
}

/*
Returns:
  JoyStickLeft 
  JoyStickRight
  JoyStickMid
*/
int JoyStick::getXPos(){
	int x= analogRead(_VRxPin);
	return (((__isLeft(x) ^ _xReverse)&(!(__isRight(x) ^ _xReverse))) << 1) | ((__isRight(x) ^ _xReverse)&(!(__isLeft(x) ^ _xReverse)));
}

/*
@Return:
  JoyStickUp
  JoyStickDown
  JoyStickMid
*/
int JoyStick::getYPos(){
	int y= analogRead(_VRyPin);
	return (((__isUp(y) ^ _yReverse)&(!(__isDown(y) ^ _yReverse))) << 1) | ((__isDown(y) ^ _yReverse)&(!(__isUp(y) ^ _yReverse)));
}


int JoyStick::getBtnPos(){
	return digitalRead(_SwButtonPin);
}

#ifdef JOYSTICK_GETPOS
void JoyStick::getPosition(){
	int pressed= digitalRead(_SwButtonPin); //this variable determines whether joystick has been pressed down
	int x= analogRead(_VRxPin);//this variable holds the X-coordinate value
	int y= analogRead(_VRyPin); //this variable holds the Y-coordinate value

	xPos = ((__isLeft(x) ^ _xReverse) << 1) | (__isRight(x) ^ _xReverse);
	yPos = ((__isUp(y) ^ _yReverse) << 1) | (__isDown(y) ^ _yReverse);
	buttonPos = pressed;
	
}
#endif

/*
Reverse X dimension
*/
void JoyStick::reverseX(){
	_xReverse ^= 1;
}

/*
Reverse Y dimension
*/
void JoyStick::reverseY(){
	_yReverse ^= 1;
}

#ifdef JOYSTICK_INTR
/*
** registerBtnIntr(), register an ISR for button operations
** parameters:
** @ op: What kind of action you want to respond to. Choose one among:
** 		JSPRESS: the press action.
** 		JSRELEASE: the release action.
** 		JSCHANGE: the button status changed. 
** @ JoyStickISR: Your ISR.
*/
void JoyStick::registerBtnIntr(int op,void (*JoyStickISR)()){
	attachInterrupt(digitalPinToInterrupt(_SwButtonPin), JoyStickISR, op);
}

/*
** detachBtnIntr(), unregister button operation ISR
*/
void JoyStick::detachBtnIntr(){
	detachInterrupt(digitalPinToInterrupt(_SwButtonPin));
}
#endif

