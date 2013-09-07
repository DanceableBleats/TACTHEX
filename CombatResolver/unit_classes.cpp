#include "unit_classes.h"

unit::unit(UNIT_CLASS u)
{
	switch (u)
	{
	case BLANK:
		{
			attack = 0;
			defense = 0;
			hp = 0;
			break;
		}
	case SWORDSMAN:
		{
			attack = 1;
			defense = 1;
			hp = 30;
			break;
		}//end of SWORDSMAN
	case PIKEMAN:
		{
			attack = 1;
			defense = 1;
			hp = 25;
			break;
		}//end of PIKEMNAN
	case PIKEMAN_BONUS:
		{
			attack = 2;
			defense = 2;
			hp = 25;
			break;
		}//end of PIKEMAN_BONUS
	case ARCHER:
		{
			attack = 1;
			defense = 0;
			hp = 25;
			break;
		}//end of ARCHER
	case CAVALRY:
		{
			attack = 1;
			defense = 1;
			hp = 25;
			break;
		}//end of CAVALRY
	case CAVALRY_BONUS:
		{
			attack = 3;
			defense = 1;
			hp = 25;
			break;
		}//end of CAVALRY_BONUS
	case FLYER:
		{
			attack = 1;
			defense = 1;
			hp = 20;
			break;
		}//end of FLYER
	case FLYER_BONUS:
		{
			attack = 3;
			defense = 0;
			hp = 20;
			break;
		}//end of FLYER_BONUS
	case UNDEAD:
		{
			attack = 0;
			defense = 0;
			hp = 25;
			break;
		}//end of UNDEAD
	case BANDIT:
		{
			attack = 1;
			defense = 0;
			hp = 25;
			break;
		}//end of BANDIT

	}//end of switch

	//sAttack.Format("%d\n", attack);
	//sDefense.Format("%d\n", defense);
	//sHP.Format("%d\n", hp);

	*bAttack = attack;
	*bDefense = defense;
	*bHP - hp;


	//MessageBox(NULL, TEXT("Created."), TEXT("Created."), MB_OK);

}


unit::~unit()
{
	//MessageBox(NULL, TEXT("Destroyed."), TEXT("Destroyed."), MB_OK);
}
