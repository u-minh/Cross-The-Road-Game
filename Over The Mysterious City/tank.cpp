#pragma once
#include "tank.h"

cTank::~cTank()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

cTank::cTank(int x, int y, int speed)
	: cVehicle(x, y, speed)
{}

int cTank::width()
{
	return this->width_;
}

void cTank::draw()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << tank[i][j];
		}
	}
}
void cTank::erase()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

void cTank::MakeSound()
{
	Music tmp;
	tmp.playCar();
}

void cTank::Move()
{
	erase();
	color(15, 0);
	SetX(GetX() + GetSpeed());
	draw();
}

