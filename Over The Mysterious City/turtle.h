#pragma once
#ifndef _cTurtle_H_
#define _cTurtle_H_

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "animal.h"
#include "console.h"
#include "Music.h"

using namespace std;

class cTurtle : public cAnimal
{
/*
     .~~. *>
   _/,__,\/
*/

	private:
		const int width_ = 9;
		const char turtle[2][9] = { ' ', ' ', '.', '~', '~', '.', ' ', '*', '>',
					'_', '/', ',', '_', '_', ',', '\\', '/', ' ' };

	public:
		cTurtle(int, int, int);
		~cTurtle();

		int width(); //get width method
		void draw();
		void erase();
		void MakeSound() override;
		void Move() override;
};
#endif 
