#pragma once
#include <Windows.h>


//#ifndef _AFX_H_
//#define _AFX_H_
//#include <afx.h>
//#endif

//forward
int bufftoi(TCHAR[]);



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

	TCHAR bAttack[3];
	TCHAR bDefense[3];
	TCHAR bHP[3];

	//CString sAttack;
	//CString sDefense;
	//CString sHP;

	
};