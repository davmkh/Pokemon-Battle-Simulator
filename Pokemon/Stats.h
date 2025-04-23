#pragma once
#include "header.h"

class Stats {
private:
	// tracks user data
	int wins;
	int losses;
	int roundsPlayed;

	string name; // allows player to set name

public:
	// constructor
	Stats(int Wins, int Losses, int RoundsPlayed);
	
	// triggers at the end of a match
	void incrementWins();
	void incrementLosses();
	void incrementRoundsPlayed();

	// getters
	int getWins();
	int getLosses();
	int getRoundsPlayed();

	// file handling functions
	void loadStats();
	void saveStats();




};

