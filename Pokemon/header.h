#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cstdlib> //rand()
#include <ctime> //time()
#include <vector>
#define FPS 60

using namespace std;

// Moves (will be called in Pokemon class)
struct pokemonMove {
	string name;
	string type;
	int damage;
	int accuracy; // will implement after beta version of game
};

double calcMultiplier(string targetType, string moveType, double multiplier);