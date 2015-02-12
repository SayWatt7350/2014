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

#include "hitechnic-irseeker-v2.h";//3rd party driver for the ir sensor
#include "joystickdriver.c"




const int COLOR_COUNT = 15;//the amount of colors we have
int speed = 50;//default motor speed
int fullspeed = 100;//motor speed variables



int sFRS = 90;//servo values
int sBRS = 109;
int sFLS = 132;
int sBLS = 131;

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
int gatedrive = 90;
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

int lastservopos = 0;   // 1 = straight, 2 = spin , 3 = turn 45 deg to right, 4 = turn 45degrees to left, 5 = turn wheels to side





unsigned long thediff=0;//the difference between two values given to the function "difference"
int colorTags[][] = {
	{254, 257, 138},//red
	{387, 390, 262},//light orange
	{331, 332, 170},//dark orange
	{346, 347, 298},//tan
	{217, 217, 172},//brown
	{390, 392, 345},//light yellow
	{374, 377, 311},//dark yellow
	{306, 310, 348},//light green
	{147, 158, 181},//dark green
	{194, 193, 265},//light blue
	{157, 161, 162},//dark blue
	{251, 248, 165},//purple
	{393, 396, 377},//white
	{375, 375, 177},//pink
	{79, 78, 80}//black
};

string colornames[15]={//declaration of all the names
	"Red",
	"Light Orange",
	"Dark Orange",
	"Tan",
	"Brown",
	"Light Yellow",
	"Dark Yellow",
	"Light Green",
	"Dark Green",
	"Light blue",
	"Dark blue",
	"Purple",
	"White",
	"Pink",
	"Black",
};







/*
void turnleft45();
void turnright45();
void turnleft90();
void turnright90();
void difference(long r1, long g1, long b1, long r2, long g2, long b2);
void turnServos(int turnpos, int lastpos);
void godirection(int direction, int distance);
void program15();
*/








/*
Difference engine applies the difference formula onto two sets of RGB values
and returns the integer difference for comparison. Theory difference is
SQRT(Sum(distances squared))
*/

void difference(long r1, long g1, long b1, long r2, long g2, long b2)
{
	long r = r1 - r2;//differences between database value and the scanned value
	long g = g1 - g2;
	long b = b1 - b2;

	thediff =sqrt(r^2+g^2+b^2);
}



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
	wait1Msec(1000);//for debug
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

void turnright45()//turn 45 degrees right
{

	turnServos(2,lastservopos);
	int speed=50;
	int clicks=1440*3*PI/16;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(nMotorEncoder[RightBack] < clicks && nMotorEncoder[LeftFront] > -clicks)
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

void turnright90()//turn 90 degrees right
{
	turnServos(2,lastservopos);

	int speed=50;
	int clicks=1440*3*PI/8;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(nMotorEncoder[RightBack] < clicks && nMotorEncoder[LeftFront] < clicks)
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




void turnleft45()//turn 45 degrees left
{
	turnServos(2,lastservopos);

	int speed=50;
	int clicks=1440*3*PI/16;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(nMotorEncoder[RightBack] < clicks && nMotorEncoder[LeftFront] < clicks)
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

void turnleft90()//turn 90 degrees left
{

	turnServos(2,lastservopos);


	int speed=50;
	int clicks=1440*3*PI/8;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(nMotorEncoder[RightBack] < clicks && nMotorEncoder[LeftFront] < clicks)
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

void gostraight(int distance)
{
	turnServos(1,lastservopos);


	int speed=50*distance/abs(distance);//forward or backward
	int clicks=1440*3*PI*distance/128;

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	while(abs(nMotorEncoder[RightBack]) < abs(clicks) && abs(nMotorEncoder[LeftFront]) < abs(clicks))
	{
		motor[RightFront] = speed;
		motor[RightBack] = speed;
		motor[LeftFront] = speed;
		motor[LeftBack] = speed;
	}
	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;




}


void godirection(int direction, int distance)
{

int speed=90*distance/abs(distance);

	int clicks=1440*3*PI*distance/128;

	turnServos(direction, 0);//forces servos to change



	nMotorEncoder[RightFront] = 0;

	while(abs(nMotorEncoder[RightFront]) < abs(clicks))
	{
		motor[RightFront] = speed;
		motor[RightBack] = speed;
		motor[LeftFront] = speed;
		motor[LeftBack] = speed;
		wait1Msec(25);
	}
	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;

}



void program15()
{



	godirection(1,72);//get of ramp
	turnServos(4,0);//forces servos to turn
	godirection(4,36);
	turnleft90();
	turnleft90();
servo[gate]=gatedown;
wait1Msec(1000);
	godirection(1,-22);
	servo[lock]=lockdown;
	wait1Msec(100);
	godirection(1,96);

	turnleft90();
	turnleft90();
godirection(1,0);
}



task main()
{

	//waitForStart();
	/*
	list of programs

	starting		|what to
	position		|do
	______________________________
	1		ramp		|knock down poles
	2		parking	|knock down poles
	3						|
	4						|
	5						|
	6						|
	7						|
	8						|
	10					|
	11					|
	12					|
	13					|
	14					|
	15	anywhere|go straight 5 seconds
	*/
	wait1Msec(2000);
	disableDiagnosticsDisplay();
	short colorValues[4];//these are the scanned values

	int j;
	long r;
	long g;
	long b;
	//	wait1Msec(500);

	int minDifference = 32767; // MAX_INT
	int selectedColor = 0;//this is the color closest to the scanned color
	servo[gate]=gateup;


	// gostraight
	sFRS = 90;
	sBRS = 109;
	sFLS = 132;
	sBLS = 131;

	servo[frontRS]= sFRS;
	servo[backRS]= sBRS;
	servo[frontLS]= sFLS;
	servo[backLS]= sBLS;
	wait1Msec(500);


	servo[leftmandible] = openwideL;
	servo[rightmandible] = openwideR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	servo[gate] = gateup;
	servo[mouth]= mouthup;

godirection(1,0);
wait1Msec(1000);


	/*
	while(true)
	{
	for(j =0; j<4; j++)//get color sensor values
	{
	getColorSensorData(colorPort, 0, &colorValues[j]);
	r = colorValues[0];
	g = colorValues[1];
	b = colorValues[2];
	}


	for(int i = 0; i < COLOR_COUNT; i++)//here we find the closest color in our database
	{

	difference(//passing in the database values and the scanned values to find the difference
	colorTags[i][0],
	colorTags[i][1],
	colorTags[i][2],
	r, g, b);
	long diff = thediff;

	if (diff <= minDifference) {//if the difference between the color in the database that we are currently checking and the scanned color
	minDifference = diff;			//is less than the smallest difference between the other database colors, then the database color we are
	selectedColor = i;				//currently checking is the closest match so far
	}

	nxtDisplayCenteredTextLine(0, "%d, %d", diff, minDifference);//print all the values
	nxtDisplayCenteredTextLine(1, "%d,%d,%d", colorValues[0], colorValues[1], colorValues[2]);
	nxtDisplayCenteredTextLine(4, "%d,%d,%d,",	colorTags[i][0], colorTags[i][1], colorTags[i][2]);
	}

	nxtDisplayCenteredTextLine(2, "%s", colornames[selectedColor]);
	nxtDisplayCenteredTextLine(3, "Is this the color?");
	if(nNxtButtonPressed==2)
	{
	break;
	}
	}

	waitForStart();*/
	servo[gate]=gatedrive;

	/*
	switch(selectedColor)
	{
	case 1:
	//		program1();
	break;
	case 2:
	//	program2();
	break;
	/*case 3:
	break;
	case 4:
	break;
	case 5:
	break;
	case 6:
	break;
	case 7:
	break;
	case 8:
	break;
	case 9:
	break;
	case 10:
	break;
	case 11:
	break;
	case 12:
	break;
	case 13:
	break;
	case 14:
	break;*//*
	case 15:
	program15();
	break;
	default:
	program15();
	break;
	}



	*/
	program15();
}
