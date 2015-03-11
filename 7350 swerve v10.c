#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S3,     compass,         sensorI2CCustom)
#pragma config(Sensor, S4,     Mux,            sensorI2CCustom9V)
#pragma config(Motor,  mtr_S1_C1_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightBack,     tmotorTetrix, openLoop,)
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


#include "hitechnic-irseeker-v2.h";//3rd party driver for the ir sensor
#include "joystickdriver.c"
#include "hitechnic-sensormux.h"    //Use the path where you put Xander's drivers
#include "hitechnic-compass.h"
#include "lego-touch.h"
//#include "swerve functions.c"

const tMUXSensor HTIRS2 = msensor_S4_4;
const tMUXSensor touch = msensor_S4_2;





//constants
const int DEADZONE = 40;
const int MAX_MOTOR_VAL = 100;
const float MAX_JOY_VAL = 127.0;


/*int scaleForMotor(int joyVal) //taken from l0jec's post on http://www.chiefdelphi.com/forums/archive/index.php/t-78636.html
//this is an exponential drive
{
//check for deadzone
if(abs(joyVal) < DEADZONE)
{
return 0;
}

//calculate scaled value
int sign = joyVal / abs(joyVal); // 1 or -1
float ratio = ((joyVal * joyVal) / (MAX_JOY_VAL * MAX_JOY_VAL));
int scaledVal = (sign * MAX_MOTOR_VAL) * ratio;

return scaledVal;
}
*/

#include "JoystickDriver.c"

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

		int FRStraight = 161;
		int BRStraight = 132;
		int FLStraight = 110;
		int BLStraight = 159;

		int FRLeft = 107;
		int BRLeft = 100;
		int FLLeft = 76;
		int BLLeft = 99;

		int FRRight = 219;
		int BRRight = 167;
		int FLRight = 144;
		int BLRight = 241;

		int FRSide = 49;
		int BRSide = 203;
		int FLSide = 179;
		int BLSide = 42;
/*
	servoChangeRate[RightFront]=1;
	servoChangeRate[LeftFront]=1;
	servoChangeRate[LeftBack]=1;
	servoChangeRate[RightBack]=1;
*/

	if (lastpos != turnpos)    // Only execute if the new position is different than the old position. otherwise return.
	{
		//   straight defaults
		// define temporary variables servo default is straight.
		int sFRS = 161;
		int sBRS = 154;
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


		switch (turnpos)
		{
		case 1:							// gostraight
			sFRS = FRStraight;
			sBRS = BRStraight;
			sFLS = FLStraight;
			sBLS = BLStraight;
			break;

		case 2:							// spin
			sFRS = FRLeft;				//   						\  	u
			sBRS = BRRight;				//  						/	 	u
			sFLS = FLRight;				//		/							u
			sBLS = BLLeft;				//		\							u
			// set motors direction to help servos and turn same direction as servo.
			if (lastpos == 1)  // straight to spin
			{
				mFRS = mBLS = -30;
				mFLS = mBLS = 30;
			} else if (lastpos == 5)  // sideways to spin
			{
				mFRS = mBLS = 30;
				mFLS = mBLS = -30;
			}

			break;

		case 3:				// 45 degree turn to right  ???
			sFRS = FRRight;				//   						/
			sBRS = BRRight;				//  						/
			sFLS = FLRight;				//		/
			sBLS = BLRight;				//	 ??? /
			break;


		case 4:				// 45 degree turn to left ???
			sFRS = FRLeft;				//   						\		u
			sBRS = BRLeft;				//  						\		u
			sFLS = FLLeft;				//		\							u
			sBLS = BLLeft;				//	  \							u
			break;

		case 5:				// sideways ???
			sFRS = FRSide;				//   						->
			sBRS = BRSide;				//  						->
			sFLS = FLSide;				//		->
			sBLS = BLSide;				//	  ->
			break;

		default:			// gostraight

			sFRS = FRStraight;
			sBRS = BRStraight;
			sFLS = FLStraight;
			sBLS = BLStraight;
			break;
		}   // end of switch

		// turn motor to help servo turn or leave it stopped
		motor[RightFront] = mFRS;
		motor[LeftFront] = mFLS;
		motor[RightBack] = mBRS;
		motor[LeftBack] = mBLS;

		//
		//  now turn servos
		//
		servo[frontRS]= sFRS;
		servo[backRS]= sBRS;
		servo[frontLS]= sFLS;
		servo[backLS]= sBLS;
		wait1Msec(150);		// only do this if changing servo pos.   if same as last time, then skip.

		//
		// Now, stop motors.  Will be restarted in new direction.
		//
		motor[RightFront] = 0;
		motor[LeftFront] = 0;
		motor[RightBack] = 0;
		motor[LeftBack] = 0;
	}

	lastpos = turnpos;
	return;
}



task main()
{
	//disableDiagnosticsDisplay();
	int threshold = 40;
	/*//removed for testing

	servo[Winch]=127;
	*/
	//
	//  going straight
	//
	int straight_FRS = 161;
	int straight_BRS = 131;
	int straight_FLS = 110;
	int straight_BLS = 134;



	//  mandible servo positions
	//
	int openwideR = 0;
	int openwideL = 255;
	int shutR = 220;
	int shutL = 0;
	int outL=150;
	int outR=80;
	//  mouth
	int mouthup=60;
	int mouthdown=214;
	int mouthjiggle=74;
	//
	int elevatorposition=0;
	int uppositionscore=62;
	int downpositionscore= 5;
	// gate
	int gateup = 5;
	int gatedrive = 50;
	int gatedown = 202;
	//
	int lockup = 0;
	int lockdown = 112;
	//
	int scoreopen = 5;
	int scoreclose = 245;

	int FRS =0;
	int BRS = 0;
	int FLS  = 0;
	int BLS = 0;

	int correction=0;//correction for left motor

	//    servo initialization
	servo[leftmandible] = outL;
	servo[rightmandible] = outR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	//servo[gate] = gateup;
	//
	//  wheels  go straight to start
	//
	servo[frontRS]= straight_FRS;
	servo[backRS]= straight_BRS;
	servo[frontLS]= straight_FLS;
	servo[backLS]= straight_BLS;
	//servo[mouth]= mouthup;
	servo[mouth]= mouthdown;
	int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side

	waitForStart();
	//turnServos(1, lastservopos);
	//servo[gate] = gatedrive;




	while(true)
	{
		getJoystickSettings(joystick); //Constantly updates values on the joystick
		//  left joystick

		if((abs(joystick.joy1_y1) > threshold)|| (abs(joystick.joy1_x1) > threshold) || (abs(joystick.joy1_x2) > threshold))
		{
			if ((abs(joystick.joy1_y1) > threshold) && (abs (joystick.joy1_x1) > threshold))   // going 45 degrees
			{
				BRS = FRS = BLS = FLS = -(abs(joystick.joy1_y1) * 90)/joystick.joy1_y1;  // TAKE POWER AND DIRECTION from Y axis
				if (((joystick.joy1_y1 * joystick.joy1_x1)) > 0)			// if both positive or both negative go to right
				{
					turnServos(3, lastservopos);  // turn wheels to right to go 45 degrees
					lastservopos = 3;

				} else
				{
					turnServos(4, lastservopos);  // turn wheels to left to go 45 degrees
					lastservopos = 4;
				}
			} else if (((abs(joystick.joy1_y1) > threshold)) &&(abs(joystick.joy1_x1) <= threshold))  // go straight

			// if going forward or back
			{
				BRS = FRS = FLS = BLS = (abs(joystick.joy1_y1)*90)/joystick.joy1_y1;

				// servos
				turnServos(1, lastservopos);
				lastservopos = 1;
				// motors

			} else if ((abs(joystick.joy1_x1) > threshold) &&  (abs(joystick.joy1_y1) <= threshold)) // go sideways
			{
				BRS = FRS = BLS = FLS = (abs(joystick.joy1_x1)*100)/joystick.joy1_x1;  //  positive = go right, negative = go left.
				BRS=FLS=-FRS;
				// servos
				turnServos(5, lastservopos);  // turn wheels to right to go sideways
				lastservopos = 5;
				// motors

			} else if (abs(joystick.joy1_x2) > threshold) // spin
			{
				BRS=FRS = -(abs(joystick.joy1_x2)*40)/joystick.joy1_x2;  //  positive = go right, negative = go left.
				BLS = FLS = -FRS;   // have to switch direction to make it spin.
				// servos
				turnServos(2, lastservopos);  // turn wheels to right to go sideways
				lastservopos = 2;
			}
		}else
		{
			BRS = FRS = BLS = FLS = 0;
		}

		// Now tell motors to go
		motor[RightFront] = FRS;
		motor[LeftFront] = FLS;
		motor[RightBack] = BRS;
		motor[LeftBack] = BLS;

		// Mandible controls
		if(joy1Btn(8))//left one needs to close first
		{
			servo[leftmandible] = shutL;
			wait1Msec(100);
			servo[rightmandible] = shutR;

		}
		if(joy1Btn(6))//right one needs to open first
		{
			servo[rightmandible] = openwideR;
			wait1Msec(100);
			servo[leftmandible] = openwideL;
		}

		// Mouth controls

		if(joy1Btn(4))
		{
			servoChangeRate[mouth] = 10;
			servo[mouth]=mouthup;
			wait1Msec(30);

			servo[rightmandible] = outR;  // open mandibles so they don't hit elevator
			servo[leftmandible] = outL;
		}
		if(joy1Btn(2))
		{
			servoChangeRate[mouth] = 30;
			servo[mouth]=mouthdown;
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
		}

//jiggle the mouth
				if(joy1Btn(3))
		{
			servo[rightmandible] = outR;  // open mandibles so they don't hit elevator
			servo[leftmandible] = outL;

			servoChangeRate[mouth] = 1;
			servo[mouth]=mouthjiggle;
			wait1Msec(300);
			servo[mouth]=mouthup;
			wait1Msec(300);
			servoChangeRate[mouth] = 10;
		}


		/////////////    JOYSTICK 2 //////////////////

		//  elevator controls

		if((joystick.joy2_y2) > threshold )
		{
			servo[mouth]=mouthdown;
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
			motor[elevator1]= 90;//Raises the elevator
			motor[elevator2]= 90;
		}

		// lower elevator

		else if((joystick.joy2_y2) < -threshold && TSreadState(((tMUXSensor)touch))==0)
		{
			servo[mouth]=mouthdown;
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
			motor[elevator1]= -90;
			motor[elevator2]= -90;
		}
		else
		{
			motor[elevator1]=0;
			motor[elevator2]=0;
		}

		//scoring
		if(joy2Btn(8))
		{

			servo[score] = scoreopen;
		}
		else
		{
			servo[score]=scoreclose;
		}

		// rolling goal

		if(joy2Btn(2))   // gate down to capture rolling goal
		{

			servo[gate] = gatedown;
		}

		if (joy2Btn(4))		// gate up
		{
			servo[lock] = lockup;
			wait1Msec(5);
			servo[gate] = gatedrive;

		}


		//lock

		if (joy2Btn(3))		// lock on
		{
			servo[lock] = lockdown;
			servo[gate] = gatedown;
		}

		if (joy2Btn(1))     // lock up - release rolling goal
		{
			servo[lock] = lockup;
		}



	}
}