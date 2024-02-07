#pragma once

#ifndef _cCar_H_
#define _cCar_H_

#include <iostream>
#include <Windows.h>
#include "vehicle.h"
#include <mmsystem.h>
#include "console.h"
#include "Music.h"

using namespace std;

class cCar : public cVehicle
{
	private:
		const int width_ = 8;
		const char car[2][8] = { ' ', '_', '~', 'p', '\\', '_', '_', ' ',
					'(', '_', ',', '_', '_', ',', '_', ')' };

	public:
		cCar(int, int, int);
		~cCar();

		int width(); //get width function
		void draw() override;
		void erase() override;
		void MakeSound() override;
		void Move() override;
};
#endif 

