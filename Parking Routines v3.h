void program1()
{

	godirection(1,63);//get of ramp
	//turnServos(4,0);//forces servos to turn
	//wait1Msec(1000);
	//godirection(4,40);
	turnleft45();
	godirection(1,40);
	//turnleft90();
	//turnleft90();
	turnleft45();
	turnleft90();
	servo[gate]=gatedown;
	wait1Msec(1000);
	godirection(1,-27);
	servo[lock]=lockdown;
	wait1Msec(100);
	godirection(1,2);
	servo[lock] = lockup;
	wait1Msec(100);
	godirection(1,-3);
	servo[lock] = lockdown;
	wait1Msec(100);
	godirection(1,48);
	//	turnServos(3,0);
	godirection(3,70);


	turnleft90();
	turnleft45();
	turnServos(1,0);
}



void program2()
{
	turnServos(1,0);//forces servos to turn
	godirection(5,25);
	godirection(1,75);
	turnleft90();
	turnleft90();
	servo[gate]=gatedown;
	godirection(1,-45);
	servo[lock]=lockdown;

	godirection(1,70);

	turnright90();
	turnright45();

	godirection(1,-15);

}



//void program3()
//{
//	clearDebugStream();
//	getcenterpospark();
//	//	centerpos=1;//for testing

//	if(centerpos==1)
//	{//if the goal is right in front of robot

//		writeDebugStream("POSITION 1");

//		//gostraight(4,27);//45 degrees to the left
//		//compassturn(180);

//		servo[gate]=gatedrive;
//		compassstraight(1,-12);
//		/*
//		StartTask(movefrom0to120);
//		while(!finished);
//		*/
//	}
//	else if(centerpos==2)
//	{//if the goal is at a 45 degree angle
//		writeDebugStream("POSITION 2");

//		godirection(4,32);

//		turnleft45();
//		turnleft90();


//		godirection(1,-36);

//		/*
//		compassstraight(1,12);
//		compassturn(45);
//		compassstraight(5,24);

//		newelevpos=120;
//		//		StartTask(changeelevator);
//		//changeelevator(120);//move elevator to 120 inches
//		servo[score]=scoreopen;//release score gate
//		*/
//	}
//	else if(centerpos==3)
//	{
//		writeDebugStream("POSITION 3");
//		godirection(4,55);//left diagonal to be on side of pole
//		turnleft90();//turn to be in front of pole
//		godirection(1,-30);//backward to hit pole

//		turnleft45();


//		/*newelevpos=120;
//		StartTask(changeelevator);
//		//changeelevator(120);//move elevator to 120 inches
//		servo[score]=scoreopen;//release score gate
//		*/
//	}

//}




void program9()//knocks dowgetickstand from parking
{
	godirection(1,14);
	getcenterpospark();
//	StartTask(movefrom0to120);
//	centerpos=4; //Testing Ultrasound
//	nxtDisplayCenteredTextLine(2,"Parking");

	if(centerpos==1)
	{
		writeDebugStreamLine("Position 1");

		godirection(1,12);
		turnGYRO(90,90);
		turnGYRO(90,90);
		wait1Msec(100);
		godirection(5,9);
		wait1Msec(100);
		godirection(1,-8);
//		lineupcenter();
//    while (!finished)
//			}
//				Elevator Raise Check
//			{
//
		wait1Msec(1000);
		godirection(5,-10);
		godirection(1,-25);
		godirection(1,25);
		godirection(1,-25);

	}
	else if(centerpos==2)
	{
		writeDebugStreamLine("Position 2");

		godirection(1,12);
		turnGYRO(45,90);
		godirection(1,15);
		turnGYRO(90,90);
		godirection(1,-8);
//		lineupcenter();
//    while (!finished)
//			}
//				Elevator Raise Check
//			{
//
		wait1Msec(1000);
		godirection(5,-8);
		godirection(1,-25);
		godirection(1,25);
		godirection(1,-25);

	}
	else if(centerpos==3)
	{
		writeDebugStreamLine("Position 3");

		godirection(1,12);
		turnGYRO(50,90);
		godirection(1,50);
		turnGYRO(40,90);
		godirection(1,-8);
//		lineupcenter();
//    while (!finished)
//			}
//				Elevator Raise Check
//			{
//
		wait1Msec(1000);
		godirection(5,-8);
		godirection(1,-25);
		godirection(1,25);
		godirection(1,-25);

	}
	else if (centerpos==4)//Not Possible unless set at beginning of Function
	{
		lineupcenter();
	}
}

void program10()
{
	disableDiagnosticsDisplay(); //For Testing Purposes
	getcenterpospark();
	if(centerpos == 3)
	{
		nxtDisplayCenteredBigTextLine(2, "Position 3"); //Checks Position - Temp for testing
		godirection(1,54);
		turnServos(5,0);
		wait1Msec(500);
		godirection(5,-24);
		turnServos(1,0);
		wait1Msec(200);
		godirection(1,28);
		turnleft90();
//		StartTask(movefrom0to120);
//		while (!finished)
//		{
//			writeDebugStreamLine("Im Doing Something... Please Try Again Later"); //Checks if task is in progress
//		}
		turnServos(1,0);
		godirection(1,1);
		godirection(1,-1);
		turnServos(5,0);
		wait1Msec(500);
		godirection(5,12);
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,24);
		godirection(1,-24);
	}
	else if(centerpos == 2)
	{
		nxtDisplayCenteredBigTextLine(2, "Position 2"); //Checks Position - Temp for testing
		godirection(1,24);
		turnleft90();
		turnleft45();
		godirection(1,-10);
//		StartTask(movefrom0to120);
//		while (!finished)
//		{
//			writeDebugStreamLine("Im Doing Something... Please Try Again Later"); //Testing
//		}
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,1);
		godirection(1,-1);
		turnServos(5,0);
		wait1Msec(500);
		godirection(5,12);
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,24);
		godirection(1,-24);
	}
	else if(centerpos ==3)
	{
		nxtDisplayCenteredBigTextLine(2,"Position 1"); //Checks Position - Temp for testing
		godirection(1,24);
		turnServos(5,0);
		wait1Msec(500);
		godirection(5,12);
		turnleft90();
		turnleft90();
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,5);
		StartTask(movefrom0to120);
		while (!finished)
//		{
//			writeDebugStreamLine("Im Doing Something");
//			writeDebugStreamLine("Im Doing Something"); //Checks if Task is done - Temp for testing
//		}
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,1);
		godirection(1,-1);
		turnServos(5,0);
		wait1Msec(500);
		godirection(5,12);
		turnServos(1,0);
		wait1Msec(500);
		godirection(1,24);
		godirection(1,-24);
	}
}


/*void program11()
{

compassstraight(1,63);//get of ramp
//turnServos(4,0);//forces servos to turn
compassstraight(4,40);

compassturn(90);//turn 90 to left
compassturn(90);

servo[gate]=gatedown;
wait1Msec(1000);
compassstraight(1,-27);
servo[lock]=lockdown;
wait1Msec(100);
compassstraight(1,2);
servo[lock] = lockup;
wait1Msec(100);
compassstraight(1,-3);
servo[lock] = lockdown;
wait1Msec(300);
servo[score] = scoreopen;
wait1Msec(1000);

//compassstraight(1,48);
//	turnServos(3,0);
//compassstraight(3,70);
compassstraight(1,105);

compassturn(90);
compassturn(45);
turnServos(1,0);

}
*/
void program12()
{
	turnServos(1,0);//forces servos to turn
	godirection(5,25);
	godirection(1,75);
	turnleft90();
	turnleft90();
	servo[gate]=gatedown;
	godirection(1,-45);
	servo[lock]=lockdown;

	godirection(1,70);

	turnright90();
	turnright45();

	godirection(1,-15);

}


void program15()
{
	turnServos(1,0);//forces servos to turn
	godirection(1,72);//forward 6 feet

}


void program21()
{

	godirection(1,-63);//get of ramp
	turnServos(4,0);//forces servos to turn
	wait1Msec(1000);
	godirection(4,-40);
	servo[gate]=gatedown;
	wait1Msec(1000);
	godirection(1,-27);
	servo[lock]=lockdown;
	wait1Msec(100);
	godirection(1,2);
	servo[lock] = lockup;
	wait1Msec(100);
	godirection(1,-3);
	servo[lock] = lockdown;
	wait1Msec(100);
	godirection(1,48);
	//	turnServos(3,0);
	godirection(3,70);


	turnleft90();
	turnleft45();
	turnServos(1,0);
}


void program25()
{
	turnServos(1,0);//forces servos to turn
	godirection(1,72);//forward 6 feet
	turnGYRO(60, 40);
	godirection(1,100);
}




void program31()
{

	godirection(1,-63);//get of ramp


	turnGYRO(45, 60);

	turnServos(1,0);
	wait1Msec(100);
	godirection(1,-38);

	turnServos(2,0);
	turnGYRO(-43, 40);


	servo[gate]=gatedown;
	wait1Msec(1000);
	godirection(1,-28);
	/*	//if the rolling goal is in a certain position,
	//then we can't get it by going straight
	//so we have to hit the wall at a diagonal, return to the original position
	//and hit the wall straight another time again
	//then we will have it regardless of whatever position it is in
	godirection(1, 10);
	turnGYRO(-45, 40);
	godirection(1, -14);//10*sqrt(2)
	wait1Msec(50);//let the robot settle
	godirection(1, -14);
	turnGYRO(45, 40);
	godirection(1, -10);//now we have the rolling goal
	*/
	//while(true);
	servo[lock]=lockdown;
	wait1Msec(100);
	godirection(1,2);
	servo[lock] = lockup;
	wait1Msec(100);
	godirection(1,-3);
	servo[lock] = lockdown;
	wait1Msec(100);
	godirection(1,48);
	//	turnServos(3,0);
	godirection(3,70);


	turnleft90();
	turnleft45();
	turnServos(1,0);

}
	void program22()
	{
		turnServos(5,0);
		godirection(5,24);
		turnServos(1,0);
		wait1Msec(1000);
		godirection(5,24*5);
		turnServos(5,0);
		godirection(5,-24);
		//	writeDebugStream("Done");
	}
