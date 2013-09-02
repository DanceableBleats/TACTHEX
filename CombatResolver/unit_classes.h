#pragma once

enum UNIT_CLASS
{
SWORDSMAN = 1,
PIKEMAN,
PIKEMAN_BONUS,
ARCHER,
CAVALRY,
CAVALRY_BONUS,
FLYER,
FLYER_BONUS,
UNDEAD,
BANDIT
};


class unit 
{
public:
	unit(UNIT_CLASS);
	~unit();

	int attack;
	int defense;
	int hp;

	



};