#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class game_of_life
{
private:
	char ALIVE = '*';
	char DEAD = '-';
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	int rand_life();
	void kutovi(int i, int j, int& count_alive);
	void prvi_redak(int i, int j, int& count_alive);
	void rubovi_lijevo_desno(int i, int j, int& count_alive);
	void sredina(int i, int j, int& count_alive);
	void zadnji_redak(int i, int j, int& count_alive);


public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

