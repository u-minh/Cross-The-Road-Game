#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include <time.h>
#include <thread>
#include <fstream>

#include "console.h"
#include "menu.h"
#include "people.h"
#include "trafficLight.h"
#include "car.h"
#include "truck.h"
#include "turtle.h"
#include "tank.h"
#include "bird.h"
#include "alane.h"
#include "vlane.h"

using namespace std;

class game {
private:
	vector <VehicleLane*> vlanes;
	vector <AnimalLane*> alanes;
	cPeople* people;
public:
	const int vlaneSize = 4; //number of vehicle lanes
	const int alaneSize = 4; //number of animal lanes
	
	void ClearVLanes();
	void SetNewVLanes(vector<VehicleLane*>);
	void ClearALanes();
	void SetNewALanes(vector<AnimalLane*>);

	game();
	game(vector<VehicleLane*>, vector<AnimalLane*>, cPeople*);
	~game();

	void ObjRunner(); //responsible for moving obstacles
	void PeopleRunner(); //responsible for moving people object

	void newGame();
	void drawGame();
	void drawLane();
	void drawBorder();
	void updateScore();
	void updateLevel();
	void updateStat(); //updating score, level, etc... in general
	void openGate();

	void Explosion(int, int); //show explosion upon collision
	int collision(int);
	void popUpWhenDead(); //enable pop-up upon collision 
	void printGAMEOVER();

	void NewPlayer(); //getting player information when starting a new game
	void LoadFile(); 
	bool SaveGame(string);
	vector<string> getAllFileName(const string&); //get all save files in the SaveFile folder
	bool LoadGame(string);
	string showLoadGame();
};

void box(int, int, int, int); 


#endif _GAME_H_