#include "car.h"

cCar::~cCar()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

cCar::cCar(int x, int y, int speed)
	: cVehicle(x, y, speed)
{}

int cCar::width()
{
	return this->width_;
}

void cCar::draw()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << car[i][j];
		}
	}
}
void cCar::erase()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

void cCar::MakeSound()
{
	Music tmp;
	tmp.playCar();
}	

void cCar::Move()
{
	erase();
	color(15, 0);
	SetX(GetX() + GetSpeed());
	draw();
}	


