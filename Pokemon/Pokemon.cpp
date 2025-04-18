#include "Pokemon.h"

// constructor + destructor definitions //
Pokemon::Pokemon(string n, string t1, string t2, int hp, int atk, int def, int spd, move moveOne, move moveTwo, move moveThree, move moveFour) {
	name = n;
	type1 = t1;
	type2 = t2;
	hitpoints = hp;
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

