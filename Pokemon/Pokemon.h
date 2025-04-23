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
	int level;


	// moveset (up to and maximum 4)
	pokemonMove move1;
	pokemonMove move2;
	pokemonMove move3;
	pokemonMove move4;

	bool fainted;

public:
	// constructor + destructor
	Pokemon(string n, string t1, string t2, int hp, int atk, int def, int spd, pokemonMove moveOne, 
		pokemonMove moveTwo, pokemonMove moveThree, pokemonMove moveFour);
	virtual ~Pokemon();

	// setters
	void setHitpoints(int Hitpoints);
	void setAttack(int Attack);
	void setDefense(int Defense);
	void setSpeed(int Speed);
	void setFainted(bool newStatus);

	// might have to add more setters/getters

	// getters
	int getHitpoints();
	int getAttack();
	int getDefense();
	int getSpeed();
	string getType1();
	string getType2();

	bool getFaintedStatus();

	void attackTarget(Pokemon& target, int moveNumber); //Attack function that passes in the target address and the move number 


};


