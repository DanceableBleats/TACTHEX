#pragma once

#include <afx.h>


enum UNIT_CLASS
{
	BLANK = 0,
	SWORDSMAN,
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

	CString sAttack;
	CString sDefense;
	CString sHP;

	
};