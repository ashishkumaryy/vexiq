#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor2,          armright,      tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightmotor,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,          armleft,       tmotorVexIQ, PIDControl, reversed, encoder)


#include "lib-command.h"


task main()

{

	//Working code as of March 01, 2019 10:39 PM

	initializeMotors();



	//@@@START - Pick up yellow hub@@
	moveRight(240, 100);

	//03/02/19 3:04 PM Changed from 390 to 400
	moveArmMotors(ARM_UP, 400, 50);
	moveBaseMotors(MOVE_FORWARD, 425, 80);
	moveArmMotors(ARM_UP, 100, 50);
	moveBaseMotors(MOVE_BACKWARD, -365, 80);
	//@@@END - Pick up yellow hub@@

	//@@@START - First orange hub@@
	//03/02/19 3:04 PM Changed from -200 to -250
	moveArmMotors(ARM_DOWN, -250, 50);  //-250
	moveLeft(190, 100); //220
	moveBaseMotors(MOVE_FORWARD, 850, 100);

	//03/02/19 3:35 PM Changed from 400 to 410
	moveLeft(410, 50); //400

		//03/02/19 3:45 PM Speed changed from 80 to 100
	moveBaseMotors(MOVE_FORWARD, 580, 100);//50

	moveLeft(1000, 60);

	//03/02/19 3:45 PM Speed changed from 80 to 100
	moveBaseMotors(MOVE_FORWARD,1000 , 100);//50 950
	////@@@END - First orange hub@@

	//03/02/19 3:37 PM Changed speed from 50 to 60
	moveArmMotors(ARM_DOWN, -150, 60);

	moveRight(900, 80); //Changing from 1000 to 900
	moveBaseMotors(MOVE_FORWARD, 950, 100);
	moveLeft(1000, 100);

	//03/02/19 3:37 PM Changed speed from 50 to 60
	moveArmMotors(ARM_UP, 250, 60);
		//03/02/19 3:48 PM Changed forward from 420 to 410
	moveBaseMotors(MOVE_FORWARD, 420, 100);
	moveBaseMotors(MOVE_BACKWARD, -255, 100);

	//03/02/19 3:37 PM Changed speed from 80 to 75
	moveArmMotors(ARM_DOWN, -250, 75);
	moveBaseMotors(MOVE_BACKWARD, -400, 50);
	////wait1Msec(5000);

}
