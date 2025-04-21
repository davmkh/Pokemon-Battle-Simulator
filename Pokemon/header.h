#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Moves (will be called in Pokemon class)
typedef struct pokemonMove {
	string name;
	string type;
	int damage;
	int accuracy; // will implement after beta version of game
};
