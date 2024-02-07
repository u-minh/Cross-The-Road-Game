#pragma once
#ifndef _MENU_H_
#define _MENU_H

#include "console.h"
#include "Music.h"

using namespace std;

class Menu
{
	public:
		void printTitle();
		void printCity1();
		void printCity2();
		void printRiver();
		void printAll(); //print all elements of menu including: city, title and river

		void settings(); 
		void menu();
		void Instructions();
};

#endif _MENU_H_