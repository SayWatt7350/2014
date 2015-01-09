#pragma config(Hubs, S1, HTMotor, HTServo, none, none)
#pragma config(Hubs, S2, HTMotor, HTServo, none, none)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Sensor, S2, , sensorI2CMuxController)
#pragma config(Motor, mtr_S1_C1_1, RightFront, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S1_C1_2, RightBack, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S2_C1_1, LeftFront, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S2_C1_2, LeftBack, tmotorTetrix, openLoop)
#pragma config(Servo, srvo_S1_C2_1, frontRS, tServoStandard)
#pragma config(Servo, srvo_S1_C2_2, backRS, tServoStandard)
#pragma config(Servo, srvo_S1_C2_3, Winch, tServoStandard)
#pragma config(Servo, srvo_S1_C2_4, servo4, tServoNone)
#pragma config(Servo, srvo_S1_C2_5, servo5, tServoNone)
#pragma config(Servo, srvo_S1_C2_6, servo6, tServoStandard)
#pragma config(Servo, srvo_S2_C2_1, frontLS, tServoStandard)
#pragma config(Servo, srvo_S2_C2_2, backLS, tServoStandard)
#pragma config(Servo, srvo_S2_C2_3, servo9, tServoNone)
#pragma config(Servo, srvo_S2_C2_4, servo10, tServoNone)
#pragma config(Servo, srvo_S2_C2_5, servo11, tServoNone)
#pragma config(Servo, srvo_S2_C2_6, servo12, tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard !!*//
#include "JoystickDriver.c"
task main()
{
  int threshold = 20;
  servo[frontRS]= 59;
  servo[backRS]= 81;
  servo[frontLS]= 122;
  servo[backLS]= 118;
  servo[Winch]=127;
  servoChangeRate[Winch]=5;
  servoChangeRate[backRS]=5;
  waitForStart();
  while(true)
  {
    getJoystickSettings(joystick); //Constantly updates values on the joystick
    //Right Wheel
    if(abs(joystick.joy1_y2) > threshold)
    {
      motor[RightFront] = joystick.joy1_y2;
      motor[RightBack] = joystick.joy1_y2;
    }
    else
    {
      motor[RightFront] = 0;
      motor[RightBack] = 0;
    }
    //Left wheel
    if (abs(joystick.joy1_y1) > threshold)
    {
      motor[LeftFront] = joystick.joy1_y1;
      motor[LeftBack] = joystick.joy1_y1;
    }
    else
    {
      motor[LeftFront] = 0;
      motor[LeftBack] =0;
    }
    // ram command
    /* if(joy1Btn(5))
    {
    // sPIN FAST
    motor[spinner] = 100;
    //wait1Msec(50);
    }
    else
    {
    motor[spinner] = 0;
    }
    */
    if(joy1Btn(2))
    {
      // sPIN sLOW
      servo[Winch] = -255;
      //servo[backRS]=100;
      //motor[spinner] = 60;
      wait1Msec(500);
    }
    /*else if(joy1Btn(3))
    {
    // sPIN sLOW
    servo[Winch] = 150;
    //motor[spinner] = 60;
    wait1Msec(500);
    }*/
    else
    {
      servo[Winch] = 255;
      //motor[spinner] = 60;
      wait1Msec(500);
      // motor[spinner] = 0;
    }
  }
}
