#include "unit_classes.h"

unit::unit(UNIT_CLASS u)
{
	switch (u)
	{
	case SWORDSMAN:
		{
			attack = 1;
			defense = 1;
			hp = 30;
		}//end of SWORDSMAN
	case PIKEMAN:
		{
			attack = 1;
			defense = 1;
			hp = 25;
		}//end of PIKEMNAN
	case PIKEMAN_BONUS:
		{
			attack = 2;
			defense = 2;
			hp = 25;
		}//end of PIKEMAN_BONUS
	case ARCHER:
		{
			attack = 1;
			defense = 0;
			hp = 25;
		}//end of ARCHER
	case CAVALRY:
		{
			attack = 1;
			defense = 1;
			hp = 25;
		}//end of CAVALRY
	case CAVALRY_BONUS:
		{
			attack = 2;
			defense = 1;
			hp = 25;
		}//end of CAVALRY_BONUS
	case FLYER:
		{
			attack = 1;
			defense = 1;
			hp = 20;
		}//end of FLYER
	case FLYER_BONUS:
		{
			attack = 2;
			defense = 0;
			hp = 20;
		}//end of FLYER_BONUS
	case UNDEAD:
		{
			attack = 0;
			defense = 0;
			hp = 25;
		}//end of UNDEAD
	case BANDIT:
		{
			attack = 1;
			defense = 0;
			hp = 25;
		}//end of BANDIT

	}//end of switch
}

/*
SWORDSMAN,
PIKEMAN,
PIKEMAN_BONUS,
ARCHER,
CAVALRY,
CAVALRY_BONUS,
FLYER,
FLYER_BONUS,
UNDEAD,
BANDIT\
*/

unit::~unit()
{
}
