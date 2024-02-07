#include "vehicle.h"

cVehicle::cVehicle()
{
	mX = mY = 0;
	Speed = 0;
}

cVehicle::~cVehicle()
{
}

cVehicle::cVehicle(int x, int y)
{
	if (x < 1) mX = 1;
	else mX = x;

	if (y < 1) mY = 1;
	else mY = y;

	Speed = 0;
}

cVehicle::cVehicle(int x, int y, int speed)
{
	if (x < 1) mX = 1;
	else mX = x;

	if (y < 1) mY = 1;
	else mY = y;

	if (speed < 1) Speed = 1;
	else Speed = speed;
}

cVehicle::cVehicle(const cVehicle& src)
{
	mX = src.mX;
	mY = src.mY;
	Speed = src.Speed;
}

int cVehicle::GetX() { return mX; }

int cVehicle::GetY() { return mY; }

void cVehicle::SetX(int x)
{
	mX = x;
}

void cVehicle::SetY(int y)
{
	if (y < 1) mY = 1;
	else mY = y;
}

int cVehicle::GetSpeed() { return Speed; }

void cVehicle::SetSpeed(int speed)
{
	if (speed < 0) Speed = 0;
	else Speed = speed;
}

void cVehicle::SetCoord(int x, int y)
{
	if (x < 1) mX = 1;
	else mX = x;

	if (y < 1) mY = 1;
	else mY = y;
}
