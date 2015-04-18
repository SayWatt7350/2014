#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S3,     GYRO,         sensorI2CCustom)
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

#define touch msensor_S4_2
#define HTIRS2 msensor_S4_4
#define eopd1 msensor_S4_3
#define ultrasound msensor_S4_1
#define eopd2 msensor_S4_1
#define USING_2_EOPD 1
#define NUMBER_OF_PROGRAMS 31



#include "hitechnic-sensormux.h" //THIS MUST BE THE FIRST #INCLUDE
#include "hitechnic-irseeker-v2.h"//3rd party driver for the ir sensor
#include "joystickdriver.c"
#include "hitechnic-compass.h"
#include "hitechnic-colour-v2.h"
#include "hitechnic-gyro.h"
#include "hitechnic-eopd.h"
#include "lego-ultrasound.h"
#include "..\..\autonomous variables.h"
#include "..\..\swerve functions v2.h"
#include "..\..\swerve autonomous functions.h"
//#include "..\..\Autonomous Routines v3.h"
#include "..\..\Parking Routines v3.h"
//.. means go up a directory
//these are in the github directory
//default driver location is c:\~~github directory~~\2014\rdpartyrobotcdr-3.3.1\drivers
//programs are located in c:\~~github directory~~\2014
//so we have to go up 2 directories to get to \2014 from \rdpartyrobotcdr-3.3.1\drivers




//----------------------------------------------------------------------------START TASK MAIN---------------------------------------------
task main()
{
	//	clearDebugStream();
	//waitForStart();
	/*
	list of programs

	starting		|what to
	position		|do
	______________________________
	1		ramp		|drop ball in small goal and move to parking
	2		parking	|drop ball in small goal and move to parking//values not tested
	3		parking	|score in center goal
	4			      |
	5						|
	6						|
	7						|
	8						|
	9		parking	|knocks down kickstand & scores in mid w/ IR
	10	ramp		|scores in mid and knocks kickstand(With IR)
	11	ramp		|drop ball in small goal and move to parking(with compass)
	12	parking	|drop ball in small goal and move to parking//values not tested
	13					|
	14					|
	15	anywhere|go straight 6 feet (can get of ramp)
	21	ramp		|drop ball in small goal and move to parking (BACKWARDS)
	*/

	//	disableDiagnosticsDisplay();
	/*
	short colorValues[4];//these are the scanned values

	int j;
	long r;
	long g;
	long b;
	//	wait1Msec(500);
	*/
	int minDifference = 32767; // MAX_INT
	int selectedColor = 0;//this is the color closest to the scanned color
	servo[gate]=gateup;


	// gostraight

	sFRS = 161;
	sBRS = 154;
	sFLS = 132;
	sBLS = 131;

	servo[frontRS]= sFRS;
	servo[backRS]= sBRS;
	servo[frontLS]= sFLS;
	servo[backLS]= sBLS;
	wait1Msec(500);

//Test to see if ultrasound exists
/*
	ClearTimer(T3);
		while (true)
			{
				if (time1[T3] < 10000) && (ultrasound < 25)
					{
						PlaySound(soundBeepBeep);
						ultrasoundexists = 1;
					}
				else if (time1[T3] >= 10000)
					{
						ultrasoundexists = 0;
					{
			}


*/


	//servo[leftmandible] = outL;
	//servo[rightmandible] = outR;
	//	servo[mouth] = mouthup;
	servo[score] = scoreclose;
	servo[lock] = lockup;
	servo[gate] = gateup;
	servo[mouth]= mouthup;
	//selectedColor=HTCS2readColor(colorport);

	turnServos(1,0);



	/*clearDebugStream();
	//while(true)
	{
	if(!HTCS2readRGB(colorport, r, g,b))
	{
	writeDebugStream("BAD\n");
	}
	writeDebugStream("%d, %d, %d\n", r,g,b);
	//writeDebugStream("----------------\n");
	wait1Msec(1000);
	}

	*/
	//	wait1Msec(4000);
	/*
	3|lightblue//program1
	3|darkblue
	5|darkyellow
	7|pink
	7|red//program3
	7|orange
	13|lightgreen
	14|white//program11
	14|tan
	14|brown
	14|lightyellow
	17|purple
	17|black//default(program15)


	*/

	/*	while(true)
	{
	for(j =0; j<4; j++)//get color sensor values
	{
	//	x=HTCS2readRGB(colorport, r, g,b);
	//getColorSensorData(colorport, 0, &colorValues[j]);
	r = colorValues[0];
	g = colorValues[1];
	b = colorValues[2];
	//	writeDebugStream("R:%d,G:%d,B:%d\n",r,g,b);
	//writeDebugStream("color:%d\n",HTCS2readColor(colorport));


	}
	}*//*
	for(int x=0; x<10; x++)//test values a couple of times to make sure we have the right one
	{
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
	}
	nxtDisplayCenteredTextLine(2, "%s", colornames[selectedColor]);
	nxtDisplayCenteredTextLine(3, "Is this the color?");
	if(nNxtButtonPressed==2)
	{
	break;
	}
	}
	*/


	//	disableDiagnosticsDisplay();
	//	eraseDisplay();

	switch(selectedColor)
	{
	case 1:
	case 7:
		nxtDisplayCenteredTextLine(1,"RED");
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
		nxtDisplayCenteredTextLine(1,"WHITE");
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:nxtDisplayCenteredTextLine(1,"BLACK");
		break;
	default:
		nxtDisplayCenteredTextLine(1,"BLACK");
		break;
	}


	turnServos(1,0);


	//wait1Msec(5000);
	PlaySound(soundBeepBeep);
	PlaySound(soundBeepBeep);

	//		waitForStart();
	servo[gate]=gatedrive;



	/*

	switch(selectedColor)
	{
	case 1:
	break;
	case 2:
	break;
	case 3:
	program1();
	break;
	case 4:
	break;
	case 5:
	break;
	case 6:
	break;
	case 7:
	writeDebugStream("7");
	program3();
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
	program11();
	break;
	case 15:
	break;
	case 16:
	break;
	program15();
	break;
	default:
	program15();
	break;
	*/

	//program1();

	//turnleft90();
	//compassturn(180);
	//compassturn(180);
	//while(true);
	//program1();
	//turnServos(2,0);
	//wait1Msec(5000);
	program9();





}
