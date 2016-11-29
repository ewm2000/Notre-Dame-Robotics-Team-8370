#pragma config(Sensor, dgtl9,  backe,          sensorQuadEncoder)
#pragma config(Sensor, dgtl11, righte,         sensorQuadEncoder)
#pragma config(Motor,  port2,           back,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           right,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           front,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           left,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           crighttop,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clefttop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           crightbot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           cleftbot,      tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void pre_auton()
{

  bStopTasksBetweenModes = true;
}

task autonomous()
{

  AutonomousCodePlaceholderForTesting();
}

task usercontrol()
{
		while(True){
		/*Driving*/
		float SpeedDivisor = 2-vexRT[Btn6U];
		float ForwDrive = vexRT[Ch3]/SpeedDivisor;
		float SideDrive = vexRT[Ch4]/SpeedDivisor;
		motor[left] = ForwDrive;
		motor[right] = ForwDrive;
		motor[front] = SideDrive;
		motor[back] = SideDrive;

		/*Moving Arm*/

		float up = vexRT[Btn6D];
		float down = vexRT[Btn5D];

		motor[crighttop] = 127*(up-down);
		motor[crightbot] = 127*(up-down);
		motor[clefttop] = 127*(up-down);
		motor[cleftbot] = 127*(up-down);
	}

  while (true)
  {

    UserControlCodePlaceholderForTesting();
  }
}