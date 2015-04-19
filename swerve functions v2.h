int eopdthreshold1=10;
int eopdthreshold2=10;
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


//  Team 7350 - swerve code
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
	int BRStraight = 53;
	int FLStraight = 172;
	int BLStraight = 189;

	int FRLeft = 107;
	int BRLeft = 20;   // not quite
	int FLLeft = 109;
	int BLLeft = 113;

	int FRRight = 219;
	int BRRight = 133;
	int FLRight = 255;
	int BLRight = 220;// not quite

	int FRSide = 49;
	int BRSide = 211;
	int FLSide = 52;
	int BLSide = 23;
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
		int sBRS = 68;
		int sFLS = 158;
		int sBLS = 189;

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
		wait1Msec(250);		// only do this if changing servo pos.   if same as last time, then skip.

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





int geteopdvalue()
{
	//nxtDisplayCenteredTextLine(2,"%d::%d::%d::%d", HTEOPDreadProcessed(eopd1),HTEOPDreadProcessed(eopd2), under,USING_2_EOPD);
	int reading1= HTEOPDreadProcessed(eopd1);
	int reading2= 0;
	if(USING_2_EOPD)
	{
		reading2= HTEOPDreadProcessed(eopd2);
	}



	if(USING_2_EOPD==1)
	{
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
	}

	if(USING_2_EOPD==0)
	{
		if(reading1>eopdthreshold1 && under!=3 && under!=0)
		{
			under=0;//nothing new
		}
		else if(reading1< eopdthreshold1 && (under==0 || under==3)&& under!=1 && under!=2)
		{
			under=1;//something new
		}
		else if(reading1< eopdthreshold1 && (under==1 || under==2))
		{
			under=2;//somthing old
		}
		else if(reading1> eopdthreshold1 &&(under==0 || under==3))
		{
			under=3;	//nothing old
		}
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
