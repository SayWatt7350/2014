#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  HTServo)
#pragma config(Sensor, S3,     eopd1,           sensorI2CCustom)
#pragma config(Sensor, S4,     eopd2,            sensorI2CCustom)
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

//swapped backRS and front RS
#include "hitechnic-irseeker-v2.h";//3rd party driver for the ir sensor
//#include "JoystickDriver.c"
#include "hitechnic-sensormux.h"
#include "hitechnic-compass.h"
#include "lego-touch.h"
//#include "swerve functions v2.h"
#include "hitechnic-eopd.h"


#define touch msensor_S4_2
#define HTIRS2 msensor_S4_4
#define colorport msensor_S4_1
//#define eopd msensor_S4_3


int eopdthreshold1=35;
int eopdthreshold2=35;
	int under=0;
	/*
	0 means nothing underneath
	1 means something new underneath
	2 means something has been underneath
	*/
int encoders=125;
int geteopdvalue();
task movemotordown();
task movemotorup();





task main()
{
	HTEOPDsetShortRange(eopd1);
	HTEOPDsetShortRange(eopd2);

StartTask(movemotordown);

wait1Msec(500);
StartTask(movemotordown);



	while(true)
	{

		//nxtDisplayCenteredTextLine(3, "eopd:%d", HTEOPDreadProcessed(eopd1));


		switch(geteopdvalue())
		{
	case 0:	nxtDisplayCenteredTextLine(4, "Nothing New");	StartTask(movemotordown); break;
	case 1:	nxtDisplayCenteredTextLine(4, "Something New"); StartTask(movemotorup); break;
	case 2:	nxtDisplayCenteredTextLine(4, "Something Old");	break;
	case 3: nxtDisplayCenteredTextLine(4, "Nothing Old");	break;
	}

	wait1Msec(400);

	}


}

int geteopdvalue()
{
nxtDisplayCenteredTextLine(1,"%d::%d::%d", HTEOPDreadProcessed(eopd1),HTEOPDreadProcessed(eopd2), under);
int reading1= HTEOPDreadProcessed(eopd1);
int reading2= HTEOPDreadProcessed(eopd2);
if(reading1>eopdthreshold1 && reading2>eopdthreshold2 && under!=3 && under!=0)
	{
		under=0;//nothing new
	}
	else if(reading1< eopdthreshold1 && reading2<eopdthreshold2 && (under==0 || under==3)&& under!=1 && under!=2)
	{
		under=1;//something new
	}
	else if(reading1< eopdthreshold1 && reading2<eopdthreshold2  && (under==1 || under==2))
	{
		under=2;//somthing old
	}
	else if(reading1> eopdthreshold1 && reading2>eopdthreshold2 &&(under==0 || under==3))
	{
		under=3;	//nothing old
	}

	return under;
}



task movemotorup()
{
	StopTask(movemotordown);
	nMotorEncoder[motorB]=0;

	while(nMotorEncoder[motorB]<encoders)
	{
		motor[motorB]=100;
	}
	motor[motorB]=0;


}

task movemotordown()
{
	StopTask(movemotorup);
	nMotorEncoder[motorB]=0;
	while(nMotorEncoder[motorB]>-encoders)
	{
		motor[motorB]=-100;
	}
	motor[motorB]=0;

}
