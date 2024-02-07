#pragma once

#ifndef _cTank_H_
#define _cTank_H_

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "vehicle.h"
#include "console.h"
#include "Music.h"

using namespace std;

class cTank : public cVehicle
{
private:
	const int width_ = 7;
	const char tank[2][7] = { '|', '"', '"', '"', '\\', '-', '=',
						'(', 'o', '_', '_', 'o', ')', ' ' };

public:
	cTank(int, int, int);
	~cTank();

	int width(); //method of getting width
	void draw() override;
	void erase() override;
	void MakeSound() override;
	void Move() override;
};
#endif 

