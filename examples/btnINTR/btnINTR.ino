/*
  btnINTR.ino
  Example of using JoyStick library.
  Use button to control onBoard LED.
  This example use INTR to track button events.
  Please connect your sw pin to one which can trigger interrupts(usually 2 or 3, see: https://www.arduino.cc/en/Reference/AttachInterrupt).
  Created by Hongwei Qin (glqinhw@163.com), September 15, 2016.
*/


#include <JoyStick.h>

JoyStick myJoyStick(A0,A1,2);
volatile int lightstatus;
void btnisr(){
	if(lightstatus){
		lightstatus = 0;
		digitalWrite(13, LOW);
	}else{
		lightstatus = 1;
		digitalWrite(13, HIGH);
	}
}

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  lightstatus=0;
  myJoyStick.registerBtnIntr(JSPRESS,btnisr);
}

void loop() {

}

