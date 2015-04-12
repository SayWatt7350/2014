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
	int BRStraight = 68;
	int FLStraight = 158;
	int BLStraight = 189;

	int FRLeft = 107;
	int BRLeft = 20;   // not quite
	int FLLeft = 100;
	int BLLeft = 113;

	int FRRight = 219;
	int BRRight = 147;
	int FLRight = 209;
	int BLRight = 220;// not quite

	int FRSide = 49;
	int BRSide = 255;
	int FLSide = 41;
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
