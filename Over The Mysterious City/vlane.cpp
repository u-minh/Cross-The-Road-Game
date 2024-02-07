#include "vlane.h" //vehicle lane

void VehicleLane::EraseOldList()
{
	for (int i=0; i<vehicles.size(); ++i)
	{
		delete vehicles[i];
		vehicles[i] = nullptr; 
	}
	vehicles.clear();
}

void VehicleLane::SetNewList(vector <cVehicle*> vehs)
{
	if (this->vehicles.size() != 0)
		this->EraseOldList();
	for (int i = 0; i < vehs.size(); ++i)
	{
		vehicles.push_back(vehs[i]);
	}
}

VehicleLane::VehicleLane()
{
	this->EraseOldList();
	startingPos = 1;
	carPassed = 0;
}

VehicleLane::VehicleLane(vector <cVehicle*> vehs, int pos)
{
	SetNewList(vehs);
	startingPos = pos;
	for (int i = 0; i < vehs.size(); i++)
	{
		vehs[i]->SetY(pos*3);
	}
	carPassed = 0;
}

VehicleLane::VehicleLane(const VehicleLane& src)
{
	SetNewList(src.vehicles);
	this->carPassed = src.carPassed;
	this->startingPos = src.startingPos;
}

VehicleLane& VehicleLane::operator=(const VehicleLane& src)
{
	SetNewList(src.vehicles);
	this->carPassed = src.carPassed;
	this->startingPos = src.startingPos;
	return *this;
}

VehicleLane::~VehicleLane()
{
	this->EraseOldList();
}

int VehicleLane::getPos() { return startingPos; }

vector <cVehicle*> VehicleLane::getVehicles() { return vehicles; }

void VehicleLane::MoveAll()
{
	Traffic_Light tmp(90, startingPos * 3);

	for (int i = 0; i < vehicles.size(); ++i)
	{
		if (carPassed % 7 == (1 + vehicles[0]->GetSpeed()))
		{
			tmp.changeLight(4);
			if (rand() % (51*vehicles[i]->GetSpeed()) == 3)
				carPassed++;
		}
		else
		{
			tmp.changeLight(2);
			if (vehicles[i]->GetX() > SCREEN_WIDTH - vehicles[i]->width() - vehicles[i]->GetSpeed())
			{
				if (RespawnAble(i))
				{
					vehicles[i]->erase();
					if (rand() % 13 == 3)
					{
						carPassed++;
						vehicles[i]->SetCoord(2, this->startingPos * 3);
						vehicles[i]->Move();
					}
					else
					{
						vehicles[i]->erase();
						vehicles[i]->SetCoord(96, 9); // hide it hehe
						vehicles[i]->erase();
					}
				}
				else
				{
					vehicles[i]->erase();
					vehicles[i]->SetCoord(96, 9); // hide it hehe
					vehicles[i]->erase();
				}
			}
			else
				vehicles[i]->Move();
		}
	}
}


bool VehicleLane::RespawnAble(int x)
{
	for (int i = 0; i < vehicles.size(); ++i)
	{
		if (i != x)
			if (vehicles[i]->GetX() <= (vehicles[x]->width() + 1 + vehicles[i]->GetSpeed()))
			{
				return false;
			}
	}
	return true;
}
