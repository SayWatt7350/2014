void program1()
{

	godirection(1,63);//get of ramp

	////turnServos(4,0);//forces servos to turn
	////wait1Msec(1000);
	////godirection(4,42);
	////godirection(5,6);
	turnleft45();

	godirection(1,38);

	turnleft45();

	turnleft90();
	////turnleft90();
//	while(true){/*do nothing*/}
	servo[gate]=gatedown;
	turnServos(1,0);
	wait1Msec(1000);
	godirection(1,-30);
	servo[lock]=lockdown;
	wait1Msec(100);
	godirection(1,2);
	servo[lock] = lockup;
	wait1Msec(100);
	godirection(1,-3);
	servo[lock] = lockdown;
	wait1Msec(100);

	servo[mouth]=mouthdown;


	distance=2000;
	starttask(moveelevator);

	wait1Msec(3000);
	servo[score]=scoreopen;

	wait1Msec(1000);

	godirection(1,96);
	godirection(1, 12);
	//	turnServos(3,0);
	//godirection(3,70);


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



void program3()
{
	clearDebugStream();
	getcenterpospark();
	//	centerpos=1;//for testing

	if(centerpos==1)
	{//if the goal is right in front of robot

		writeDebugStream("POSITION 1");

		compassstraight(4,27);//45 degrees to the left
		compassturn(180);

		servo[gate]=gatedrive;
		compassstraight(1,-12);
		/*
		StartTask(movefrom0to120);
		while(!finished);
		*/
	}
	else if(centerpos==2)
	{//if the goal is at a 45 degree angle
		writeDebugStream("POSITION 2");

		godirection(4,32);

		turnleft45();
		turnleft90();


		godirection(1,-36);

		/*
		compassstraight(1,12);
		compassturn(45);
		compassstraight(5,24);

		newelevpos=120;
		//		StartTask(changeelevator);
		//changeelevator(120);//move elevator to 120 inches
		servo[score]=scoreopen;//release score gate
		*/
	}
	else if(centerpos==3)
	{
		writeDebugStream("POSITION 3");
		godirection(4,55);//left diagonal to be on side of pole
		turnleft90();//turn to be in front of pole
		godirection(1,-30);//backward to hit pole

		turnleft45();


		/*newelevpos=120;
		StartTask(changeelevator);
		//changeelevator(120);//move elevator to 120 inches
		servo[score]=scoreopen;//release score gate
		*/
	}

}




void program5()//messes up oponent's rolling goals
{

	//turnright();
	godirection(1,-60);//go sideways to interfere with 30cmrolling goals
	godirection(4,48);//diagonal to interfere with 60cm rolling goal
	godirection(4,-48);//return to original position
	godirection(5,-120);//return to original position




}




void program7()
{
	clearDebugStream();
	getcenterpospark();
	//	centerpos=1;//for testing

	if(centerpos==1)
	{//if the goal is right in front of robot

		writeDebugStream("POSITION 1");

		godirection(3,6);
		godirection(1,60);


		for(int x=0; x<3; x++)
		{
			godirection(1,12);
			godirection(1,-12);
		}


	}



else if(centerpos==2)
{//if the goal is at a 45 degree angle
	writeDebugStream("POSITION 2");


	godirection(3,12);
	godirection(1,60);

turnleft45();


	for(int x=0; x<3; x++)
	{
		godirection(1,12);
		godirection(1,-12);
	}


}
else if(centerpos==3)
{
	writeDebugStream("POSITION 3");
	godirection(3,6);//45 degrees to the right
	godirection(1,60);//knock down pole

	turnleft90();



	for(int x=0; x<3; x++)
	{
		godirection(1,12);
		godirection(1,-12);
	}

}

}









void program11()
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


void program16()
{

wait1Msec(20000);//20 seconds

turnServos(1,0);//forces servos to turn
godirection(1,72);//forward 6 feet
//godirection(1,-72);//forward 6 feet

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
