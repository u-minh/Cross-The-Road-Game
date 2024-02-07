#include "trafficLight.h"

Traffic_Light::Traffic_Light()
{
	this->mX = 0;
	this->mY = 0;
}

Traffic_Light::Traffic_Light(int x, int y)
{
	this->mX = x;
	this->mY = y;
}

Traffic_Light::Traffic_Light(const Traffic_Light& src)
{
	mX = src.mX;
	mY = src.mY;
	isRed = src.isRed;
}

Traffic_Light& Traffic_Light::operator=(const Traffic_Light& src)
{
	mX = src.mX;
	mY = src.mY;
	return *this;
}
void Traffic_Light::setRed(bool x)
{
	this->isRed = x;
}
bool Traffic_Light::stop()
{
	return this->isRed;
}

void Traffic_Light::drawLight()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				color(15, 2);
			else
				color(15, 0);
			gotoXY(j + mX, i + mY);
			cout << this->light[i][j];
		}
	}
}

void Traffic_Light::changeLight(int colors)
{
	color(15, colors);
	gotoXY(mX + 1, mY + 0);
	cout << this->light[1][1];
}
