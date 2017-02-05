#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  newcube,        sensorDigitalIn)
#pragma config(Sensor, dgtl2,  oldcube,        sensorDigitalIn)
#pragma config(Sensor, dgtl3,  skills,         sensorDigitalIn)
#pragma config(Sensor, dgtl6,  leftEncoder,    sensorNone)
#pragma config(Sensor, dgtl8,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl10, armEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl12, armTouch,       sensorTouch)
#pragma config(Sensor, I2C_1,  rightClaw,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftClaw,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           rightClaw,     tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port5,           leftClaw,      tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_2)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)
// Select Download method as "competition"
#pragma competitionControl(Competition)
//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void stop_all(int time){	// stops all
	motor[armLeft] = 0;
	motor[armLeft2] = 0;
	motor[armRight] = 0;
	motor[armRight2] = 0;
	motor[backRight]= 0;
	motor[backLeft]= 0;
	motor[frontRight]= 0;
	motor[frontLeft]= 0;

	wait1Msec(time);
	}
void cube_shoot(){
	while(SensorValue[armTouch] != 1){
		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
	}

	}
void back_shoot(){	// drives back and shoots
	//drive backward for
	motor[backRight]=-127;
	motor[backLeft]=-127;
	motor[frontRight]=-127;
	motor[frontLeft]=-127;
	wait1Msec(800);
	// start arm
	while(SensorValue[armTouch] != 1){
		// arm portion
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
		// drive portion
		motor[backRight]=-127;
		motor[backLeft]=-127;
		motor[frontRight]=-127;
		motor[frontLeft]=-127;
}
	}
void left_turn(float ticks){ // moves left laterally (red)
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder] < ticks || SensorValue[leftEncoder] > -ticks){
					if(SensorValue[rightEncoder] < ticks){ //forward shaft rotation
 							if (SensorValue[rightEncoder]/ticks <.8){
 								motor[backRight]=127;
								motor[frontRight]=127;
							}
							else{
								motor[backRight]=90;
								motor[frontRight]=90;
							}
 					}
					else
					{
 					 			motor[backRight]=0;
								motor[frontRight]=0;
					}
					if(SensorValue[leftEncoder] > -ticks){ //reversed shaft rotation
 						if (SensorValue[leftEncoder]/ticks >-.8){
 								motor[backLeft]=-127;
 								motor[frontLeft]=-127;
 							}
 						else{
 							motor[backLeft]=-90;
 							motor[frontLeft]=-90;
 							}
					}
					else{
 						motor[backLeft]=0;
 						motor[frontLeft]=0;
					}
}

	}
void right_turn(float ticks){ // moves right laterally (blue)
SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[leftEncoder] < ticks || SensorValue[rightEncoder] > -ticks){
					if(SensorValue[leftEncoder] < ticks){ //forward shaft rotation
 								if (SensorValue[leftEncoder]/ticks < .8){
										motor[backLeft]=127;
										motor[frontLeft]=127;
									}
								else{
										motor[backLeft]=90;
										motor[frontLeft]=90;
									}
 					}
					else
					{
 					 			motor[backLeft]=0;
								motor[frontLeft]=0;
					}
					if(SensorValue[rightEncoder] > -ticks){ //reversed shaft rotation
 						if (SensorValue[rightEncoder]/ticks > -.8){
							motor[backRight]=-127;
 							motor[frontRight]=-127;
 						}
 						else{
 							motor[backRight]=-90;
 							motor[frontRight]=-90;}
						}
					else{
 						motor[backRight]=0;
 						motor[frontRight]=0;
					}
}
	}
void arm_down(int deg){	// moves arm down
	while (SensorValue[armEncoder] > deg){
		motor[armLeft] = -127;
		motor[armLeft2] = -127; //L -70, R 50 cube1
		motor[armRight] = 127;
		motor[armRight2] = 127;
	}
	}
void pause(int time){	// delay at beginning
	motor[armLeft] = 0;
	motor[armLeft2] = 0;
	motor[armRight] = 0;
	motor[armRight2] = 0;
	motor[backRight]= 0;
	motor[backLeft]= 0;
	motor[frontRight]= 0;
	motor[frontLeft]= 0;
	wait1Msec(time);
	}

void drive_forward(float inches){ // drives forward
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	float ticks = inches * 28.6478898;
	while (SensorValue[rightEncoder]<ticks){

		if (SensorValue[rightEncoder]==SensorValue[leftEncoder]){
				if (SensorValue[rightEncoder]/ticks <.8)
				{motor[backRight]=127;
					motor[backLeft]=127;
					motor[frontRight]=127;
					motor[frontLeft]=127;
				}
				else{
				{motor[backRight]=60;
					motor[backLeft]=60;
					motor[frontRight]=60;
					motor[frontLeft]=60;
				}
		}
		if (SensorValue[rightEncoder] <SensorValue[leftEncoder]){
					motor[backRight]=127;
					motor[backLeft]=110;
					motor[frontRight]=127;
					motor[frontLeft]=110;
		}
		if (SensorValue[rightEncoder] >SensorValue[leftEncoder]){
					motor[backRight]=110;
					motor[backLeft]=127;
					motor[frontRight]=110;
					motor[frontLeft]=127;
		}
		}
			//motor[backRight]=-63;
			//motor[backLeft]=-63;
			//motor[frontRight]=-63;
			//motor[frontLeft]=-63;
			//wait1Msec(12);
	}
}
void drive_backward(float inches){ // drives forward
SensorValue[rightEncoder] = 0;
SensorValue[leftEncoder] = 0;
float ticks = inches * -28.6478898;
	while (SensorValue[rightEncoder]>ticks)
{
		if (SensorValue[rightEncoder]==SensorValue[leftEncoder]){
									if (SensorValue[rightEncoder]/ticks <.3)
				{motor[frontRight]=-60;
					motor[backLeft]=-60;
					motor[frontLeft]=-60;
					motor[backRight]=-60;
				}
				else
				{	motor[frontRight]=-60;
					motor[backLeft]=-60;
					motor[frontLeft]=-60;
					motor[backRight]=-60;}
		}
	//	if (SensorValue[rightEncoder] >SensorValue[leftEncoder]){
	//				motor[backRight]=-127;
	//				motor[backLeft]=-110;
	//				motor[frontRight]=-127;
	//				motor[frontLeft]=-110;
	//	}
	//	if (SensorValue[rightEncoder] <SensorValue[leftEncoder]){
	//				motor[backRight]=-110;
	//				motor[backLeft]=-127;
	//				motor[frontRight]=-110;
	//				motor[frontLeft]=-127;
	//}
}
}
void arm_up(int deg){	// moves arm down
	while (SensorValue[armEncoder] < deg){
		motor[armLeft] = 127;
		motor[armLeft2] = 127; //L -70, R 50 cube1
		motor[armRight] = -127;
		motor[armRight2] = -127;
	}
	}
void old_cube(){
					SensorValue[armEncoder] = 0;
					back_shoot();
					stop_all(400); //stop
					drive_forward(270); //foreward a little
					stop_all(100);
					left_turn(350); //laeral
					stop_all(200); //stop
					drive_forward(990); // 500 ms == 3 ft
					stop_all(200);
					right_turn(360);
					stop_all(200);
					drive_backward(200);
					stop_all(500); //
					arm_down(20);
					stop_all(500);
					drive_forward(1500);
					stop_all(500);
					drive_backward(500);
					stop_all(500);
					arm_down(3);
					stop_all(500);
					drive_forward(1800);
					stop_all(500);
					cube_shoot();
	}
void pro_skills(){
	SensorValue[armEncoder] = 0;
	int startReturn = 800;

	back_shoot();
	stop_all(200);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(2000);

	cube_shoot();
	stop_all(400);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(2000);

	cube_shoot();
	stop_all(400);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);

	arm_up(20);
	back_shoot();
	stop_all(300);
	drive_forward(startReturn);
	stop_all(400);
	arm_down(3);
	stop_all(1400);



	}
void drive_backward_time(int time){
	motor[frontRight]=-60;
	motor[backLeft]=-60;
	motor[frontLeft]=-60;
	motor[backRight]=-60;
	wait1Msec(time);
}
void new_cube(){
					SensorValue[armEncoder] = 0;
					back_shoot();
					stop_all(200);
					drive_forward(9); //foreward a little
					stop_all(500);
					left_turn(240); //laeral
					stop_all(50);
					drive_forward(45);//35 // 500 ms == 3 ft
					//stop_all(50);
					//right_turn(250);
					//stop_all(50);//prev 200
					//drive_backward_time(120);
					//stop_all(50);
					//drive_forward(1);
					//stop_all(50); //prev 500
					//arm_down(10);
					//stop_all(50); //prev 500
					//drive_forward(20); // comp:1500
					//arm_up(90);
					//stop_all(50);//prev 500
					//drive_backward(25); // comp:500
					//stop_all(50);//prev 500
					//arm_down(5);
					//stop_all(50);//prev 500
					//drive_forward(52); // comp:1800
					//stop_all(50);//prev 500
					//cube_shoot();
					//////second star
					//stop_all(50);
					//drive_backward(5);
					//stop_all(50)
					//drive_forward(5);
					//arm_down(5);
					//drive_forward(50);
					//stop_all(50);
					//back_shoot();
					//drive_forward(100);
					//stop_all(50);
					//arm_down(3);
					//stop_all(50);
					//drive_forward(1500); //comp: 1500
					//stop_all(50);
					//arm_up(50);
					//stop_all(50);
					//back_shoot();
	}
	void star(){
	SensorValue[armEncoder] = 0;
	right_turn(250);
	stop_all(50);
	drive_forward(80);
	stop_all(50);
	drive_backward(12);
	stop_all(50);
	left_turn(240);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	right_turn(250);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	right_turn(240);
	stop_all(50);
	arm_up(80);
	stop_all(50);
	arm_down(5);
	stop_all(50);
	drive_forward(12);
	stop_all(50);
	cube_shoot();
	}

task autonomous()
{
  bool autosetup;
  autosetup = true;
	new_cube();

	// positioning, side of arm aligned with first tab crossing, midsection of wheel aligned with second crossing of tabs
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// Lower to defend position
task clawupopen(){
						motor[rightClaw] = -100;
						motor[leftClaw] = -100;
						wait1Msec(1000)
						motor[rightClaw] = 0;
						motor[leftClaw] =  0;

}
task defendPositionl() {
	while(SensorValue[armEncoder] > 90) {
		motor[armLeft] = -127;
		motor[armLeft2] = -127;
		motor[armRight] = 127;
		motor[armRight2] = 127;
	}
	if (SensorValue[armEncoder] < 90) {
		motor[armLeft] = 0;
		motor[armLeft2] = 0;
		motor[armRight] = 0;
		motor[armRight2] = 0;
		return;
	}
}
// Raise to defend position
task defendPositionr() {
	while(SensorValue[armEncoder] < 90) {
		motor[armLeft] = 127;
		motor[armLeft2] = 127;
		motor[armRight] = -127;
		motor[armRight2] = -127;
	}
	if (SensorValue[armEncoder] > 90) {
		motor[armLeft] = 0;
		motor[armLeft2] = 0;
		motor[armRight] = 0;
		motor[armRight2] = 0;
		return;
	}
}

task usercontrol()
{
  // User control code inside the loop
	nMotorEncoder[rightClaw] = 0;
	nMotorEncoder[leftClaw] = 0;
	SensorValue[armEncoder] = 0;
	bool clawFlag = true;
  while (true)
  {

	  	float SpeedDivisor = 1;
	  	float backLimit = SensorValue[armTouch];
			float LeftDrive = vexRT[Ch3]/SpeedDivisor, RightDrive = vexRT[Ch2]/SpeedDivisor;
//drive
			motor[frontLeft] = LeftDrive;
	  	motor[backLeft] = LeftDrive;
	  	motor[frontRight] = RightDrive;
	  	motor[backRight] = RightDrive;

// claw code
		if(vexRT[Btn5D] == 1){	// claw opens

					motor[rightClaw] = -127;
					motor[leftClaw] = -127;
		}
	 	 else if(vexRT[Btn5U] == 1){ //claw closes
					motor[rightClaw] = 127;
					motor[leftClaw] = 127;
		}
		else if ((SensorValue[armEncoder] > 50) && (clawFlag == true)) {
			startTask (clawupopen);
			clawFlag = false;
			}
			else if ((SensorValue[armEncoder] <50)){ // stays at 0 if lift is not going up
				motor[leftClaw] = 0;
				motor[rightClaw] = 0;
				clawFlag = true;
				}


// arm code

	  	if (vexRT[Btn7R] == 1){
	  		if ((nMotorEncoder[leftClaw] <180) ){
						motor[rightClaw] = 0;
						motor[leftClaw] = 0;
					}
					else{
						motor[rightClaw] = -127;
						motor[leftClaw] = -127;
			}
			}
			if ((vexRT[Btn6U] == 1) && (SensorValue[armEncoder] >40)){
				if ((nMotorEncoder[leftClaw] < 180) || (nMotorEncoder[rightClaw] > -360)){
						motor[rightClaw] = 0;
						motor[leftClaw] = 0;
					}
					else{
						motor[rightClaw] = -100;
						motor[leftClaw] = -100;

					}


			}
	  	if(vexRT[Btn6U] == 1 && backLimit == 0 )	// if button 6U is pressed, arm goes up
			{

				motor[armLeft] = 127;
				motor[armLeft2] = 127;
				motor[armRight] = -127;
				motor[armRight2] = -127;
			}
	 	 else if(vexRT[Btn6D] == 1) // if button 6D is pressed, arm goes down
			{
				motor[armLeft] = -127;
				motor[armLeft2] = -127;
				motor[armRight] = 127;
				motor[armRight2] = 127;
			}
		else // stays at 0
			{
				motor[armLeft] = 0;
				motor[armLeft2] = 0;
				motor[armRight] = 0;
				motor[armRight2] = 0;
			}




		//	if(vexRT[Btn8D] == 1){
		//		if((SensorValue[armEncoder] >80))
		//		{
		//		if ((nMotorEncoder[leftClaw] < 180) || (nMotorEncoder[rightClaw] > -360)){
		//				motor[rightClaw] = 0;
		//				motor[leftClaw] = 0;
		//			}
		//			else{
		//				motor[rightClaw] = -100;
		//				motor[leftClaw] = -100;

		//			}
		//	}
		//}
			if(vexRT[Btn8U] == 1){

	nMotorEncoder[rightClaw] = 0;
	nMotorEncoder[leftClaw] = 0;
	SensorValue[armEncoder] = 0;
		//SensorValue[ArmEncoder] = 0;

				//back_shoot();
				//	stop_all(200);
				//	drive_forward(270); //foreward a little
				//	stop_all(50);
				//	left_turn(350); //laeral
				//	stop_all(50);
				//	drive_forward(990); // 500 ms == 3 ft
				//	stop_all(50);
				//	right_turn(360);
				//	stop_all(50);//prev 200
				//	drive_backward(200); //comp:200
				//	stop_all(50); //prev 500
				//	arm_down(20);
				//	stop_all(50); //prev 500
				//	drive_forward(1500); // comp:1500
				//	stop_all(50);//prev 500
				//	drive_backward(500); // comp:500
				//	stop_all(50);//prev 500
				//	arm_down(3);
				//	stop_all(50);//prev 500
				//	drive_forward(1500); // comp:1800
				//	stop_all(50);//prev 500
				//	cube_shoot();

				//	drive_forward(300);
				//	arm_down(3);
				//	drive_forward(1500); //comp: 1500
				//	arm_up(50);
				//	back_shoot();}

	}
    // DO NOT REMOVE BELOW WITHOUT ASKING ANISH.
    UserControlCodePlaceholderForTesting();
  }
}
