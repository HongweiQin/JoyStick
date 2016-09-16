/*
**  Config.h - Library for using joystick.
**  Created by Hongwei Qin (glqinhw@163.com), September 15, 2016.
**  This file covers configurations for joystick. If you want to enable one, just uncomment it.
*/

/*
**GETPOS enables the getPosition method.
**The getPosition() method allows users to get all of the position information using only one function call.
**Pros: If you usually want to get all dimensions of the stick's position information at the same time, it can save your execution time.
**Cons: It consumes more space, since we have to use some variebles to hold the position information. As you know, space matters in SOC systems.
*/
//#define JOYSTICK_GETPOS

//enable the INTR usage
#define JOYSTICK_INTR

//software filter for btn INTR
#define SWfilter
#ifdef SWfilter
#define SWFILTERTHRESHOLD 500000
#endif

