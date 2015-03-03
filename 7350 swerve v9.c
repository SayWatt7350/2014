<<<<<<< Updated upstream
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Motor,  mtr_S1_C1_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightBack,     tmotorTetrix, openLoop, reversed)
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
			sFRS = 161;
			sBRS = 131;
			sFLS = 132;
			sBLS = 159;
			break;

		case 2:							// spin
			sFRS = 107;				//   						\  	u
			sBRS = 167;				//  						/	 	u
			sFLS = 170;				//		/							u
			sBLS = 102;				//		\							u
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
			sFRS = 219;				//   						/
			sBRS = 167;				//  						/
			sFLS = 170;				//		/
			sBLS = 255;				//	 ??? /
			break;


		case 4:				// 45 degree turn to left ???
			sFRS = 107;				//   						\		u
			sBRS = 96;				//  						\		u
			sFLS = 100;				//		\							u
			sBLS = 102;				//	  \							u
			break;

		case 5:				// sideways ???
			sFRS = 49;				//   						->
			sBRS = 202;				//  						->
			sFLS = 255;				//		->
			sBLS = 43;				//	  ->
			break;


		default:			// gostraight

			sFRS = 161;
			sBRS = 154;
			sFLS = 132;
			sBLS = 95;
			break;
		}   // end of switch
/*
case 6:// 20 degree value between | and /
			sFRS = 188;
			sBRS = 151;
			sFLS = 191;
			sBLS = 154;
			break;
*/
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
	int threshold = 40;
	/*//removed for testing

	servo[Winch]=127;
	*/
	//
	//  going straight
	//
	int straight_FRS = 161;
	int straight_BRS = 131;
	int straight_FLS = 132;
	int straight_BLS = 134;



	//  mandible servo positions
	//
	int openwideR = 240;
	int openwideL = 0;
	int shutR = 0;
	int shutL = 228;
	//  mouth
	int mouthup=60;
	int mouthdown=214;
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
	int lockdown = 85;
	//
	int scoreopen = 5;
	int scoreclose = 245;

	int FRS =0;
	int BRS = 0;
	int FLS  = 0;
	int BLS = 0;

	int correction=0;//correction for left motor

	//    servo initialization
	servo[leftmandible] = openwideL;
	servo[rightmandible] = openwideR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	servo[gate] = gateup;
	//
	//  wheels  go straight to start
	//
	servo[frontRS]= straight_FRS;
	servo[backRS]= straight_BRS;
	servo[frontLS]= straight_FLS;
	servo[backLS]= straight_BLS;
	servo[mouth]= mouthup;
	int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side

	waitForStart();
	//turnServos(1, lastservopos);
	servo[gate] = gatedrive;

	waitForStart();


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
				FLS*=-1;
				// servos
				turnServos(5, lastservopos);  // turn wheels to right to go sideways
				lastservopos = 5;
				// motors

			} else if (abs(joystick.joy1_x2) > threshold) // spin
			{
				FRS = BRS = -(abs(joystick.joy1_x2)*40)/joystick.joy1_x2;  //  positive = go right, negative = go left.
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
		if(joy1Btn(8))
		{

			servo[rightmandible] = shutR;
			servo[leftmandible] = shutL;
		}
		if(joy1Btn(6))
		{
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
		}

		// Mouth controls

		if(joy1Btn(4))
		{
			servo[mouth]=mouthup;
			wait1Msec(30);

			servo[rightmandible] = openwideR;  // open mandibles so they don't hit elevator
			servo[leftmandible] = openwideL;
		}
		if(joy1Btn(2))
		{
			servo[mouth]=mouthdown;
		}

		/////////////    JOYSTICK 2 //////////////////

		//  elevator controls
		/*
		if(abs(joystick.joy2_y2) > threshold)// absolute value so can be negative or positive
		{
		motor[elevator] = 100*joystick.joy2_y2/abs(joystick.joy2_y2);//Raises the elevator
		}
		else
		{
		motor[elevator] = 0;
		}
		*/
		// scoring

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

		if (joy2Btn(3))		// lock on
		{
			servo[lock] = lockdown;
		}

		if (joy2Btn(1))     // lock up - release rolling goal
		{
			servo[lock] = lockup;
		}


	}
}
=======
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Motor,  mtr_S1_C1_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightBack,     tmotorTetrix, openLoop, reversed)
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
			sFRS = 161;
			sBRS = 154;
			sFLS = 132;
			sBLS = 131;
			break;

		case 2:							// spin
			sFRS = 107;				//   						\  	u
			sBRS = 187;				//  						/	 	u
			sFLS = 170;				//		/							u
			sBLS = 95;				//		\							u
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
			sFRS = 219;				//   						/
			sBRS = 187;				//  						/
			sFLS = 170;				//		/
			sBLS = 168;				//	 ??? /
			break;


		case 4:				// 45 degree turn to left ???
			sFRS = 107;				//   						\		u
			sBRS = 114;				//  						\		u
			sFLS = 100;				//		\							u
			sBLS = 95;				//	  \							u
			break;

		case 5:				// sideways ???
			sFRS = 49;				//   						->
			sBRS = 80;				//  						->
			sFLS = 255;				//		->
			sBLS = 56;				//	  ->
			break;

		default:			// gostraight

			sFRS = 161;
			sBRS = 154;
			sFLS = 132;
			sBLS = 95;
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
	int threshold = 40;
	/*//removed for testing

	servo[Winch]=127;
	*/
	//
	//  going straight
	//
	int straight_FRS = 161;
	int straight_BRS = 154;
	int straight_FLS = 132;
	int straight_BLS = 134;



	//  mandible servo positions
	//
	int openwideR = 240;
	int openwideL = 0;
	int shutR = 0;
	int shutL = 228;
	//  mouth
	int mouthup=60;
	int mouthdown=214;
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
	int lockdown = 85;
	//
	int scoreopen = 5;
	int scoreclose = 245;

	int FRS =0;
	int BRS = 0;
	int FLS  = 0;
	int BLS = 0;

	int correction=0;//correction for left motor

	//    servo initialization
	servo[leftmandible] = openwideL;
	servo[rightmandible] = openwideR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	servo[gate] = gateup;
	//
	//  wheels  go straight to start
	//
	servo[frontRS]= straight_FRS;
	servo[backRS]= straight_BRS;
	servo[frontLS]= straight_FLS;
	servo[backLS]= straight_BLS;
	servo[mouth]= mouthup;
	int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side

	waitForStart();
	//turnServos(1, lastservopos);
	servo[gate] = gatedrive;

	waitForStart();


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
				FLS*=-1;
				// servos
				turnServos(5, lastservopos);  // turn wheels to right to go sideways
				lastservopos = 5;
				// motors

			} else if (abs(joystick.joy1_x2) > threshold) // spin
			{
				FRS = BRS = -(abs(joystick.joy1_x2)*40)/joystick.joy1_x2;  //  positive = go right, negative = go left.
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
		if(joy1Btn(8))
		{

			servo[rightmandible] = shutR;
			servo[leftmandible] = shutL;
		}
		if(joy1Btn(6))
		{
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
		}

		// Mouth controls

		if(joy1Btn(4))
		{
			servo[mouth]=mouthup;
			wait1Msec(30);

			servo[rightmandible] = openwideR;  // open mandibles so they don't hit elevator
			servo[leftmandible] = openwideL;
		}
		if(joy1Btn(2))
		{
			servo[mouth]=mouthdown;
		}

		/////////////    JOYSTICK 2 //////////////////

		//  elevator controls
		/*
		if(abs(joystick.joy2_y2) > threshold)// absolute value so can be negative or positive
		{
		motor[elevator] = 100*joystick.joy2_y2/abs(joystick.joy2_y2);//Raises the elevator
		}
		else
		{
		motor[elevator] = 0;
		}
		*/
		// scoring

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

		if (joy2Btn(3))		// lock on
		{
			servo[lock] = lockdown;
		}

		if (joy2Btn(1))     // lock up - release rolling goal
		{
			servo[lock] = lockup;
		}


	}
}
=======
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
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

//constants
const int DEADZONE = 25;
const int MAX_MOTOR_VAL = 100;
const float MAX_JOY_VAL = 127.0;


//int scaleForMotor(int joyVal) //taken from l0jec's post on http://www.chiefdelphi.com/forums/archive/index.php/t-78636.html
//this is an exponential drive


/*
//check for deadzone
if(abs(joyVal) < DEADZONE) {
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
	if (lastpos != turnpos)    // Only execute if the new position is different than the old position. otherwise return.
	{
		//   straight defaults
		// define temporary variables servo default is straight.
		int sFRS = 90;
		int sBRS = 109;
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
			sFRS = 90;
			sBRS = 109;
			sFLS = 132;
			sBLS = 131;
			break;

		case 2:							// spin
			sFRS = 38;				//   						\  	u
			sBRS = 162;				//  						/	 	u
			sFLS = 170;				//		/							u
			sBLS = 95;				//		\							u
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
			sFRS = 149;				//   						/
			sBRS = 162;				//  						/
			sFLS = 170;				//		/
			sBLS = 168;				//	 ??? /
			break;


		case 4:				// 45 degree turn to left ???
			sFRS = 38;				//   						\		u
			sBRS = 47;				//  						\		u
			sFLS = 100;				//		\							u
			sBLS = 95;				//	  \							u
			break;

		case 5:				// sideways ???
			sFRS = 202;				//   						->
			sBRS = 218;				//  						->
			sFLS = 255;				//		->
			sBLS = 56;				//	  ->
			break;

		default:			// gostraight

			sFRS = 90;
			sBRS = 109;
			sFLS = 132;
			sBLS = 95;
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
int threshold = 40;
	/*//removed for testing

	servo[Winch]=127;
	*/
	//
	//  going straight
	//
	int straight_FRS = 136;
	int straight_BRS = 146;
	int straight_FLS = 132;
	int straight_BLS = 134;



	//  mandible servo positions
	//
	int openwideR = 240;
	int openwideL = 0;
	int shutR = 0;
	int shutL = 228;
	//  mouth
	int mouthup=60;
	int mouthdown=214;
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
	int lockdown = 85;
	//
	int scoreopen = 5;
	int scoreclose = 245;

	int FRS =0;
	int BRS = 0;
	int FLS  = 0;
	int BLS = 0;
	//    servo initialization
	servo[leftmandible] = openwideL;
	servo[rightmandible] = openwideR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	servo[gate] = gateup;
	//
	//  wheels  go straight to start
	//
	servo[frontRS]= straight_FRS;
	servo[backRS]= straight_BRS;
	servo[frontLS]= straight_FLS;
	servo[backLS]= straight_BLS;
	servo[mouth]= mouthup;
	int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side

	waitForStart();
//turnServos(1, lastservopos);
servo[gate] = gatedrive;

	waitForStart();


	while(true)
	{
		getJoystickSettings(joystick); //Constantly updates values on the joystick
		//  left joystick

		if((abs(joystick.joy1_y1) > threshold)|| (abs(joystick.joy1_x1) > threshold) || (abs(joystick.joy1_x2) > threshold))
		{
			if ((abs(joystick.joy1_y1) > threshold) && (abs (joystick.joy1_x1) > threshold))   // going 45 degrees
			{
				BRS = FRS = BLS = FLS = (abs(joystick.joy1_y1) * 100)/joystick.joy1_y1;  // TAKE POWER AND DIRECTION from Y axis
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
				BRS = FRS = FLS = BLS = (abs(joystick.joy1_y1)*100)/joystick.joy1_y1;

				// servos
				turnServos(1, lastservopos);
				lastservopos = 1;
				// motors

			} else if ((abs(joystick.joy1_x1) > threshold) &&  (abs(joystick.joy1_y1) <= threshold)) // go sideways
			{
				BRS = FRS = BLS = FLS = (abs(joystick.joy1_x1)*100)/joystick.joy1_x1;  //  positive = go right, negative = go left.
				BLS*=-1;
				// servos
				turnServos(5, lastservopos);  // turn wheels to right to go sideways
				lastservopos = 5;
				// motors

			} else if (abs(joystick.joy1_x2) > threshold) // spin
			{
				FRS = BRS = -(abs(joystick.joy1_x2)*100)/joystick.joy1_x2;  //  positive = go right, negative = go left.
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
		if(joy1Btn(8))
		{

			servo[rightmandible] = shutR;
			servo[leftmandible] = shutL;
		}
		if(joy1Btn(6))
		{
			servo[rightmandible] = openwideR;
			servo[leftmandible] = openwideL;
		}

		// Mouth controls

		if(joy1Btn(4))
		{
		servo[mouth]=mouthup;
		wait1Msec(30);

		servo[rightmandible] = openwideR;  // open mandibles so they don't hit elevator
		servo[leftmandible] = openwideL;
		}
		if(joy1Btn(2))
		{
		servo[mouth]=mouthdown;
		}

		/////////////    JOYSTICK 2 //////////////////

		//  elevator controls
/*
		if(abs(joystick.joy2_y2) > threshold)// absolute value so can be negative or positive
		{
		motor[elevator] = 100*joystick.joy2_y2/abs(joystick.joy2_y2);//Raises the elevator
		}
		else
		{
		motor[elevator] = 0;
		}
	*/
		// scoring

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
			servo[gate] = gateup;

		}

		if (joy2Btn(3))		// lock on
		{
			servo[lock] = lockdown;
		}

		if (joy2Btn(1))     // lock up - release rolling goal
		{
			servo[lock] = lockup;
		}


	}
}
>>>>>>> Stashed changes
>>>>>>> Stashed changes
