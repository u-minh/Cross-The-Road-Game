#include "alane.h" //animal lane

void AnimalLane::EraseOldList()
{
	for (int i = 0; i < animals.size(); ++i)
	{
		delete animals[i];
		animals[i] = nullptr;
	}
	animals.clear();
}

void AnimalLane::SetNewList(vector <cAnimal*> ans)
{
	if (this->animals.size() != 0)
		this->EraseOldList();
	for (int i = 0; i < ans.size(); ++i)
	{
		animals.push_back(ans[i]);
	}
}

AnimalLane::AnimalLane()
{
	this->EraseOldList();
	startingPos = 1;
}

AnimalLane::AnimalLane(vector <cAnimal*> ans, int pos)
{
	SetNewList(ans);
	startingPos = pos;
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i]->SetY(pos * 3);
	}
}

AnimalLane::AnimalLane(const AnimalLane& src)
{
	SetNewList(src.animals);
	this->startingPos = src.startingPos;
}

AnimalLane::~AnimalLane()
{
	this->EraseOldList();
}

int AnimalLane::getPos() { return startingPos; }

vector <cAnimal*> AnimalLane::getAnimals() { return animals; }

void AnimalLane::MoveAll()
{
	for (int i = 0; i < animals.size(); ++i)
	{
		if (animals[i]->GetX() > SCREEN_WIDTH - animals[i]->width() - animals[i]->GetSpeed())
		{
			if (RespawnAble(i))
			{
				animals[i]->erase();
				if (rand() % 23 == 3)
				{
					animals[i]->SetCoord(2, this->startingPos * 3);
					animals[i]->Move();
				}
				else
				{
					animals[i]->erase();
					animals[i]->SetCoord(96, 9); //if it reaches the end
					animals[i]->erase();
				}
			}
			else
			{
				animals[i]->erase();
				animals[i]->SetCoord(96, 9); //if it reaches the end
				animals[i]->erase();
			}
		}
		else
		{
			if (animals[0]->GetX() < animals[1]->GetX() && animals[0]->GetX() + animals[0]->width() + animals[0]->GetSpeed() > animals[1]->GetX())
			{
				if (animals[0]->GetX() < animals[0]->width() - 1)
					animals[0]->erase();
				animals[1]->Move();
			}
			else
				animals[i]->Move();
		}
	}
}

bool AnimalLane::RespawnAble(int x)
{
	for (int i = 0; i < animals.size(); ++i)
	{
		if (i != x)
			if (animals[i]->GetX() <= (animals[i]->width() + animals[i]->GetSpeed()))
			{
				return false;
			}
	}
	return true;
}
