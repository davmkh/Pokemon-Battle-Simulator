#pragma once
#include "header.h"

class Pokemon {
private:
	// pokemon name
	string name;

	// pokemon type
	string type1;
	string type2; // if non-dual type, set to null

	// stats
	int hitpoints;
	int attack;
	int defense;
	int speed;

	// Moves (will be called in Pokemon class)
	typedef struct move {
		string name;
		string type;
		int damage;
		int accuracy; // will implement after beta version of game
	};

	// moveset (up to and maximum 4)
	move move1;
	move move2;
	move move3;
	move move4;

public:
	// constructor + destructor
	Pokemon();
	~Pokemon();

	// 
};


