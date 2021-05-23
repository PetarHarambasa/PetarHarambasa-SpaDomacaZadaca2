#include "game_of_life.h"
#include <iostream>
#include <windows.h>

int main()
{

	game_of_life the_game;

	/*bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);
	*/
	bool dalje;

	while (true)
	{
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		Sleep(500);
		system("cls");
	}
	return 0;
}