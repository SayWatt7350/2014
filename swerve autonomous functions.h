
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
	while(nMotorEncoder[RightBack] < (clicks+207))
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

void getcenterposramp()//returns center piece position when robot is on top of ramp
{

	int acS1, acS2, acS3, acS4, acS5;//irsensor values
	int irthreshold=58.5;//to decide if position 3 or something else
	int irthreshold2=10;//to decide if position 2 or 1

	//HTIRS2readAllDCStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5);
	//HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5);//used to get ir sensor values

	if(acS4>irthreshold)//finding position of centerpiece
	{
		centerpos=3;
	}
	else if(acS4>irthreshold2)
	{
		centerpos=2;
	}
	else
	{
		centerpos=1;
	}


}

/*
acS1, acS2, acS3, acS4, acS5;//irsensor values
0			0			0			44		0			position 1
0			0			32		29		0			position 2
0			0			0			25		0			position 3



*/



void getcenterpospark()//returns center piece position when robot is in parking zone
{

	int acS1, acS2, acS3, acS4, acS5;//irsensor values
	int irthreshold1=16;//to decide if position 3 or something else
	int irthreshold2=34.5;//to decide if position 2 or 1


	HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5);//used to get ir sensor values

	if(acS3>irthreshold1)//finding position of centerpiece
	{
		centerpos=2;
	}
	else if(acS4>irthreshold2)
	{
		centerpos=1;
	}
	else
	{
		centerpos=3;
	}


}

int finished=0;
int distance=0;
//void moveelevmotor(int distance)
task moveelevator()
{
	int speed=100*distance/abs(distance);//forward or backward
	float clicks=/*1440*PI**/distance;

	nMotorEncoder[elevator1] = 0;
	nMotorEncoder[elevator2] = 0;

	writeDebugStream("1:%d  2:%d\nClicks:%d\n",nMotorEncoder[elevator1], nMotorEncoder[elevator2], clicks);
	//writeDebugStream("Clicks:%d\n",clicks);
	if((float)abs(nMotorEncoder[elevator1]) < abs(clicks))
	{
		writeDebugStream("WORKING");
	}
	clearDebugStream();
	while((float)abs(nMotorEncoder[elevator1]) < abs(clicks) && (float)abs(nMotorEncoder[elevator2]) < abs(clicks))
	{
		writeDebugStream("MOVING\n");
		writeDebugStream("1:%d  2:%d\nClicks:%d\n",nMotorEncoder[elevator1], nMotorEncoder[elevator2], clicks);

		motor[elevator1]= 90;//Raises the elevator
		motor[elevator2]= 90;
	}
	motor[elevator1] = 0;
	motor[elevator2] = 0;

	finished=1;
}
/*
13751
12280

14047
13095

13673
13475

6666666666666666666666666666666666666666666666666666666666666666
13823.666666666666666666666666667
12950

13386.83333333335


*/




int newelevpos=0;
//void changeelevator(int newelevpos)//VALUES HAVE NOT BEEN TESTED
task changeelevator()
{//DO NOT USE UNTIL CORRECT VALUES ARE INPUTTED
	if(newelevpos==lastelevator)
	{
		return;
	}else if(lastelevator==30 && newelevpos==60)
	{
		distance=100;
		StartTask(moveelevator);
		//moveelevmotor(100);
	}else if(lastelevator==30 && newelevpos==90)
	{
		distance=200;
		StartTask(moveelevator);
		//moveelevmotor(200);
	}else if(lastelevator==30 && newelevpos==120)
	{
		distance=300;
		StartTask(moveelevator);
		//moveelevmotor(300);
	}else if(lastelevator==60 && newelevpos==30)
	{
		distance=-100;
		StartTask(moveelevator);
		//moveelevmotor(-100);
	}else if(lastelevator==60 && newelevpos==90)
	{
		distance=100;
		StartTask(moveelevator);
		//moveelevmotor(100);
	}else if(lastelevator==60 && newelevpos==120)
	{
		distance=200;
		StartTask(moveelevator);
		//moveelevmotor(200);
	}else if(lastelevator==90 && newelevpos==30)
	{
		distance=-200;
		StartTask(moveelevator);
		//moveelevmotor(-200);
	}else if(lastelevator==90 && newelevpos==60)
	{
		distance=-100;
		StartTask(moveelevator);
		//moveelevmotor(-100);
	}else if(lastelevator==90 && newelevpos==120)
	{
		distance=100;
		StartTask(moveelevator);
		//moveelevmotor(100);
	}else if(lastelevator==120 && newelevpos==90)
	{
		distance=-100;
		StartTask(moveelevator);
		//moveelevmotor(-100);
	}else if(lastelevator==120 && newelevpos==60)
	{
		distance=-200;
		StartTask(moveelevator);
		//moveelevmotor(-200);
	}else if(lastelevator==120 && newelevpos==30)
	{
		distance=-300;
		StartTask(moveelevator);
		//moveelevmotor(-300);
	}

	lastelevator=newelevpos;

	return;

}



task movefrom0to120()
{
	distance=13200;
	servo[mouth]=mouthdown;
	wait1Msec(100);
	StartTask(moveelevator);

	while(!finished);
	servo[score]=scoreopen;
	wait1Msec(500);

}









void compassturn(int degrees)//positive degrees means left
{															//negative degrees means right
	int speed= 70*(degrees/abs(degrees));

	turnServos(2,0);//forces servos to turn
	if(degrees<0)
	{
		degrees+=360;
	}
	//writeDebugStream("degrees:%d\n",degrees);

	//HTMCsetTarget(compass, degrees);

	HTMCsetTarget(compass);
	HTMCsetTarget(compass,0);
	writeDebugStream("compass:%d\n",HTMCreadHeading(compass));

	int clicks=1440*3*PI/720*degrees;

	clearDebugStream();

	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	HTMCsetTarget(compass,0);
	HTMCsetTarget(compass,0);
	HTMCsetTarget(compass,0);
	//int wantedheading=HTMCreadHeading(compass)+degrees;
	int wantedheading=HTMCreadRelativeHeading(compass);//returns value between -179 to 180
	if(wantedheading<0)
	{
wantedheading-=360;
}

if(wantedheading<360)
	{
wantedheading+=360;
}

clearDebugStream();

	writeDebugStream("compass:%d\n",(HTMCreadHeading(compass)));

	HTMCsetTarget(compass,0);
	while(//abs(nMotorEncoder[RightBack]) < abs(clicks)
		//&& abs(nMotorEncoder[LeftFront]) < abs(clicks)
	/*&&*/ HTMCreadRelativeHeading(compass)!=0)//while difference between current heading and wanted heading is greater than 0
	{

		writeDebugStream("compass:%d\n",HTMCreadRelativeHeading(compass));
		motor[RightFront] = speed;
		motor[RightBack] = speed;
		motor[LeftFront] = -speed;
		motor[LeftBack] = -speed;
	}

	//if(abs(nMotorEncoder[RightBack]) < abs(clicks) || abs(nMotorEncoder[LeftFront]) < abs(clicks))
	{
		//writeDebugStream("\nEXITED BECAUSE OF ENCODER\n");
	}



	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;

}

void compassstraight(int direction, int distance)
{

	int speed= 50*(distance/abs(distance));
	int offset=50;
	turnServos(direction,0);//forces servos to turn
	wait1Msec(100);


	int clicks=1440*3*PI*distance/128;

	for(int x=0; x<100; x++)//need to reset compass several times or else it doesn't work
	{
		HTMCsetTarget(compass,0);
	}

	int current=HTMCreadHeading(compass);
	int compassthreshold=current+180;
	//int lower=middle-180;

	if(compassthreshold>360)
	{
compassthreshold-=360;
}




	nMotorEncoder[RightBack] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftBack] = 0;
	nMotorEncoder[LeftFront] = 0;
	if(distance>0)
	{
		//abs so can be positive and negative
		while(abs(nMotorEncoder[RightBack]) < abs(clicks)	&& abs(nMotorEncoder[LeftFront]) < abs(clicks))//while difference between current heading and wanted heading is greater than 0
		{
			nxtDisplayCenteredTextLine(2,"%d, %d",HTMCreadHeading(compass), current);
			if(HTMCreadHeading(compass)>current)
			{
				writeDebugStream("Left side faster\n");



				motor[RightFront] = speed;
				motor[RightBack] = speed;
				motor[LeftFront] = (speed+offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[LeftBack] = (speed+offset);//drive side faster at the rate of the difference between current and wanted compass degree
			}	else if(HTMCreadHeading(compass)<current)
			{
				writeDebugStream("Right side faster\n");



				motor[RightFront] = (speed+offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[RightBack] = (speed+offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[LeftFront] = speed;
				motor[LeftBack] = speed;
			}else if(HTMCreadHeading(compass)==current)
			{
				writeDebugStream("both sides equal\n");
				motor[RightFront] = speed;
				motor[RightBack] = speed;
				motor[LeftFront] = speed;
				motor[LeftBack] = speed;
			}
		}
	}
	else
	{
		//abs so can be positive and negative
		while(abs(nMotorEncoder[RightBack]) < abs(clicks)	&& abs(nMotorEncoder[LeftFront]) < abs(clicks))//while difference between current heading and wanted heading is greater than 0
		{
			if(HTMCreadHeading(compass)>180)
			{

				motor[RightFront] = (speed-offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[RightBack] = (speed-offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[LeftFront] = speed;
				motor[LeftBack] = speed;

			}	else if(HTMCreadHeading(compass)<180)
			{
				motor[RightFront] = speed;
				motor[RightBack] = speed;
				motor[LeftFront] = (speed-offset);//drive side faster at the rate of the difference between current and wanted compass degree
				motor[LeftBack] = (speed-offset);//drive side faster at the rate of the difference between current and wanted compass degree

			}else if(HTMCreadHeading(compass)==180)
			{
				writeDebugStream("both sides equal\n");
				motor[RightFront] = speed;
				motor[RightBack] = speed;
				motor[LeftFront] = speed;
				motor[LeftBack] = speed;
			}
		}


	}

	motor[RightFront] = 0;
	motor[RightBack] = 0;
	motor[LeftFront] = 0;
	motor[LeftBack] = 0;

}
