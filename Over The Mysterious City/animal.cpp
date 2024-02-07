#include "animal.h"

cAnimal::cAnimal()
{
	this->mX = 0;
	this->mY = 0;
	this->Speed = 0;
}

cAnimal::cAnimal(int x, int y, int speed)
{
	if (x < 1) mX = 1;
	else mX = x;
	
	if (y < 1) mY = 1;
	else mY = y;

	if (speed < 1) Speed = 1;
	else Speed = speed;
}

int cAnimal::GetX()
{
	return this->mX;
}

int cAnimal::GetY()
{
	return this->mY;
}

void cAnimal::SetX(int x)
{
	mX = x;
}

void cAnimal::SetY(int y)
{
	if (y < 1) mY = 1;
	else mY = y;
}

void cAnimal::SetCoord(int x, int y)
{
	this->mX = x;
	this->mY = y;
}

int cAnimal::GetSpeed() { return Speed; }

void cAnimal::SetSpeed(int speed)
{
	if (speed < 1) Speed = 1;
	else Speed = speed;
}

cAnimal::~cAnimal() {}

