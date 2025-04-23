#include "Pokemon.h"

// constructor + destructor definitions //
Pokemon::Pokemon(string n, string t1, string t2, int hp, int atk, int def, int spd, pokemonMove moveOne, pokemonMove moveTwo, pokemonMove moveThree, pokemonMove moveFour) {
	name = n;
	type1 = t1;
	type2 = t2;
	hitpoints = hp;
	level = 100;
	attack = atk;
	defense = def;
	speed = spd;
	move1 = moveOne;
	move2 = moveTwo;
	move3 = moveThree;
	move4 = moveFour;
}

Pokemon::~Pokemon() {
	cout << " has fainted!" << endl;
}

// setters definitons //
void Pokemon::setHitpoints(int Hitpoints) {
	hitpoints = Hitpoints;
}

void Pokemon::setAttack(int Attack) {
	attack = Attack;
}

void Pokemon::setDefense(int Defense) {
	defense = Defense;
}

void Pokemon::setSpeed(int Speed) {
	speed = Speed;
}

// getters definitions //
int Pokemon::getHitpoints() {
	return hitpoints;
}

int Pokemon::getAttack() {
	return attack;
}

int Pokemon::getDefense() {
	return defense;
}

int Pokemon::getSpeed() {
	return speed;
}

string Pokemon::getType1()
{
	return type1;
}

string Pokemon::getType2()
{
	return type2;
}

void Pokemon::attackTarget(Pokemon& target, int moveNumber)
{
	pokemonMove selectedMove;

	switch (moveNumber)
	{
	case 1: selectedMove = move1;
		break;
	case 2: selectedMove = move2;
		break;
	case 3: selectedMove = move3;
		break;
	case 4: selectedMove = move4;
		break;
	}

	//display message
	cout << name << " uses " << selectedMove.name << "!" << endl;

	//copy target types
	string t1 = target.getType1();
	string t2 = target.getType2();

	//calculate effectiveness multiplier
	double multiplier = 1.0;
	multiplier = calcMultiplier(t1, selectedMove.type, multiplier);
	if (!t2.empty())
	{
		multiplier = calcMultiplier(t2, selectedMove.type, multiplier);
	}

	int damageDone = ((selectedMove.damage * attack) / target.getDefense()) * multiplier;
	int newHP = target.getHitpoints() - damageDone;// calc new hitpoints
	newHP = (newHP < 0) ? 0 : newHP; //is newHP less than 0? if yes, set back to zero

	target.setHitpoints(newHP);

	if (multiplier == 0)
	{
		cout << "It has no effect!" << endl;
	}
	else if (multiplier > 1)
	{
		cout << "It's super effective!" << endl;
	}
	else if (multiplier < 1)
	{
		cout << "It's not very effective..." << endl;
	}
}

