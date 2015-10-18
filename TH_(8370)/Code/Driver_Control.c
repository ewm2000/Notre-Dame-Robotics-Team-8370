#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightThread,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftThread,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightShoot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftShoot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          Intake,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// main task
task main() {

	while(true) {

		int LSy = vexRT[Ch3]; // Between -127 and 127 before divided
		int LSx = vexRT[Ch4]; // ^

		/*
		* DRIVE
		*/
		motor[leftDrive] = LSy + LSx; // Left Motor
		motor[rightDrive] = LSy - LSx; // Right Motor

		}
}