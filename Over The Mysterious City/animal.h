#pragma once

#ifndef _cAnimal_H_
#define _cAnimal_H_

#include <iostream>
#include "console.h"

using namespace std;

class cAnimal
{
	protected:
		int mX, mY;
		int Speed;
	public:
		cAnimal();
		~cAnimal();
		cAnimal(int, int, int);
		int GetX();
		int GetY();
		void SetX(int);
		void SetY(int);
		void SetCoord(int, int);
		int GetSpeed();
		void SetSpeed(int);
		virtual void draw() {};
		virtual void erase() {};
		virtual void Move() = 0;
		virtual void MakeSound() = 0;
		virtual int width() = 0;
};

#endif 