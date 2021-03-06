#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S4,     irsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    toppiece,             tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "Joystickdriver.c"

task main()
{
	waitForStart();
	int speed=50;

	motor[Right]=50;
	motor[Left]=50;
	wait10Msec(400);//go forward 5 seconds to get off the ramp

motor[Left]=-100;
		motor[Right]=100;
		wait10Msec(50);//turn 90 degrees

	while (true)
	{

		motor[Left]=100; //keep going forward then go backwards then turn... forever
		motor[Right]=100;
		wait10Msec(300);

		motor[Left]=-100;
		motor[Right]=-100;
		wait10Msec(300);

		motor[Left]=-100;
		motor[Right]=100;
		wait10Msec(50);


	}
}
