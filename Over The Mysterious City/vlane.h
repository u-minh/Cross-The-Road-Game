#pragma once

#include "car.h"
#include "trafficLight.h"
#include "truck.h"
#include <vector>

class VehicleLane
{
	private:
		int startingPos; //position of the lane
		vector <cVehicle*> vehicles;
		int carPassed; //keep track of number of vehicles in the lane
	public:
		void EraseOldList();
		void SetNewList(vector<cVehicle*>);

		VehicleLane();
		VehicleLane(vector<cVehicle*>, int);
		VehicleLane(const VehicleLane&);
		VehicleLane& operator=(const VehicleLane&);
		~VehicleLane();

		int getPos();
		vector <cVehicle*> getVehicles();
		
		void MoveAll(); //move every vehicle in the lane
		bool RespawnAble(int); //check if a vehicle can be respawned at the start of a lane
};
