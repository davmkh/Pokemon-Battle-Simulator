#include "header.h"

double calcMultiplier(string targetType, string moveType, double multiplier)
{
	if (moveType == "NORMAL") //normal type moves
	{
		if (targetType == "ROCK" || targetType == "STEEL") //resistance
		{
			multiplier *= 0.5;
		}
		else if (targetType == "GHOST") //no effect
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "FIRE") //fire type moves
	{
		if (targetType == "GRASS" || targetType == "ICE" || targetType == "BUG" || targetType == "STEEL") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "WATER" || targetType == "ROCK" || targetType == "DRAGON") //resistance
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "WATER") //water type moves
	{
		if (targetType == "FIRE" || targetType == "GROUND" || targetType == "ROCK") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "WATER" || targetType == "GRASS" || targetType == "DRAGON") //resistance
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "ELECTRIC") //electric type moves
	{
		if (targetType == "WATER" || targetType == "FLYING") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "ELECTRIC" || targetType == "GRASS" || targetType == "DRAGON") //resistance
		{
			multiplier *= 0.5;
		}
		else if (targetType == "GROUND") //no effect
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "GRASS") //grass type moves
	{
		if (targetType == "WATER" || targetType == "GROUND" || targetType == "ROCK") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "GRASS" || targetType == "POISON" || targetType == "FLYING" || targetType == "BUG" || targetType == "DRAGON" || targetType == "STEEL") //resistance
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "ICE") //ice type moves
	{
		if (targetType == "GRASS" || targetType == "GROUND" || targetType == "FLYING" || targetType == "DRAGON") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "WATER" || targetType == "ICE" || targetType == "STEEL") //resistance
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "FIGHTING") //fighting type moves
	{
		if (targetType == "NORMAL" || targetType == "ICE" || targetType == "ROCK" || targetType == "DARK" || targetType == "STEEL") //super effective
		{
			multiplier *= 2;
		}
		else if (targetType == "POISON" || targetType == "PSYCHIC" || targetType == "FLYING" || targetType == "BUG" || targetType == "FAIRY")
		{
			multiplier *= 0.5;
		}
		else if (targetType == "GHOST")
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "POISON") //poison type moves
	{
		if (targetType == "GRASS" || targetType == "FAIRY") //super 
		{
			multiplier *= 2;
		}
		else if (targetType == "POISON" || targetType == "GROUND" || targetType == "ROCK" || targetType == "GHOST")//not very
		{
			multiplier *= 0.5;
		}
		else if (targetType == "STEEL") //no effect
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "GROUND") //ground type moves
	{
		if (targetType == "FIRE" || targetType == "ELECTRIC" || targetType == "POISON" || targetType == "ROCK" || targetType == "STEEL") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "GRASS" || targetType == "BUG") //not very
		{
			multiplier *= 0.5;
		}
		else if (targetType == "FLYING")//no effect
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "FLYING") //flying types moves
	{
		if (targetType == "GRASS" || targetType == "FIGHTING" || targetType == "BUG") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "ELECTRIC" || targetType == "ROCK" || targetType == "STEEL") //not very
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "PSYCHIC") //psychic moves
	{
		if (targetType == "FIGHTING" || targetType == "POISON") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "PSYCHIC" || targetType == "STEEL")
		{
			multiplier *= 0.5;
		}
		else if (targetType == "DARK")
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "BUG") //bug moves
	{
		if (targetType == "GRASS" || targetType == "PSYCHIC" || targetType == "DARK") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "FLYING" || targetType == "POISON" || targetType == "FLYING" || targetType == "GHOST" || targetType == "STEEL" || targetType == "FAIRY") //not very
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "ROCK") //rock moves
	{
		if (targetType == "FIRE" || targetType == "ICE" || targetType == "FLYING" || targetType == "BUG") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "GROUND" || targetType == "STEEL") //not very
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "GHOST") //ghost moves
	{
		if (targetType == "GHOST" || targetType == "PSYCHIC") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "DARK")
		{
			multiplier *= 0.5;
		}
		else if (targetType == "NORMAL")
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "DRAGON") //dragon moves
	{
		if (targetType == "DRAGON") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "STEEL")
		{
			multiplier *= 0.5;
		}
		else if (targetType == "FAIRY")
		{
			multiplier *= 0;
		}
	}
	else if (moveType == "DARK") //dark moves
	{
		if (targetType == "PSYCHIC" || targetType == "GHOST") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "FIGHTING" || targetType == "DARK" || targetType == "FAIRY") //not very
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "STEEL") //steel moves
	{
		if (targetType == "ICE" || targetType == "ROCK" || targetType == "FAIRY") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "WATER" || targetType == "ELECTRIC" || targetType == "STEEL") //not very
		{
			multiplier *= 0.5;
		}
	}
	else if (moveType == "FAIRY") //fairy moves
	{
		if (targetType == "FIGHTING" || targetType == "DRAGON" || targetType == "DARK") //super
		{
			multiplier *= 2;
		}
		else if (targetType == "FIRE" || targetType == "POISON" || targetType == "STEEL") //not very
		{
			multiplier *= 0.5;
		}
	}
	return multiplier;
}