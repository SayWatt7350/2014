

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
	int BRStraight = 103;
	int FLStraight = 119;
	int BLStraight = 159;

	int FRLeft = 107;
	int BRLeft = 71;
	int FLLeft = 83;
	int BLLeft = 99;

	int FRRight = 219;
	int BRRight = 140;
	int FLRight = 155;
	int BLRight = 241;

	int FRSide = 49;
	int BRSide = 177;
	int FLSide = 190;
	int BLSide = 42;
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
