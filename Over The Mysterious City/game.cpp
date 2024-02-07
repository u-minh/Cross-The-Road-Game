#include "game.h"

int score = 0;
int gatePos = 0;
string name;
string filename;

bool isFinish = false; //get to finish line
bool isStop = false; //vehicle state
bool isEnd = false; //game state
bool loadIngame = false; //if game loading occurs while playing
bool isLoaded = false; //if game is loaded
bool saved = false; //if game is saved

int level = 1;
int Speed = 1;
int posX = SCREEN_WIDTH / 2, posY = SCREEN_HEIGHT - 3; //default position of people

vector <cVehicle*> allvhs;
vector <cAnimal*> allans; //for saving vehicles and animals

int loadedPeopleX;
int loadedPeopleY; //for saving and loading position of people

void game::ClearVLanes()
{
	for (int i = 0; i < vlanes.size(); ++i)
	{
		delete vlanes[i];
		vlanes[i] = nullptr;
	}
	vlanes.clear();
}

void game::SetNewVLanes(vector <VehicleLane*> src)
{
	this->ClearVLanes();
	for (int i = 0; i < vlanes.size(); ++i)
	{
		VehicleLane* tmp = new VehicleLane(*src[i]);
		vlanes.push_back(tmp);
	}
}

void game::ClearALanes()
{
	for (int i = 0; i < alanes.size(); ++i)
	{
		delete alanes[i];
		alanes[i] = nullptr;
	}
	alanes.clear();
}

void game::SetNewALanes(vector<AnimalLane*> src)
{
	this->ClearALanes();
	for (int i = 0; i < src.size(); ++i)
	{
		AnimalLane* tmp = new AnimalLane(*src[i]);
		alanes.push_back(tmp);
	}
}

game::game()
{
	ClearALanes();
	ClearVLanes();
	people = new cPeople();
}

game::game(vector<VehicleLane*> vsrc, vector<AnimalLane*> asrc, cPeople* psrc)
{
	SetNewALanes(asrc);
	SetNewVLanes(vsrc);
	people = psrc;
}

game::~game()
{
	ClearALanes();
	ClearVLanes();
	delete people;
}

void game::Explosion(int x, int y)
{
/*
	 '.  \ | /  ,'
	   `. `.' ,'
	   .`. | , '.
	 - ~ - 0 - ~ -
*/
	people->setState(false); //people is hit
	color(15, 4);
	gotoXY(x, y); cout << "0";
	string base = " - ~ ~";
	string top[3] = {"  .`. | , '.", "  `. `.' ,'", "'.  \\ | /  ,'"};
	for (int i = 0; i < 6; i++)
	{
		Sleep(50);
		gotoXY(x + i + 1, y);	cout << base[i];
		gotoXY(x - i - 1, y);	cout << base[i];
	}
	for (int i = 1; i < 4; i++)
	{
		Sleep(100);
		gotoXY(x - 6, y - i);
		cout << top[i-1];
	}

	Sleep(500);
	gotoXY(35, 12);
	cout << "                           ";
	gotoXY(35, 13);
	cout << "                           ";
	string ctn = "Press any key to continue";
	int ind = 0;
	string::iterator it;
	for (it = ctn.begin(); it != ctn.end(); it++)
	{
		if (ind % 2 == 1)
		{
			gotoXY(43, 12);
			cout << "                         ";
		}
		else
		{
			gotoXY(43, 12);
			cout << "GAME OVER!!!      ";
		}
		gotoXY(36 + ind, 13);
		cout << *it;
		Sleep(120);
		ind++;
	}
}

void game::openGate()
{
	srand(time(NULL));
	gatePos = rand() % 70 + 2;
	gotoXY(gatePos, 0);
	cout << "|               |";
	isFinish = true;
}

void game::ObjRunner()
{
	while (!isEnd)
	{
		if (!isStop)
		{
			gotoXY(102, 8);
			cout << "            ";
			Sleep(100);
			for (int i = 0; i < vlanes.size(); ++i)
			{
				if (collision(i) != -1)
				{
					Music end;
					end.playImpact();
					isEnd = true;

					if (people->getY() % 2 == 0)
						vlanes[i]->getVehicles()[collision(i)]->erase();
					else
						alanes[i]->getAnimals()[collision(i)]->erase();

					Explosion(people->getX() - 1, people->getY() + 2);
					break;
				}
				else
				{
					PeopleRunner();
					vlanes[i]->MoveAll();
					if (i < alanes.size())
						alanes[i]->MoveAll();
					updateStat();
					if (posY < 7 && isFinish == false)
						openGate();
				}
			}
		}
		else
		{
			if (saved)
			{
				gotoXY(102, 8);
				color(2, 14);
				cout << "GAME SAVED";
				Sleep(1000);
				gotoXY(102, 8);
				color(15, 0);
				cout << "           ";
				isStop = false;
			}
			else
			{
				gotoXY(102, 8);
				color(11, 1);
				cout << "GAME PAUSED";
			}
		}
	}
}

int game::collision(int i)
{
	for (int j = 0; j < vlanes[i]->getVehicles().size(); ++j)
	{
		if (people->getY() == vlanes[i]->getVehicles()[j]->GetY())
		{
			if (vlanes[i]->getVehicles()[j]->GetX() - 1 <= people->getX() && people->getX() - 1 <= vlanes[i]->getVehicles()[j]->GetX() + vlanes[i]->getVehicles()[j]->width())
			{
				return j;
			}
		}
		if (i < alanes.size())
		{
			for (int k = 0; k < alanes[i]->getAnimals().size(); ++k)
			{
				if (people->getY() == alanes[i]->getAnimals()[k]->GetY())
				{
					if (alanes[i]->getAnimals()[k]->GetX() <= people->getX() && people->getX() <= alanes[i]->getAnimals()[k]->GetX() + alanes[i]->getAnimals()[k]->width())
					{
						return k;
					}
				}
			}	
		}
	}
		
	return -1;
}

void game::PeopleRunner()
{
	people->erasePlayer();
	people->setCoord(posX, posY);
	people->drawPlayer();
}

void game::updateStat()
{
	updateLevel();
	updateScore();
	gotoXY(WIN_WIDTH + 12 - name.size()/2, 7);
	cout << name;
}
void game::NewPlayer()
{
	system("cls");
	system("color F0");
	SetConsoleOutputCP(437);
	gotoXY(33, 12);
	cout << "Welcome hero, let us know your name to save your progress.";
	box(45, 13, 30, 2);
	gotoXY(46, 14);
	getline(cin, name, '\n');
	filename = name;
	level = Speed = 1;
	newGame();
}

void game::newGame()
{
	srand(time(NULL));
	isEnd = false;
	isStop = false;
	isFinish = false;
	posX = SCREEN_WIDTH / 2; posY = SCREEN_HEIGHT - 3; //setting default spawning point
	char key = 0;

	if (!isLoaded)
	{
		ClearALanes();
		ClearVLanes();
		for (int i = 0; i < 4; i++)
		{
			allans.clear();
			allvhs.clear();
			VehicleLane* v;
			AnimalLane* a;

			cVehicle* tmpV;
			cAnimal* tmpA;

			tmpV = new cCar(82, 0, Speed + 1); allvhs.push_back(tmpV);
			tmpV = new cTruck(77, 0, Speed + 1); allvhs.push_back(tmpV);
			tmpV = new cTank(83, 0, Speed + 1); allvhs.push_back(tmpV);
			tmpA = new cBird(83, 0, Speed + 2); allans.push_back(tmpA);
			tmpA = new cTurtle(83, 0, Speed); allans.push_back(tmpA);
			v = new VehicleLane(allvhs, (i + 1) * 2);
			a = new AnimalLane(allans, (i + 1) * 2 - 1);

			vlanes.push_back(v);
			alanes.push_back(a);
		}
	}
	else
	{
		isLoaded = false;
		posX = loadedPeopleX;
		posY = loadedPeopleY;
	}
	SetConsoleOutputCP(65001);
	drawGame();
	drawLane();

	people = new cPeople(posX, posY);
	people->drawPlayer();

	Traffic_Light light1(90, 5);
	light1.drawLight();
	Traffic_Light light2(90, 11);
	light2.drawLight();
	Traffic_Light light3(90, 17);
	light3.drawLight();	
	Traffic_Light light4(90, 23);
	light4.drawLight();

	thread c(&game::ObjRunner, this); //thread for running obstacles
	
	while (true)
	{
		Music obs;
		color(15, 0);
		key = toupper(_getch());

		if (key == 'L') //save game
		{
			obs.playSelection();
			isStop = true;
			if (SaveGame(filename))
				saved = true;
		}

		if (key == 'T') //load game
		{
			if (isEnd == false)
				isEnd = true;
			if (loadIngame == false)
				loadIngame = true;
			SetConsoleOutputCP(65001);
			if (isEnd && loadIngame)
			{
				c.join();
				LoadFile();
			}
			break;
		}

		if (key == 'B') //back to menu
		{
			obs.playSelection();
			if (isEnd == false)
				isEnd = true;
			SetConsoleOutputCP(65001);
			if (isEnd)
			{
				c.join();
				level = 1;
				Speed = 1;
				score = 0;
				name = "";
			}
			Sleep(100);
			system("cls");
			Menu men;
			men.menu();
			break;
		}

		if (key == 'P') //pause game
		{
			saved = false;
			obs.playSelection();
			if (isStop == false)
			{
				isStop = true;
			}
			else
			{
				isStop = false;
			}
		}

		if (key == 'O') //turn on/off music
		{
			obs.playSelection();
			Music ms;
			if (MusicMode == true)
			{
				MusicMode = 0;
				ms.close();
			}
			else
			{
				MusicMode = 1;
				ms.newPLay();
			}
			continue;
		}
		if (key == 'W' && !isStop)
		{
			posY -= 3;
			score++;
			
			if (MusicMode)
			{
				if (posY == 24 || posY == 18 || posY == 12) obs.playCar();
				else if (posY == 21 || posY == 15 || posY == 9 || posY == 3) obs.playBird();
			}
		}
		if (key == 'S' && !isStop)
		{
			posY += 3;
			if (posY > 27) 
				posY = 27;

			if (MusicMode)
			{
				if (posY == 24 || posY == 18 || posY == 12) obs.playCar();
				else if (posY == 21 || posY == 15 || posY == 9 || posY == 3) obs.playBird();
			}
		}
		if (key == 'A' && !isStop)
		{
			posX -= 4;
			if (posX < 2)
				posX = 2;
		}
		if (key == 'D' && !isStop)
		{
			posX += 4;
			if (posX > 86)
				posX = 86;
		}
		if (posY < 3 && isFinish == true)
		{
			if (posX >= gatePos && posX <= gatePos + 13)
			{
				isEnd = true;
			}
			else
				posY = 3;
		}
		if (isEnd)
		{
			if (people->getState())
			{
				c.join();
				level++;
				Speed += 1 + level / 2;
				score += 10;
				obs.playSelection();
				newGame(); //place to switch to new level
			}
			else
			{
				c.join();
				Speed = 1;
				popUpWhenDead();
			}
		}
	}
}
void game::drawLane()
{
	for (int i = 26; i > 1; i -= 3)
	{
		gotoXY(1, i);
		cout << "--------------------------------------------------------------------------------------------";
	}
	
}
void game::drawBorder()
{
	color(15, 0);
	SetConsoleOutputCP(437);
	box(0, 0, 93, 29);
	box(0, 0, 119, 29);
}

void game::updateLevel()
{
	color(15, 0);
	gotoXY(WIN_WIDTH + 7, 25);
	cout << "Level:  " << level;
}
void game::updateScore()
{
	color(15, 0);
	gotoXY(WIN_WIDTH + 8, 5);
	cout << "Score: " << score << endl;
}

void box(int x, int y, int w, int h)
{
	color(15, 0);
	for (int iy = y; iy <= y + h; iy++)
	{
		for (int ix = x; ix <= x + w; ix++)
		{
			gotoXY(iy, iy);
			cout << " ";
		}
	}
	if (h <= 1 || w <= 1)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + w, y);
	cout << char(191);
	gotoXY(x, y + h);
	cout << char(192);
	gotoXY(x + w, y + h);
	cout << char(217);
}

void game::drawGame()
{
	color(15, 0);
	system("cls");
	drawBorder();
	gotoXY(WIN_WIDTH + 10, 2);
	cout << "Over:";
	gotoXY(WIN_WIDTH + 2, 3);
	cout << "The Mysterious City";
	gotoXY(WIN_WIDTH + 7, 4);
	cout << "----------";
	gotoXY(WIN_WIDTH + 7, 6);
	cout << "----------";
	gotoXY(WIN_WIDTH + 10, 12);
	cout << "Menu:";
	gotoXY(WIN_WIDTH + 7, 13);
	cout << "----------";
	gotoXY(WIN_WIDTH + 2, 14);
	color(15, 2);
	cout << "Pause:            P";
	gotoXY(WIN_WIDTH + 2, 15);
	color(15, 3);
	cout << "Save Progress:    L";
	gotoXY(WIN_WIDTH + 2, 16);
	color(15, 4);
	cout << "Load Saved Game:  T";
	gotoXY(WIN_WIDTH + 2, 17);
	color(15, 5);
	cout << "On/Off Music:     O";
	gotoXY(WIN_WIDTH + 2, 18);
	color(15, 6);
	cout << "Back To Menu:     B";
	gotoXY(WIN_WIDTH + 9, 25);
	cout << "Level:" << level;
	gotoXY(WIN_WIDTH + 7, 26);
	color(15, 0);
	cout << "----------";
}

void game::popUpWhenDead()
{
	system("cls");
	SetConsoleOutputCP(65001);
	printGAMEOVER();
	Music sel;
	string dead[] = { "    Play Again   ","    Main Menu    " };
	int set[] = { 7,7 };
	int counter = 0;
	string space = "     ";
	gotoXY(55, 12);
	color(0, 7);
	cout << "    Score: " << score;
	if (score >= 10 && score < 100) space.erase(0, 1);
	if (score >= 100 && score < 1000) space.erase(0, 2);
	if (score >= 1000 && score < 10000) space.erase(0, 3);
	cout << space << endl;
	gotoXY(55, 13);
	color(0, 7);
	cout << "    Level: " << level << "     " << endl;
	level = 1;
	gotoXY(55, 14);
	color(0, 7);
	cout << "    ----0----    ";
	while (true)
	{
		if (counter == 0) set[0] = 12;
		if (counter == 1) set[1] = 12;
		for (int j = 0; j < 2; j++)
		{
			gotoXY(55, 15 + j);
			SetColor(set[j]);
			cout << dead[j];
		}
		char key = toupper(_getch());
		if (key == 'W')
		{
			sel.playSelection();
			counter--;
			if (counter == -1) counter = 1;
		}
		if (key == 'S')
		{
			sel.playSelection();
			counter++;
			if (counter == 2) counter = 0;
		}
		if (key == ENTER_KEY)
		{
			sel.playSelection();
			Menu menu;
			if (counter == 0)
			{
				score = 0;
				newGame();
			}
			if (counter == 1)
			{
				SetConsoleOutputCP(65001);
				score = 0;
				level = 1;
				name = "";
				menu.menu();
			}
		}
		for (int l = 0; l < 2; l++) set[l] = 7;
	}
}
void game::printGAMEOVER()
{
	string over = R"(
			  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  
			 ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
			▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒
			░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  
			░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒
			 ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░
			  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░
			░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ 
				  ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     
																 ░                 
)";
	cout << over;
	Menu t;
	t.printCity1();
	t.printCity2();
	t.printRiver();
}

bool game::SaveGame(string fname)
{
	fstream fout;
	string path = "./SaveFile/" + fname + ".dat";
	fout.open(path, ios::binary | ios::out);
	if (!fout.is_open())
		return false;
	
	fout.write((char*)&level, sizeof(int));
	fout.write((char*)&score, sizeof(int));

	int tmpx = 0, tmpy = 0;	
	tmpx = people->getX();
	tmpy = people->getY();
	fout.write((char*)&tmpx, sizeof(int));
	fout.write((char*)&tmpy, sizeof(int));

	for (int i = 0; i < vlaneSize; ++i)
	{
		fout.write((char*)vlanes[i], sizeof(VehicleLane));
	}

	for (int i = 0; i < alaneSize; ++i)
	{
		fout.write((char*)alanes[i], sizeof(AnimalLane));
	}

	fout.close();
	if (!fout.good())
	{
		cout << "Error at writing time" << endl;
		return false;
	}
	return true;
}

vector<string> game::getAllFileName(const string& name)
{
	vector<string> loads;
	string folder(name);
	folder.append("\\*");

	wstring tmp = wstring(folder.begin(), folder.end());
	LPCWSTR sw = tmp.c_str();

	WIN32_FIND_DATA dat;
	HANDLE search;

	if ((search = FindFirstFile(sw, &dat)) != INVALID_HANDLE_VALUE) {
		do {
			wchar_t* txt = dat.cFileName;
			wstring ws(txt);
			string str(ws.begin(), ws.end());
			if (str[0] == '.') continue;
			loads.push_back(str);
		} while (FindNextFile(search, &dat) != 0);
		FindClose(search);
	}
	return loads;
}

bool game::LoadGame(string fname)
{
	fstream fin;
	string path = "./SaveFile/" + fname + ".dat";
	fin.open(path, ios::binary | ios::in);
	if (!fin.is_open())
		return false;

	filename = fname;
	fin.read((char*)&level, sizeof(int));
	fin.read((char*)&score, sizeof(int));
	
	fin.read((char*)&loadedPeopleX, sizeof(int));
	fin.read((char*)&loadedPeopleY, sizeof(int));

	ClearALanes();
	ClearVLanes();

	for (int i = 0; i < vlaneSize; ++i)
	{
		VehicleLane* tmpV = new VehicleLane();
		fin.read((char*)tmpV, sizeof(VehicleLane));
		vlanes.push_back(tmpV);
	}

	for (int i = 0; i < alaneSize; ++i)
	{
		AnimalLane* tmpA = new AnimalLane();
		fin.read((char*)tmpA, sizeof(AnimalLane));
		alanes.push_back(tmpA);
	}

	fin.close();

	if (!fin.good())
	{
		cout << "Error at reading time" << endl;
		return false;
	}

	return true;
}

void game::LoadFile()
{
	string getloadfile = showLoadGame();
	if (LoadGame(getloadfile))
	{
		isLoaded = true;
		newGame();
	}
}
	
string game::showLoadGame()
{
	system("cls");
	Menu menu;
	vector<string> temp = getAllFileName("SaveFile");
	vector<string> sub;
	int x = 48, y = 9, count = 0,subCount=0;
	vector<int> set(temp.size());
	fill(set.begin(), set.end(), 0);
	Music sel;
	int counter = 0;
	system("color F3");
	string load = R"(
			██╗      ██████╗  █████╗ ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗
			██║     ██╔═══██╗██╔══██╗██╔══██╗    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝
			██║     ██║   ██║███████║██║  ██║    ██║  ███╗███████║██╔████╔██║█████╗  
			██║     ██║   ██║██╔══██║██║  ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  
			███████╗╚██████╔╝██║  ██║██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗
			╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
)";
	cout << load;
	SetConsoleOutputCP(437);
	color(15, 3);
	box(44, 7, 40, 20);
	gotoXY(42, 28);
	cout << "------Press ESC to get back to main menu------";

	for (int i = 0; i < 6; i++)
	{
		box(x, y, 30, 2);
		y += 3;
	}
	for (auto& i : temp) i = i.substr(0, i.length() - 4);
	while (true)
	{
		for (int k = 0; k < temp.size(); k++)
		{
			if (counter == count)
			{
				set[count] = 12;
			}

		}
		for (int k = 0, m = 0; k < temp.size(); k++, m += 3)
		{
			gotoXY(52, 10 + m);
			color(15, set[k]);
			cout << temp[k] << endl;
		}
		char key = toupper(_getch());
		if (key == UP_ARROW || key == 'W')
		{
			sel.playSelection();
			counter--;
			count--;
			if (counter == -1)
			{
				counter = temp.size() - 1;
				count = temp.size() - 1;
			}
		}
		if (key == DOWN_ARROW || key == 'S')
		{
			sel.playSelection();
			counter++;
			count++;
			if (counter == temp.size())
			{
				counter = 0;
				count = 0;
			}
		}
		if (key == ESCAPE_KEY)
		{
			sel.playSelection();
			SetConsoleOutputCP(65001);
			name = "";
			menu.menu();
			break;
		}
		if(key==ENTER_KEY)
		{
			sel.playSelection();
			system("cls");
			if (loadIngame)
			{
				if (filename == temp[count])
				{
					color(15, 13);
					system("cls");
					SetConsoleOutputCP(65001);
					menu.printTitle();
					SetConsoleOutputCP(437);
					color(15, 0);
					box(25, 13, 72, 6);

					color(15, 0);
					gotoXY(28, 16);
					cout << "Can't load current game slot because it's currently being played";
					Sleep(2000);

					SetConsoleOutputCP(65001);
					showLoadGame();
					break;
				}
			}
			name = temp[count];
			return temp[count];
		}
		for (auto& i : set) i = 0;
	}
}
