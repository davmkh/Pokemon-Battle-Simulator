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
	Pokemon(string n, string t1, string t2, int hp, int atk, int def, int spd, move moveOne, 
		move moveTwo, move moveThree, move moveFour);
	virtual ~Pokemon();

	// setters
	void setHitpoints(int Hitpoints);
	void setAttack(int Attack);
	void setDefense(int Defense);
	void setSpeed(int Speed);

	// might have to add more setters/getters

	// getters
	int getHitpoints();
	int getAttack();
	int getDefense();
	int getSpeed();


};


