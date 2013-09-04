#pragma once

#ifndef _AFX_H_
#define _AFX_H_
#include <afx.h>
#endif

#include <vector>
#include <iostream>
#include <fstream>


class commander
{
public:

	commander(CString csName, int a, int d, int hp);
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
	std::vector<commander*>::iterator iter;

	std::fstream fCommanderList;
	std::fstream fListBackup;


	bool checkExists();
	bool saveCommander();
};