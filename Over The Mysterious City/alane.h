#pragma once
#include "animal.h"
#include "bird.h"
#include "turtle.h"
#include "trafficLight.h"
#include <vector>

using namespace std;

class AnimalLane
{
	private:
		int startingPos; //position of the lane
		vector <cAnimal*> animals; //list of animals
	public:
		void EraseOldList();
		void SetNewList(vector<cAnimal*>);

		AnimalLane();
		AnimalLane(vector<cAnimal*>, int);
		AnimalLane(const AnimalLane&);
		~AnimalLane();

		int getPos();
		vector <cAnimal*> getAnimals();

		void MoveAll();
		bool RespawnAble(int); //check if an animal can be respawned at the start of the lane
};