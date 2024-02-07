#pragma once

#ifndef _cVehicle_H_
#define _cVehicle_H_

#include <iostream>
#include "Music.h"

using namespace std;

class cVehicle
{
	protected:
		int mX, mY;
		int Speed;
	public:
		cVehicle();
		~cVehicle();
		cVehicle(int, int);
		cVehicle(int, int, int);
		cVehicle(const cVehicle&);

		int GetX();
		int GetY();
		void SetX(int);
		void SetY(int);
		int GetSpeed();
		void SetSpeed(int);
		void SetCoord(int, int);

		virtual void draw() {};
		virtual void erase() {};
		virtual void MakeSound() = 0;
		virtual void Move() = 0;
		virtual int width() = 0;
};

#endif _cVehicle_H_
