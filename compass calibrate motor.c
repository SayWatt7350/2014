#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S3,     compass,         sensorI2CCustom)
#pragma config(Sensor, S4,     Mux,            sensorI2CCustom9V)
#pragma config(Motor,  mtr_S1_C1_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightBack,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     elevator1,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     elevator2,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     LeftFront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     LeftBack,      tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    frontRS,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    backRS,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    lock,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_1,    frontLS,              tServoStandard)
#pragma config(Servo,  srvo_S2_C3_2,    backLS,               tServoStandard)
#pragma config(Servo,  srvo_S2_C3_3,    score,                tServoStandard)
#pragma config(Servo,  srvo_S2_C3_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo12,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_1,    leftmandible,         tServoStandard)
#pragma config(Servo,  srvo_S2_C4_2,    rightmandible,        tServoStandard)
#pragma config(Servo,  srvo_S2_C4_3,    mouth,                tServoStandard)
#pragma config(Servo,  srvo_S2_C4_4,    gate,                 tServoStandard)
#pragma config(Servo,  srvo_S2_C4_5,    servo23,              tServoNone)
#pragma config(Servo,  srvo_S2_C4_6,    servo24,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#include "hitechnic-compass.h"


int speed = 50;//default motor speed
int fullspeed = 100;//motor speed variables



int sFRS = 90;//servo values
int sBRS = 109;
int sFLS = 132;
int sBLS = 131;

int straight_FRS = 161;
int straight_BRS = 154;
int straight_FLS = 132;
int straight_BLS = 131;


int FRS =0;
int BRS = 0;
int FLS  = 0;
int BLS = 0;

int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side









//
//   turnServos will turn the servos to one of five positions, then wait 150ms to adjust if lastpos is different then intended position.
//		turnpos =
//				1 = straight
//				2 = spin turn
//				3 = 45 degree angle to right
//				4 = 45 degree angle to left
//				5 = sideways
//

void turnServos(int turnpos, int lastpos)
{
	if (lastpos != turnpos)    // Only execute if the new position is different than the old position. otherwise return.
	{
		//   straight defaults
		// define temporary variables servo default is straight.
		int sFRS = 161;
		int sBRS = 131;
		int sFLS = 132;
		int sBLS = 131;

		//  Motors set to stop
		int mFRS =0;
		int mBRS = 0;
		int mFLS  = 0;
		int mBLS = 0;
		//
		// first, stop motors so don't create strain on servos.
		//
		motor[RightFront] = mFRS;
		motor[LeftFront] = mFLS;
		motor[RightBack] = mBRS;
		motor[LeftBack] = mBLS;
		wait1Msec(100);  // delay so don't overdraw current on servo block;


		switch (turnpos)
		{
		case 1:							// gostraight
			sFRS = 161;
			sBRS = 131;
			sFLS = 132;
			sBLS = 131;
			break;

		case 2:							// spin
			sFRS = 107;				//   						\  	u
			sBRS = 166;				//  						/	 	u
			sFLS = 170;				//		/							u
			sBLS = 95;				//		\							u
			// set motors direction to help servos and turn same direction as servo.
			/*			if (lastpos == 1)  // straight to spin
			{
			mFRS = mBLS = -30;
			mFLS = mBLS = 30;
			} else if (lastpos == 5)  // sideways to spin
			{
			mFRS = mBLS = 30;
			mFLS = mBLS = -30;
			}
			*/
			break;

		case 3:				// 45 degree turn to right  ???
			sFRS = 219;				//   						/
			sBRS = 166;				//  						/
			sFLS = 170;				//		/
			sBLS = 168;				//	 ??? /
			break;


		case 4:				// 45 degree turn to left ???
			sFRS = 107;				//   						\		u
			sBRS = 96;				//  						\		u
			sFLS = 100;				//		\							u
			sBLS = 95;				//	  \							u
			break;

		case 5:				// sideways ???
			sFRS = 49;				//   						->
			sBRS = 203;				//  						->
			sFLS = 255;				//		->
			sBLS = 56;				//	  ->
			break;

		case 6:// 20 degree value between | and /
			sFRS = 191;
			sBRS = 154;
			sFLS = 191;
			sBLS = 154;
			break;


		default:			// gostraight

			sFRS = 161;
			sBRS = 131;
			sFLS = 132;
			sBLS = 95;
			break;
		}   // end of switch

		// turn motor to help servo turn or leave it stopped
		/*		motor[RightFront] = mFRS;
		motor[LeftFront] = mFLS;
		motor[RightBack] = mBRS;
		motor[LeftBack] = mBLS;
		wait1Msec(100);  // delay so don't overdraw current on servo block;
		*/
		//
		//  now turn servos
		//
		servo[frontRS]= sFRS;
		wait1Msec(100);  // delay so don't overdraw current on servo block;
		servo[backRS]= sBRS;
		wait1Msec(100);  // delay so don't overdraw current on servo block;
		servo[frontLS]= sFLS;
		wait1Msec(100);  // delay so don't overdraw current on servo block;
		servo[backLS]= sBLS;
		//	wait1Msec(2000);		// only do this if changing servo pos.   if same as last time, then skip.

		//
		// Now, stop motors.  Will be restarted in new direction.
		//
		/*		motor[RightFront] = 0;
		motor[LeftFront] = 0;
		motor[RightBack] = 0;
		motor[LeftBack] = 0;
		*/
	}

	lastpos = turnpos;
	return;
}

void turnleft()//turn 1 degrees left
{


	int speed=70;
	int clicks=1440*3*(PI/8)/90;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(nMotorEncoder[RightBack] < clicks)
	{
		motor[RightFront] = speed;
		motor[RightBack] = speed;
		motor[LeftFront] = -speed;
		motor[LeftBack] = -speed;
	}
	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;


}












// Lets you know when 20 seconds is over, can help with setting up
// the initial timing and motor speed.
//task timeMe() {
//	wait1Msec(20000);
//	PlaySound(soundBeepBeep);
//	while(bSoundActive) EndTimeSlice();
//}

// Pulse a big "*" at the bottom of the screen to show that it's
// doing something.
task showPulse() {
	while (true) {
		nxtDisplayCenteredBigTextLine(6, " ");
		wait1Msec(400);
		nxtDisplayCenteredBigTextLine(6, "*");
		wait1Msec(400);
	}
}



// Start the calibration and complain loudly if something goes wrong
void startCalibration() {
	if (!HTMCstartCal(HTCOMPASS)) {
		eraseDisplay();
		nxtDisplayTextLine(1, "ERROR: Couldn't");
		nxtDisplayTextLine(2, "calibrate sensor.");
		nxtDisplayTextLine(4, "Check connection");
		nxtDisplayTextLine(5, "and try again.");
		PlaySound(soundException);
		while(bSoundActive) EndTimeSlice();
		wait1Msec(5000);
		StopAllTasks();
	}
}

// Stop the calibration and complain loudly if somethign goes wrong
void stopCalibration() {
	if (!HTMCstopCal(HTCOMPASS)) {
		eraseDisplay();
		nxtDisplayTextLine(1, "ERROR: Calibration");
		nxtDisplayTextLine(2, "has failed.");
		nxtDisplayTextLine(4, "Check connection");
		nxtDisplayTextLine(5, "and try again.");
		PlaySound(soundException);
		while(bSoundActive) EndTimeSlice();
		wait1Msec(5000);
		StopAllTasks();
		} else {
		nxtDisplayTextLine(1, "SUCCESS: ");
		nxtDisplayTextLine(2, "Calibr. done.");
		PlaySound(soundUpwardTones);
		while(bSoundActive) EndTimeSlice();
		wait1Msec(5000);
	}
}






task main()
{
	turnServos(2,lastservopos);
	wait1Msec(1000);

	for(int x=0; x<540;x++)
	{

		turnleft();
		wait1Msec(100);


	}



}