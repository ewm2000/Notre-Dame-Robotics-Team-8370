#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           ramp,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           belt,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightShoot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftShoot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           robotLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  {
  	motor(leftDrive) = 127;
  motor(rightDrive) = 127;
  wait1Msec(5000);
	}
	 wait1Msec(5000);
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.


		int LSy = vexRT[Ch3]; // Between -127 and 127 before divided
		int RSy = vexRT[Ch2]; // ^

		/*
		* DRIVE
		*/
		motor[leftDrive] = LSy; // Left Motor
		motor[rightDrive] = RSy; // Right Motor

		/*
		* Shoot
		*/
		while (vexRT[Btn5U] == 1)
		{
			motor(rightShoot) = 127;
			motor(leftShoot) = -127;
		}

		/*
		* Belt
		*/
		while (vexRT[Btn6U] == 1)
		{
			motor(belt) = 127;
		}
		while (vexRT[Btn6D] == 1)
		{
			motor(belt) = -127;
		}
		/*
		* Ramp
		*/
		while (vexRT[Btn7R] == 1)
		{
			motor(ramp) = 127;
		}
		while (vexRT[Btn7L] == 1)
		{
			motor(ramp) = -127;
		}

		UserControlCodePlaceholderForTesting();
		}
}
