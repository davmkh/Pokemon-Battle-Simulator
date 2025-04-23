#include "Stats.h"

Stats::Stats(int Wins, int Losses, int RoundsPlayed) {
	wins = Wins;
	losses = Losses;
	roundsPlayed = RoundsPlayed;
}

// increment functions
void Stats::incrementWins() {
	wins++;
}

void Stats::incrementLosses() {
	losses++;
}

void Stats::incrementRoundsPlayed() {
	roundsPlayed++;
}

// getters
int Stats::getWins() {
	return wins;
}

int Stats::getLosses() {
	return losses;
}

int Stats::getRoundsPlayed() {
	return roundsPlayed;
}

// file handling functions with Stats.txt
void Stats::loadStats() {
	
}

void Stats::saveStats() {

}

