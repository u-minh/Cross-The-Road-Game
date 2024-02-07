//#include "lane.h"
//
//void Lane::EraseOldList()
//{
//	for (int i=0; i<vehicles.size(); ++i)
//	{
//		delete vehicles[i];
//		vehicles[i] = nullptr; 
//	}
//	vehicles.clear();
//}
//
//void Lane::SetNewList(vector <cVehicle*> vehs)
//{
//	this->EraseOldList();
//	for (int i = 0; i < vehs.size(); ++i)
//	{
//		cVehicle* tmp = new cVehicle(*vehs[i]);
//		vehicles.push_back(tmp);
//	}
//}
//
//Lane::Lane()
//{
//	this->EraseOldList();
//	startingPos = 0;
//}
//
//Lane::Lane(vector <cVehicle*> vehs, Traffic_Light tmplight, int pos)
//{
//	SetNewList(vehs);
//	light = tmplight;
//	startingPos = pos;
//}
//
//Lane::~Lane()
//{
//	this->EraseOldList();
//}
//
//void Lane::MoveAll() 
//{
//	
//}