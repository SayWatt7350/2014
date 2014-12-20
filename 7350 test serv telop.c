
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    frontRS,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	initializeRobot();
	int frontRServ = 120;
	int threshold = 30;
	int xthreshold = 90;
	waitForStart();   // wait for start of tele-op phase

	while (true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
		if (abs(joystick.joy1_y1) > threshold)
		{
			motor[frontRight]= pow(joystick.joy1_y1,2);
		}
		else
		{
			motor[frontRight]= 0;
		}
		//
		//   Serv function
		//
		if (abs(joystick.joy1_x1) > xthreshold)
		{
			if ((joystick.joy1_x1 > xthreshold) && (frontRServ < 250))
			{
				frontRServ += 1;
				servo[frontRS]= frontRServ;
				wait1Msec(3);
			}
			if ((joystick.joy1_x1 < -xthreshold) && (frontRServ > 1))
			{
				frontRServ -= 1;
				servo[frontRS]= frontRServ;
				wait1Msec(3);
			}
		}
	}
}
