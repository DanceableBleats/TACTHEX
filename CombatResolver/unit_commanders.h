#pragma once

#include <afx.h>
#include <vector>


class commander
{
public:

	commander();
	~commander();

	int attackBonus;
	int defenseBonus;
	int hpBonus;

	CString sName;
	CString sAttackBonus;
	CString sDefenseBonus;
	CString sHPBonus;
};



class commanderList
{
public:

	commanderList();
	~commanderList();

	std::vector<commander*> commanderVector;
};