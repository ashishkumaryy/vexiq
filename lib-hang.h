//#pragma config(Motor,  motor4,          rightmotor,    tmotorVexIQ, PIDControl, driveLeft, encoder)
//#pragma config(Motor,  motor6,          armleft,       tmotorVexIQ, PIDControl, reversed, encoder)
//#pragma config(Motor,  motor8,          armright,      tmotorVexIQ, PIDControl, encoder)
//#pragma config(Motor,  motor12,         leftMotor,     tmotorVexIQ, PIDControl, reversed, driveRight, encoder)

#pragma systemFile

const int MOVE_FORWARD 				= 1001;
const int MOVE_REVERSE 				= 1002;
const int TURN_RIGHT 					= 2001;
const int TURN_LEFT 					= 2002;
const int ARM_UP 							= 3001;
const int ARM_DOWN 						= 3002;

void stopDriveTerrainMotors()
{
	motor[leftMotor]= 0;
	motor[rightmotor] = 0;
	wait1Msec(100);
}

void stopArmMotors()
{
	//set to stop
	motor[armleft]= 0;
	motor[armright] = 0;
	wait1Msec(100);
}

void turnLeft(int motorSpeed, float waitTimeInMs)
{
	motor[leftMotor] = motorSpeed;
	motor[rightmotor] = 0;
	wait1Msec(waitTimeInMs);
}

//Turns the robot to right
void turnRight(int motorSpeed, float waitTimeInMs)
{
	motor[leftMotor] = 0;
	motor[rightmotor] = motorSpeed;
	wait1Msec(waitTimeInMs);
}

void moveForward(int motorSpeed, float waitTimeInMs)
{
	motor[leftMotor] = motorSpeed;
	motor[rightmotor] = motorSpeed;
	wait1Msec(waitTimeInMs);
}

void moveReverse(int motorSpeed, float waitTimeInMs)
{
	motor[leftMotor] = -motorSpeed;
	motor[rightmotor] = -motorSpeed;
	wait1Msec(waitTimeInMs);
}

void moveArmUp(int motorSpeed, float waitTimeInSecs)
{
	motor[armleft] = motorSpeed;
	motor[armright] = motorSpeed;
	wait1Msec(waitTimeInSecs);
}

void moveArmDown(int motorSpeed, float waitTimeInMs)
{
	motor[armleft] = -motorSpeed;
	motor[armright] = -motorSpeed;
	wait1Msec(waitTimeInMs);
}

//void spinRobot(int leftMotorSpeed, int rightMotorSpeed, float waitTimeInMs)
//{
//	motor[leftMotor] = leftMotorSpeed;
//	motor[rightmotor] = rightMotorSpeed;
//	wait1Msec(waitTimeInMs);
//	stopDriveTerrainMotors();
//}

void moveArm(int direction, int motorSpeed, float waitTimeInMs)
{
	switch(direction)
	{
	case ARM_UP:
		moveArmUp(motorSpeed, waitTimeInMs);
		break;

	case ARM_DOWN:
		moveArmDown(motorSpeed, waitTimeInMs);
		break;
	}
	//stopArmMotors();
}

void move(int direction, int motorSpeed, float waitTimeInMs)
{
	switch(direction)
	{
	case MOVE_FORWARD:
		moveForward(motorSpeed, waitTimeInMs);
		break;

	case MOVE_REVERSE:
		moveReverse(motorSpeed, waitTimeInMs);
		break;

	case TURN_RIGHT:
		turnRight(motorSpeed, waitTimeInMs);
		break;

	case TURN_LEFT:
		turnLeft(motorSpeed, waitTimeInMs);
		break;
	}
	//stopDriveTerrainMotors();
}

void initializeMotors()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightmotor);
	resetMotorEncoder(armleft);
	resetMotorEncoder(armright);
}
