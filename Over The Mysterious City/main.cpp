#include "console.h"
#include "menu.h"
#include "game.h"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Console console;
	console.initGame();

	Menu men;
	men.menu();

	return 0;
}