#include "BattleSystem.h"

BattleSystem::BattleSystem(Team* t1, Team* t2)
{
	team1 = t1;
	team2 = t2;
}

void BattleSystem::battleTurn(int playerMoveIndex, int opponentMoveIndex)
{
	Pokemon* team1Active = team1->getActive(); //team 1 active pokemon
	Pokemon* team2Active = team2->getActive(); //team 2 active pokemon

	Pokemon* first; //Pointer to which pokemon will move first (higher speed stat)
	int firstMove; //Index of which move the faster pokemon chose
	Pokemon* second; //Pointer to pokemon that will move second (lower speed stat)
	int secondMove; //INdex of which move the slower pokemon chose

	if (team1Active->getSpeed() > team2Active->getSpeed()) //Player pokemon outspeeds
	{
		first = team1Active;
		firstMove = playerMoveIndex;
		second = team2Active;
		secondMove = opponentMoveIndex;
	}
	else if (team1Active->getSpeed() < team2Active->getSpeed()) //Opponent pokemon outspeeds
	{
		first = team2Active;
		firstMove = opponentMoveIndex;
		second = team1Active;
		secondMove = playerMoveIndex;
	}
	else //Speed stats are equal and will be randomized in case of speed tie
	{
		int tieBreaker = rand() % 2;
		if (tieBreaker == 0) //player 1 wins speed tie
		{
			first = team1Active;
			firstMove = playerMoveIndex;
			second = team2Active;
			secondMove = opponentMoveIndex;
		}
		else //opponent wins speed tie
		{
			first = team2Active;
			firstMove = opponentMoveIndex;
			second = team1Active;
			secondMove = playerMoveIndex;
		}
	}

	//now do attacks since move priority has been chosen

	first->attackTarget(*second, firstMove);

	if (!second->getFaintedStatus()) //if fainted returns as false
	{
		second->attackTarget(*first, secondMove);
	}
}

bool BattleSystem::isBattleFinished()
{
	if (team1->allFainted() || team2->allFainted())
	{
		return true;
	}
	return false;
}

Team* BattleSystem::getWinningTeam()
{
	if (team1->allFainted())
	{
		return team2;
	}
	if (team2->allFainted())
	{
		return team1;
	}
	return nullptr;
}

int BattleSystem::chooseBestMove(Pokemon* aiActive, Pokemon* target)
{
	int bestMoveIndex = 0;
	int maxDamage = 0;

	vector<pokemonMove> aiMoveList = { //vector of ai pokemon moves
		aiActive->getMove1(),
		aiActive->getMove2(),
		aiActive->getMove3(),
		aiActive->getMove4()
	};
	for (int i = 0; i < 4; ++i)
	{
		pokemonMove currentMove = aiMoveList[i];
		string currentMoveType = currentMove.type;
		int damage = currentMove.damage;

		double multiplier = 1.0;
		multiplier = calcMultiplier(target->getType1(), currentMoveType, multiplier);
		if (!target->getType2().empty())
		{
			multiplier = calcMultiplier(target->getType2(), currentMoveType, multiplier);
		}

		damage = ((currentMove.damage * aiActive->getAttack()) / target->getDefense()) * multiplier;

		if (damage > maxDamage)
		{
			maxDamage = damage;
			bestMoveIndex = i + 1;
		}
	}
	return bestMoveIndex;
}
