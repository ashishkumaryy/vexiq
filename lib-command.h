#pragma systemFile

const int MOVE_FORWARD = 1;
const int MOVE_BACKWARD = -1;
const int ARM_UP = 10;
const int ARM_DOWN = -10;


void initializeMotors()
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightmotor);
	resetMotorEncoder(armleft);
	resetMotorEncoder(armright);
}

void moveLeft(long degrees, short speed)
{
	moveMotorTarget(leftMotor, degrees, speed);
	waitUntilMotorStop(leftMotor);
}

void moveRight(long degrees, short speed)
{
	moveMotorTarget(rightmotor, degrees, speed);
	waitUntilMotorStop(rightmotor);
}

void moveBase(long degrees, short speed)
{
	moveMotorTarget(leftMotor, degrees, speed);
	moveMotorTarget(rightmotor, degrees, speed);
	waitUntilMotorStop(leftMotor);
	waitUntilMotorStop(rightmotor);
}

void moveBaseMotors(int direction, long degrees, short speed)
{
	if(direction == MOVE_FORWARD)
	{
		if(degrees < 0)
			degrees = -degrees;
	}

	if(direction == MOVE_BACKWARD)
	{
		if(degrees > 0)
			degrees = -degrees;
	}
	moveBase(degrees, speed);
}

void moveArm(long degrees, short speed)
{
	moveMotorTarget(armleft, degrees, speed);
	moveMotorTarget(armright, degrees, speed);
	waitUntilMotorStop(armleft);
	waitUntilMotorStop(armright);
}

void moveArmMotors(int direction, long degrees, short speed)
{
	if(direction == ARM_UP)
	{
		if(degrees < 0)
			degrees = -degrees;
	}

	if(direction == ARM_DOWN)
	{
		if(degrees > 0)
			degrees = -degrees;
	}
	moveArm(degrees, speed);
}

void stackLeftYellowHub()
{
	//003. Move arms down to stack YELLOW hub on the 3 ORANGE hubs
	long downwardDegree = -350;
	short motorSpeed = 80;
	moveArmMotors(ARM_DOWN, downwardDegree, motorSpeed);

	//004. Move back after stacking YELLOW hub
	long backwardDegree = -620;
	motorSpeed = 50;
	moveBaseMotors(MOVE_BACKWARD, backwardDegree, motorSpeed);
}

void stackRightYellowHub()
{
long downwardDegree = -400;
short motorSpeed = 50;
moveArmMotors(ARM_DOWN, -500, 50);

//004. Move back after stacking YELLOW hub
long backwardDegree = -400;
motorSpeed = 50;
//moveBaseMotors(MOVE_BACKWARD, backwardDegree, motorSpeed);
}
