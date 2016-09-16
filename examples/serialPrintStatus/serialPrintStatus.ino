/*
  serialPrintStatus.ino
  Example of using JoyStick library.
  Use Serial to print the joy stick's status.
  Created by Hongwei Qin (glqinhw@163.com), Febrary 21, 2016.
*/

#include <JoyStick.h>

int pos;
JoyStick myJoyStick(A0,A1,8);//VRx pin, VRy pin, SW pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("---------------------------------");
  pos = myJoyStick.getXPos();
  Serial.print("joyStick's x position is ");
  if(pos == JoyStickLeft)
  {
  	Serial.println("left");
  }
  else if(pos == JoyStickRight)
  {
  	Serial.println("right");
  }
  else
  {
  	Serial.println("middle");
  }
  
  pos = myJoyStick.getYPos();
  Serial.print("joyStick's y position is ");
  if(pos == JoyStickUp)
  {
  	Serial.println("up");
  }
  else if(pos == JoyStickDown)
  {
  	Serial.println("down");
  }
  else
  {
  	Serial.println("middle");
  }

  pos = myJoyStick.getBtnPos();
  Serial.print("joyStick's Btn position is ");
  if(pos == JoyStickBtnPressed)
  {
  	Serial.println("pressed");
  }
  else
  {
  	Serial.println("released");
  }
  delay(1000);

}
