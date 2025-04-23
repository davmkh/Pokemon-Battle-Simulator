#include "header.h"
#include "Pokemon.h"

class Team
{
private:
	Pokemon* team[3]; //fixed team array of 3 pokemon
	Pokemon* activePokemon; //Which pokemon is currently in use
	int activePokemonIndex; //either set to 0, 1, or 2 to track active team member
public:
	Team(Pokemon* member1, Pokemon* member2, Pokemon* member3); //constructor that passes 3 members of team

	void setActivePokemon(int index);

	Pokemon* getActive();

	Pokemon* getMember(int index);

	int getActiveIndex();

	bool allFainted();
};