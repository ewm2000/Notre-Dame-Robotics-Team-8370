#pragma config(Motor,  port1,           R1,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           R2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           L1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           L2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           M,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
while (true)
{
	//forwardbackward drive
	motor[R1]=vexRT[Ch2];
	motor[R2]=vexRT[Ch2];
	motor[L2]=vexRT[Ch2];
	motor[L2]=vexRT[Ch2];
	//leftright drive
	motor[M]=vexRT[Ch1];
	//turn
	motor[R1]=vexRT[Ch4];
	motor[R2]=vexRT[Ch4];
	motor[L2]=vexRT[Ch4];
	motor[L2]=-1*vexRT[Ch4];

}


}
