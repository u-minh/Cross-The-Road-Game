#include "bird.h"

cBird::~cBird()
{
	for (int i = 0; i < 2; i++)
	{	
		for (int j = 0; j < 5; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

cBird::cBird(int x, int y, int speed)
	: cAnimal(x, y, speed)
{}

int cBird::width()
{
	return this->width_;
}

void cBird::draw()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << bird[i][j];
		}
	}
}

void cBird::erase()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoXY(j + GetX(), i + GetY());
			cout << ' ';
		}
	}
}

void cBird::MakeSound()
{
	Music bird;
	bird.playBird();
}

void cBird::Move()
{
		erase();
		color(15, 0);
		SetX(GetX() + GetSpeed());
		draw();
}