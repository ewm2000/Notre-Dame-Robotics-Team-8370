#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightShootA,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightShootB,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftShootA,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftShootB,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           belt,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RampA,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RampB,         tmotorVex393_HBridge, openLoop)
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
	wait1Msec(2000);

	clearTimer(T1);

	if (time1[T1] < 500)
	{
		motor[rightDrive] = 63;
		motor[leftDrive] = 63;
	} else if (time1[T1] < 1000) {
		motor[rightDrive] = 63;
		motor[leftDrive] = -63;
	} else {
		motor[rightDrive] = 0;
		motor[leftDrive] = 0;

		motor[rightShootA] = -127;
		motor[rightShootB] = -127;
		motor[leftShootA] = 127;
		motor[leftShootA] = 127;
		motor[belt] = 127;
	}

	AutonomousCodePlaceholderForTesting();
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
			motor(rightShootB) = -127;
			motor(leftShootB) = 127;
			motor(rightShootA) = -127;
			motor(leftShootA) = 127;
		}
		while (vexRT[Btn5D] == 1)
		{
			motor(rightShootB) = 0;
			motor(leftShootB) = -0;
			motor(rightShootA) = 0;
			motor(leftShootA) = 0;
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
			motor(belt) = 0;
		}
		/*
		* Ramp
		*/
		while (vexRT[Btn7R] == 1)
		{
			motor(RampA) = 63;
			wait1Msec(6000);

		}
		while (vexRT[Btn7L] == 1)
		{
			motor(RampA) = 0;
		}

		UserControlCodePlaceholderForTesting();
		}
}
