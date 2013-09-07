#pragma once

//#ifndef _AFX_H_
//#define _AFX_H_
//#include <afx.h>
//#endif

#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>

#include "controls.h"

extern mainWindowControls *_mainWindowControls;
class commanderList;
TCHAR* bufftrim(TCHAR buff[], int len);
int bufftoi(TCHAR buff[]);

class commander
{
public:

	commander(TCHAR name[], int a, int d, int hp);
	commander(int, commanderList* p_commanderList);
	~commander();
	int getNameLength();

	int attackBonus;
	int defenseBonus;
	int hpBonus;

	TCHAR bName[60];
	TCHAR bAttackBonus[3];
	TCHAR bDefenseBonus[3];
	TCHAR bHPBonus[3];

	//CString csName;
	//CString csAttackBonus;
	//CString csDefenseBonus;
	//CString csHPBonus;
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
	bool saveCommander(TCHAR name[], int a, int d, int hp);
	bool saveList();
};