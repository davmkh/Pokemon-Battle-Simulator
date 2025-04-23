#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Menu
{
public:
	Menu();
	bool MainMenu();
	void handleEvents(sf::RenderWindow& window);
};

