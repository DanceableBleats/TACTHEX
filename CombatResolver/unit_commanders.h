#pragma once

#ifndef _AFX_H_
#define _AFX_H_
#include <afx.h>
#endif

#include <vector>
#include <iostream>
#include <fstream>

#include "controls.h"

extern mainWindowControls *_mainWindowControls;
class commanderList;

class commander
{
public:

	commander(CString csName, int a, int d, int hp);
	commander(int, commanderList* p_commanderList);
	~commander();

	int attackBonus;
	int defenseBonus;
	int hpBonus;

	CString csName;
	CString csAttackBonus;
	CString csDefenseBonus;
	CString csHPBonus;
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
	bool saveCommander(CString name, int a, int d, int hp);
	bool saveList();
};