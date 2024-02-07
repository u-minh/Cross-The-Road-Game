#pragma once

#ifndef _cPeople_H_
#define _cPeople_H_

#include <iostream>
#include <Windows.h>
#include "animal.h"
#include "vehicle.h"
#include <mmsystem.h>
#include "console.h"
#include "Music.h"

using namespace std;

class cPeople
{
private:
/*
		L°/
		" "
*/
	char people[2][3] = {'L', 'o', '/',
						'/', '"', '\\'};
	int mX, mY;
	bool mState; //true: alive, false: dead
	int speed;
	const int width_ = 3;
public:
	cPeople();
	cPeople(int, int);
	~cPeople();

	int width(); //getting the width method
	int getX();
	int getY();
	bool getState();
	int getSpeed();

	void setCoord(int, int);
	void setSpeed(int);
	void setState(bool);

	void drawPlayer();
	void erasePlayer();
	
	bool isDead();
};
#endif _cPeople_H_