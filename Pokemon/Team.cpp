#include "Team.h"

Team::Team(Pokemon* member1, Pokemon* member2, Pokemon* member3)
{
	team[0] = member1;
	team[1] = member2;
	team[2] = member3;
	activePokemon = team[0];
	activePokemonIndex = 0;
}

void Team::setActivePokemon(int index)
{
	if (index >= 0 && index < 3 && team[index]->getHitpoints() > 0)
	{
		activePokemon = team[index];
		activePokemonIndex = index;
	}
}

Pokemon* Team::getActive()
{
	return activePokemon;
}

Pokemon* Team::getMember(int index)
{
	if (index >= 0 && index < 3)
	{
		return team[index];
	}
	return nullptr;
}

int Team::getActiveIndex()
{
	return activePokemonIndex;
}

bool Team::allFainted()
{
	for (int i = 0; i < 3; ++i)
	{
		if (!team[i]->getFaintedStatus())
		{
			return false;
		}
	}
	return true;
}

bool Team::switchPokemon(int index)
{
	if (index < 0 || index > 3) //out of bound error
	{
		return false;
	}

	if (index == activePokemonIndex) //already active pokemon
	{
		return false;
	}

	if (team[index]->getFaintedStatus()) //pokemon at passed index is fainted
	{
		return false;
	}

	//all checks have been passed, will now switch
	activePokemon = team[index];
	activePokemonIndex = index;
	return true;
}
