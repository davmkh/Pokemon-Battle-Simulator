#pragma once
#include "header.h"
#include "Pokemon.h"

// Pikachu - Electric
class Pikachu : public Pokemon {
public:
	Pikachu()
		: Pokemon("Pikachu", "ELECTRIC", "", 200, 160, 115, 245,
			{ "Thunderbolt", "ELECTRIC", 90, 100 },
			{ "Quick Attack", "NORMAL", 40, 100 },
			{ "Iron Tail", "STEEL", 100, 75 },
			{ "Surf", "WATER", 90, 100 }) {}
};

// Charizard - Fire/Flying
class Charizard : public Pokemon {
public:
	Charizard()
		: Pokemon("Charizard", "FIRE", "FLYING", 266, 198, 168, 205,
			{ "Flamethrower", "FIRE", 90, 100 },
			{ "Air Slash", "FLYING", 75, 95 },
			{ "Dragon Claw", "DRAGON", 80, 100},
			{ "Slash", "NORMAL", 70, 100}) {}
};

// Venasaur - Grass/Poison
class Venasaur : public Pokemon {
public:
	Venasaur()
		: Pokemon("Venasaur", "GRASS", "POISON", 270, 187, 188, 165,
			{ "Razor Leaf", "GRASS", 55, 100 },
			{ "Sludge Bomb", "POISON", 90, 100 },
			{ "Earthquake", "GROUND", 100, 100 },
			{ "Vine Whip", "GRASS", 45, 100 }) {}
};

// Blastoise - Water
class Blastoise : public Pokemon {
public:
	Blastoise()
		: Pokemon("Blastoise", "WATER", "", 268, 173, 210, 161,
			{ "Hydro Pump", "WATER", 110, 80 },
			{ "Ice Beam", "ICE", 90, 100 },
			{ "Bite", "DARK", 60, 100 },
			{ "Skull Bash", "NORMAL", 130, 100}) {}
};

// Abomasnow - Ice/Grass
class Abomasnow : public Pokemon {
public:
	Abomasnow()
		: Pokemon("Abomasnow", "GRASS", "ICE", 290, 189, 165, 125,
			{ "Blizzard", "ICE", 110, 70 },
			{ "Razor Leaf", "GRASS", 55, 95 },
			{ "Ice Shard", "ICE", 40, 100 },
			{ "Earthquake", "GROUND", 100, 100}) {}
};

// Gengar - Ghost/Poison
class Gengar : public Pokemon {
public:
	Gengar()
		: Pokemon("Gengar", "GHOST", "POISON", 230, 200, 145, 225,
			{ "Shawdow Ball", "GHOST", 80, 100 },
			{ "Sludge Bomb", "POISON", 90, 100 },
			{ "Dark Pulse", "DARK", 80, 100 },
			{ "Shadow Punch", "GHOST", 60, 100 }) {}
};

// Darkrai - Dark
class Darkrai : public Pokemon {
public:
	Darkrai()
		: Pokemon("Darkrai", "DARK", "", 250, 230, 185, 255,
			{ "Dark Pulse", "DARK", 80, 100 },
			{ "Shadow Ball", "GHOST", 80, 100 },
			{ "Dream Eater", "PSYCHIC", 100, 100 },
			{ "Payback", "DARK", 50, 100 }) {}
};

// Lucario - Fighting/Steel
class Lucario : public Pokemon {
public:
	Lucario()
		: Pokemon("Lucario", "FIGHTING", "STEEL", 250, 230, 145, 185,
			{ "Aura Sphere", "FIGHTING", 80, 100 },
			{ "Extreme Speed", "NORMAL", 80, 100 },
			{ "Low Kick", "FIGHTING", 50, 100 },
			{ "Meteor Mash", "STEEL", 90, 90 }) {}
};

// Metagross - Steel/Psychic
class Metagross : public Pokemon {
public:
	Metagross()
		: Pokemon("Metagross", "STEEL", "PSYCHIC", 270, 235, 225, 145,
			{ "Meteor Mash", "STEEL", 90, 90 },
			{ "Zen Headbutt", "PSYCHIC", 80, 90 },
			{ "Earthquake", "GROUND", 100, 100 },
			{ "Bullet Punch", "STEEL", 40, 100 }) {}
};

// Mewtwo - Pyschic
class Mewtwo : public Pokemon {
public:
	Mewtwo()
		: Pokemon("Mewtwo", "PSYCHIC", "", 322, 269, 185, 265,
			{ "Psychic", "PSYCHIC", 90, 100 },
			{ "Shadow Ball", "GHOST", 80, 100 },
			{ "Aura Sphere", "FIGHTING", 80, 100 },
			{ "Swift", "NORMAL", 60, 100 }) {}
};