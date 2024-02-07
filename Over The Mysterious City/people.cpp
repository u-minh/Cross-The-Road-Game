#include "people.h"
#include "game.h"

cPeople::cPeople()
{
	this->mX = 0;
	this->mY = 0;
	this->speed = 1;
	this->mState = true;
}

cPeople::cPeople(int x, int y)
{
	this->mX = x;
	this->mY = y;
	this->speed = 1;
	this->mState = true;
}


int cPeople::width()
{
	return this->width_;
}
int cPeople::getX() { return this->mX; }
int cPeople::getY() { return this->mY; }
bool cPeople::getState() { return this->mState; }

void cPeople::setCoord(int x, int y)
{
	this->mX = x;
	this->mY = y;
}

void cPeople::setSpeed(int v) { this->speed = v; }

int cPeople::getSpeed() { return speed; }

void cPeople::setState(bool state) { this->mState = state; }

bool cPeople::isDead() { return this->mState; }

void cPeople::drawPlayer()
{
	color(15, 0);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoXY(j + mX, i + mY);
			cout << people[i][j];
		}
	}
}
void cPeople::erasePlayer()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoXY(j + mX, i + mY);
			cout << ' ';
		}
	}
}

cPeople::~cPeople() {}
