#pragma once
#ifndef _cBird_H_
#define _cBird_H_

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "animal.h"
#include "console.h"
#include "Music.h"


class cBird : public cAnimal
{
/*
*		_(_p>
*	    \<_)	
*/
	private:
		const int width_ = 5;
		const char bird[2][5] = { '_', '(', '_', 'p', '>',
					'\\', '<', '_', ')' ,' ' };
	public:
		cBird(int, int, int);
		~cBird();

		int width(); //get width method
		void draw();
		void erase();
		void MakeSound() override;
		void Move() override;
};

#endif 