#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	return !(rand_life() | rand_life() | rand_life());
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

int game_of_life::rand_life()
{
	return rand() & 1;
}

void game_of_life::kutovi(int i, int j, int& count_alive)
{
	//GORNJI LIJEVI KUT
	if (i == 0 && j == 0)
	{
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//GORNJI LIJEVI KUT

	//GORNJI DESNI KUT
	if (i == 0 && j == STUPACA - 1)
	{
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//GORNJI DESNI KUT

	//DONJI LIJEVI KUT
	if (i == REDAKA - 1 && j == 0)
	{
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] == 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//DONJI LIJEVI KUT

	//DONJI DESNI KUT
	if (i == REDAKA - 1 && j == STUPACA - 1)
	{
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//DONJI DESNI KUT
}

void game_of_life::prvi_redak(int i, int j, int& count_alive)
{
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
			}
		if (celija_zauzeta(i + 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
}

void game_of_life::rubovi_lijevo_desno(int i, int j, int& count_alive)
{
	//LIJEVI RUB
	if ((i > 0 || i < REDAKA - 1) && j == 0)
	{
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//LIJEVI RUB

	//DESNI RUB
	if ((i > 0 || i < REDAKA - 1) && j == STUPACA - 1)
	{
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}//DESNI RUB
}

void game_of_life::sredina(int i, int j, int& count_alive)
{
		if (celija_zauzeta(i - 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i + 1, j + 1))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive > 3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
}

void game_of_life::zadnji_redak(int i, int j, int& count_alive)
{
		if (celija_zauzeta(i, j - 1))
		{
			++count_alive;
		}

		if (celija_zauzeta(i - 1, j - 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j))
		{
			++count_alive;
		}
		if (celija_zauzeta(i - 1, j + 1))
		{
			++count_alive;
		}
		if (celija_zauzeta(i, j + 1))
		{
			++count_alive;
		}

		if (_generacija[i][j] == 1 && (2 > count_alive || count_alive >3))
		{
			_sljedeca_generacija[i][j] = 0;
		}
		else if (_generacija[i][j] == 0 && count_alive == 3)
		{
			_sljedeca_generacija[i][j] = 1;
		}
		else
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
}


game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if (slucajna_vrijednost())
			{
				_generacija[i][j] = true;
			}
			else
			{
				_generacija[i][j] = false;
			}
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			int count_alive = 0;

			if ((i == 0 && j == 0) || (i == 0 && j == STUPACA - 1) || (i == REDAKA - 1 && j == 0) || (i == REDAKA - 1 && j == STUPACA - 1))
			{
				kutovi(i, j, count_alive);
			}
			else if (i == 0 && (j > 0 || j < STUPACA - 1))
			{
				prvi_redak(i, j, count_alive);
			}
			else if ((i > 0 && i < REDAKA - 1) && (j == 0 || j == STUPACA - 1))
			{
				rubovi_lijevo_desno(i, j, count_alive);
			}
			else if ((i > 0 || i < REDAKA - 1) && (j > 0 || j < STUPACA - 1))
			{
				sredina(i, j, count_alive);
			}
			else if (i == REDAKA - 1 && (j > 0 || j < STUPACA - 1))
			{
				zadnji_redak(i, j, count_alive);
			}
		}
	}

	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << ALIVE;
			}
			else
			{
				cout << DEAD;
			}
		}
		cout << endl;
	}
}
