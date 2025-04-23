#include "header.h"
#include "Team.h"

class BattleSystem
{
private:
	Team* team1;
	Team* team2;
public:
	BattleSystem(Team* t1, Team* t2);

	void battleTurn(int playerMoveIndex, int opponentMoveIndex);

	bool isBattleFinished();

	Team* getWinningTeam();

	int chooseBestMove(Pokemon* aiActive, Pokemon* target);
};