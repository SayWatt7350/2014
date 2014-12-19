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

task main()
{
	int speed=50;

	motor[Right]=50;
	motor[Left]=50;
	wait10Msec(500);//go forward 5 seconds to get off the ramp

	while(SensorRaw[irsensor]==5);
	{
		motor[right]=speed;
		motor[left]=speed;
	}

	while(SensorRaw[irsensor]<5);
	{
		motor[right]=speed;
		motor[left]=-speed;
	}

		while(SensorRaw[irsensor]==5);
	{
		motor[right]=-speed;
		motor[left]=speed;
	}


	//THIS CODE DOES NOT WORK DO NOT USE
	//FOR REFERENCE ONLY
	//ClearTimer(T1);
	//while (time1[T1] <10000)//TEMPORARY --find a way to measure ir signal strength so when signal is high enough, we exit the loop
	//{
	//	if(SensorValue(irsensor)==0)//creates rules for each zone of the ir sensor
	//	{
	//		nxtDisplayTextLine(1,"0");
	//		motor[Left]=speed;
	//		motor[Right]=-speed;
	//	}

	//	if(SensorValue(irsensor)==1)
	//	{
	//		nxtDisplayTextLine(1,"1");
	//		motor[Left]=speed-40;
	//		motor[Right]=speed+40;
	//	}
	//	if(SensorValue(irsensor)==2)
	//	{
	//		nxtDisplayTextLine(1,"2");
	//		motor[Left]=speed-30;
	//		motor[Right]=speed+30;
	//	}
	//	if(SensorValue(irsensor)==3)
	//	{
	//		nxtDisplayTextLine(1,"3");
	//		motor[Left]=speed-20;
	//		motor[Right]=speed+20;
	//	}
	//	if(SensorValue(irsensor)==4)
	//	{
	//		nxtDisplayTextLine(1,"4");
	//		motor[Left]=speed-10;
	//		motor[Right]=speed+10;
	//	}
	//	if(SensorValue(irsensor)==5)
	//	{
	//		nxtDisplayTextLine(1,"5");
	//		motor[Left]=speed;
	//		motor[Right]=speed;
	//	}
	//	if(SensorValue(irsensor)==6)
	//	{
	//		nxtDisplayTextLine(1,"6");
	//		motor[Left]=speed+10;
	//		motor[Right]=speed-10;
	//	}
	//	if(SensorValue(irsensor)==7)
	//	{
	//		nxtDisplayTextLine(1,"7");
	//		motor[Left]=speed+20;
	//		motor[Right]=speed-20;
	//	}
	//	if(SensorValue(irsensor)==8)
	//	{
	//		nxtDisplayTextLine(1,"8");
	//		motor[Left]=speed+30;
	//		motor[Right]=speed-30;
	//	}
	//	if(SensorValue(irsensor)==9)
	//	{
	//		nxtDisplayTextLine(1,"9");
	//		motor[Left]=speed+40;
	//		motor[Right]=speed-40;
	//	}
	//}







	/*

	//the conveyer belt------------------------------------------
	if(joy1Btn(7))
	{
	//  sPIN sLOW
	motor[spinner] = 30;
	//wait1Msec(50);
	}
	else if(joy1Btn(5))
	{
	motor[spinner] = 100;
	}
	else
	{
	motor[spinner] = 0;
	}



	//Everything with servo[toppiece] is for the dinosaur head
	if(joy1Btn(4))
	{
	servo[toppiece] = 215;
	}

	if(joy1Btn(2))
	{
	servo[toppiece] = 0;
	}


	//Sweeper
	if(joy1Btn(6))
	{
	motor[sweeper]=-100;
	}
	else if(joy1Btn(8))
	{
	motor[sweeper]=100;
	}
	}
	*/
}
