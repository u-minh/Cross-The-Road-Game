#include "menu.h"
#include "game.h"

bool isRunning = true;

void Menu::printTitle()
{
	string s2 = R"(
 ██████╗ ██╗   ██╗███████╗██████╗    
██╔═══██╗██║   ██║██╔════╝██╔══██╗██╗
██║   ██║██║   ██║█████╗  ██████╔╝╚═╝
██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗██╗
╚██████╔╝ ╚████╔╝ ███████╗██║  ██║╚═╝
 ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝      
			)";
	cout << s2;
	string s3 = R"(
				╔╦╗┬ ┬┌─┐  ╔╦╗┬ ┬┌─┐┌┬┐┌─┐┬─┐┬┌─┐┬ ┬┌─┐  ╔═╗┬┌┬┐┬ ┬
				 ║ ├─┤├┤   ║║║└┬┘└─┐ │ ├┤ ├┬┘││ ││ │└─┐  ║  │ │ └┬┘
				 ╩ ┴ ┴└─┘  ╩ ╩ ┴ └─┘ ┴ └─┘┴└─┴└─┘└─┘└─┘  ╚═╝┴ ┴  ┴                                 
)";
	cout << s3;
}
void Menu::printCity1()
{
	gotoXY(1, 12);
	cout << "                                    +              \n";
	gotoXY(1, 13);
	cout << "                                   / \\\n";
	gotoXY(1, 14);
	cout << " _____         ____     __________/ o \\/\\ ________      ________\n";
	gotoXY(1, 15);
	cout << "|o o o|_______|    |___|               | | # # #  |____|o o o o |\n";
	gotoXY(1, 16);
	cout << "|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o |\n";
	gotoXY(1, 17);
	cout << "|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o |\n";
	gotoXY(1, 18);
	cout << "|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o |\n";
	gotoXY(1, 19);
	cout << "|_[]__|__[]___|_||_|__<|____________;;_|_|___/\___|_.|_|____[]___|\n";
}
void Menu::printCity2()
{
	gotoXY(54, 12);
	cout << "                                    +              \n";
	gotoXY(54, 13);
	cout << "                                   / \\\n";
	gotoXY(54, 14);
	cout << " _____         ____     __________/ o \\/\\ ________      ________\n";
	gotoXY(54, 15);
	cout << "|o o o|_______|    |___|               | | # # #  |____|o o o o |\n";
	gotoXY(54, 16);
	cout << "|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o |\n";
	gotoXY(54, 17);
	cout << "|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o |\n";
	gotoXY(54, 18);
	cout << "|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o |\n";
	gotoXY(54, 19);
	cout << "|_[]__|__[]___|_||_|__<|____________;;_|_|___/\___|_.|_|____[]___|";
}
void Menu::printRiver()
{
	gotoXY(1, 23);
	cout << "_______________________________________________________________________________________________________________________\n";
	//gotoXY(1, 24);
	cout << " -          -         -       -      -    - -  -- - - --   -    -      --           --       ~~   -    -  - -\n";
	//gotoXY(1, 25);
	cout << "      --                  --       ~~   -    -  - -   - --   --      --	           --       ~~   -    -  - - \n";
	//gotoXY(1, 26);
	cout << "---            ---          ---       -  -            ~~    ---      --             --       ~~   -    -  - - \n";
	//gotoXY(1, 27);
	cout << "     ----               ----        -       ~~~ - ~    - -    -- ---------     -----         ----- -   -   -   ~~  -";
	//gotoXY(1, 28);
	cout << "-----         -----         ----- -   -   -        -      -   --      --        --       ~~   -    -  - -   - --    \n";
	//gotoXY(1, 29);
	cout << "     -----          ------     -          -    - -     -    -  -- -      -   -       -      -    - -  -- - - --";

}
void Menu::printAll()
{
	printTitle();
	printCity1();
	printCity2();
	printRiver();
}

void Menu::settings()
{
	string music[] = { "__On____","o Off|* ","o Back**" };
    Music tmp;
	int set[] = { 7,7,7 };
	int counter = 0;
	printAll();
	for (int i = 0;;)
	{
		gotoXY(55, 13);
		system("color 9E");
		cout << "Music: \n";
		if (counter == 0) set[0] = 12;
		if (counter == 1) set[1] = 10;
		if (counter == 2) set[2] = 13;
		for (int j = 0; j < 3; j++)
		{
			gotoXY(55, 14 + j);
			SetColor(set[j]);
			cout << music[j];
		}
        int key = toupper(_getch());
        if ((key == UP_ARROW || key == 'W'))
        {
            tmp.playSelection();
            counter--;
            if (counter == -1)
                counter = 2;
        }
        if ((key == DOWN_ARROW || key == 'S'))
        {
            tmp.playSelection();
            counter++;
            if (counter == 3)
                counter = 0;
        }
		if (key == ENTER_KEY)
		{
            tmp.playSelection();
			if (counter == 0)
			{
				MusicMode = 1;
				tmp.newPLay();
			}
			if (counter == 1)
			{
				MusicMode = 0;
				tmp.close();
			}
			if (counter == 2)
			{
				system("cls");
				system("color F2");
				printAll();
				break;
			}
		}
		for (int l = 0; l < 3; l++) set[l] = 7;
	}
}

void Menu::menu()
{
	system("cls");
	SetConsoleTitle(L"Over: The Mysterious City");
	
	string Menu[] = { "  Play Game  ","  Load Game  "," Instruction ","   Setting   ","  Quit Game  " };
	int set[] = { 7,7,7,7,7 };
	int counter = 1;

	game* cg = new game();
	char key;
	system("color F5");
	printAll();

	for (int i = 0;;)
	{
		Music sel;
		if (counter == 1) set[0] = 12;
		if (counter == 2) set[1] = 9;
		if (counter == 3) set[2] = 12;
		if (counter == 4) set[3] = 9;
		if (counter == 5) set[4] = 12;
		for (int j = 0; j < 5; j++)
		{
			gotoXY(55, 13 + j);
			color(0, set[j]);
			cout << Menu[j];
		}

        key = toupper(_getch());
        if (key == UP_ARROW || key == 'W')
        {
            sel.playSelection();
            counter--;
            if (counter == 0)
                counter = 5;
        }
        if (key == DOWN_ARROW || key == 'S')
        {
            sel.playSelection();
            counter++;
            if (counter == 6)
                counter = 1;
        }
		if (key == ENTER_KEY)
		{
			sel.playSelection();
			system("cls");
			if (counter == 1)
			{
				cg->NewPlayer();
				break;
			}
			if (counter == 2)
			{
				cg->LoadFile();
				break;
			}
			if (counter == 3)
			{
				Instructions();
				break;
			}
			if (counter == 4)
			{
				system("cls");
				settings();
			}
			if (counter == 5)
			{
				isRunning = false;
				exit(0);
				return;
			}
		}
		for (int l = 0; l < 5; l++) set[l] = 7;
	}

}

void Menu::Instructions()
{
	color(15, 13);
	system("cls");	
	printTitle();
	SetConsoleOutputCP(437);
	color(15, 0);
	box(25, 13, 76, 11);

	color(15, 0);
	gotoXY(28, 16);
	cout << "Movement: Use WASD or arrow keys to move";
	Sleep(200);

	color(15, 0);
	gotoXY(28, 17);
	cout << "Gameplay: Avoid the obstacles and make it to the other side of the road";
	Sleep(200);

	color(15, 0);
	gotoXY(28, 18);
	cout << "The faster you make it, the higher the points will be";
	Sleep(200);

	color(15, 0);
	gotoXY(37, 21);
	cout << "------Press ESC to get back to main menu------";

	char key = _getch();
	if (key == 27)
	{
		SetConsoleOutputCP(65001);
		menu();
	}
}