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

bool Team::addPokemon(Pokemon* selected)
{
	for (int i = 0; i < 3; ++i)
	{
		if (team[i] == nullptr)
		{
			team[i] = selected;

			if (activePokemon == nullptr)
			{
				activePokemon = selected;
				activePokemonIndex = i;
			}

			return true;
		}
	}
	return false;
}

void Team::generateRandomTeam()
{
	for (int i = 0; i < 3; ++i)
	{
		Pokemon* current = nullptr;
		int randomPokemon = (rand() % 10) + 1;
		switch (randomPokemon)
		{
		case 1: //pikachu
			current = new Pikachu();
			break;
		case 2: //charizard
			current = new Charizard();
			break;
		case 3: //venasaur
			current = new Venasaur();
			break;
		case 4: //blastoise
			current = new Blastoise();
			break;
		case 5: //abomasnow
			current = new Abomasnow();
			break;
		case 6: //gengar
			current = new Gengar();
			break;
		case 7: //darkrai
			current = new Darkrai();
			break;
		case 8: //lucario
			current = new Lucario();
			break;
		case 9: //metagross
			current = new Metagross();
			break;
		case 10: //mewtwo
			current = new Mewtwo();
			break;
		}
	}
}
