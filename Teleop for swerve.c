#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     FR_Drive,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     FL_Drive,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     BR_Drive,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     BL_Drive,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_1,    servo7,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo12,              tServoNone)
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
	servo[FR_servo]= 0;
	servo[FL_servo]= 0;
	servo[BR_servo]= 0;
	servo[BL_servo]= 0;
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
	int servoSetting = 120;
	int threshold = 30;
	int xthreshold = 90;
	waitForStart();   // wait for start of tele-op phase

	while (true)
	{
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
		if (abs(joystick.joy1_y1) > threshold)
		{
			motor[FR_Drive]= joystick.joy1_y1;
			motor[FL_Drive]= joystick.joy1_y1;
			motor[BR_Drive]= joystick.joy1_y1;
			motor[BL_Drive]= joystick.joy1_y1;

		}
		else
		{
			motor[FR_Drive]= 0;
			motor[FL_Drive]= 0;
			motor[BR_Drive]= 0;
			motor[BL_Drive]= 0;
		}
		//
		//   Serv function
		//
		if (abs(joystick.joy1_x1) > xthreshold)
		{
			if ((joystick.joy1_x1 > xthreshold) && (servoSetting < 250))
			{
				servoSetting += 1;
				servo[FR_servo]= servoSetting;
				servo[FL_servo]= servoSetting;
				servo[BR_servo]= servoSetting;
				servo[BL_servo]= servoSetting;
				wait1Msec(3);
			}
			if ((joystick.joy1_x1 < -xthreshold) && (servoSetting > 1))
			{
				servoSetting -= 1;
				servo[FR_servo]= servoSetting;
				servo[FL_servo]= servoSetting;
				servo[BR_servo]= servoSetting;
				servo[BL_servo]= servoSetting;
				wait1Msec(3);
			}
		}
	}
}
!
