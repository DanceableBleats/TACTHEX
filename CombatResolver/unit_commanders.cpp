#include "unit_commanders.h"




commander::commander(TCHAR name[], int a, int d, int hp)
{
	attackBonus = a;
	defenseBonus = d;
	hpBonus = hp;

	*bName = *name;
	*bAttackBonus = a;
	*bDefenseBonus = d;
	*bHPBonus = hp;
}

commander::commander(int a, commanderList *p_commanderList)
{
	attackBonus = p_commanderList->commanderVector.at(a)->attackBonus;
	defenseBonus = p_commanderList->commanderVector.at(a)->defenseBonus;
	hpBonus = p_commanderList->commanderVector.at(a)->hpBonus;
	
	*bName = *p_commanderList->commanderVector.at(a)->bName;
	*bAttackBonus = *p_commanderList->commanderVector.at(a)->bAttackBonus;
	*bDefenseBonus = *p_commanderList->commanderVector.at(a)->bDefenseBonus;
	*bHPBonus = *p_commanderList->commanderVector.at(a)->bHPBonus;
}

commander::~commander()
{

}




commanderList::commanderList()
{
	//std::fstream fCommanderList;  //moved to header
	
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in | std::ios::out);
	if (fCommanderList.is_open())
	{
		//place pointer at beginning of file
		fCommanderList.seekg(0,std::ios::beg);

		while (!fCommanderList.eof())
		{
			TCHAR name[50], att[3], def[3], bhp[3];
			memset(name, ' ', 50);
			int attack = 0, defense = 0, hp = 0;
MessageBox(NULL, L"Breakpoint.", L"breakpoint", NULL);
			//read one line
			fCommanderList.read(name, 50);
			fCommanderList.read(att, 2);
			fCommanderList.read(def, 2);
			fCommanderList.read(hp, 2);

			//trim
			TCHAR *p_buff = bufftrim(name, 50);
		
			//convert to ints
			att[2] = '\0';
			def[2] = '\0';
			bhp[2] = '\0';
			attack = bufftoi(att);
			defense = bufftoi(def);
			hp = bufftoi(bhp);

			commander* p_commander = new commander(p_buff, attack, defense, hp);
			commanderVector.push_back(p_commander);
		}

		fCommanderList.close();	
		
	}//end of if (fCommanderList.is_open())
	else 
	{
		MessageBox(NULL, L"Failed to open file.", L"ERROR", MB_OK | MB_ICONERROR);
	}
	MessageBox(NULL, L"Breakpoint 2.", L"breakpoint 2", NULL);
}

commanderList::~commanderList()
{

}

bool commanderList::saveList()
{
	fListBackup.open("comm_back.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in);

	//Create backup
	if (fListBackup.is_open() && fCommanderList.is_open())
	{
		TCHAR buff[56];
		fCommanderList.seekg(0,std::ios::beg);
		fListBackup.seekg(0,std::ios::beg);
		while (!fCommanderList.eof())
		{
			memset(buff, ' ', 56);
			fCommanderList.read((char*)buff, 56);
			fListBackup.write((char*)buff, 56);
		}
		fListBackup.close();
		fCommanderList.close();//close out and reset state flags
	}
	else
	{
		MessageBox(NULL, L"Failed to open one or more files.", L"ERROR", MB_OK | MB_ICONERROR);
	}

	//save commanders
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::out | std::ios::trunc);

	if (fCommanderList.is_open())
	{
		fCommanderList.seekg(0, std::ios::beg);
		for (iter = commanderVector.begin(); iter != commanderVector.end(); iter++)
		{
			TCHAR buff[60];
			memset(buff, ' ', 56);
			int len = (*iter)->getNameLength();

			for (int i = 0; i < len; ++i)
			{
				buff[i] = (*iter)->bName[i];
			}//end of inner FOR loop

			buff[51] = (*iter)->bAttackBonus[0];
			buff[52] = (*iter)->bAttackBonus[1];
			buff[53] = (*iter)->bDefenseBonus[0];
			buff[54] = (*iter)->bDefenseBonus[1];
			buff[55] = (*iter)->bHPBonus[0];
			buff[56] = (*iter)->bHPBonus[1];

			fCommanderList.write((char*)buff, 56);
		}//end of outer FOR loop
		MessageBox(NULL, L"List Saved.", L"saved", MB_OK);
	}
	else
	{
		MessageBox(NULL, L"Failed to open file: commanders.bin.", L"ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}
	fCommanderList.close();
	return 1;
}

bool commanderList::saveCommander(TCHAR name[], int a, int d, int hp)
{
	commander* p_commander = new commander(name, a, d, hp);
	commanderVector.push_back(p_commander);

	//update combo boxes
	SendMessage(_mainWindowControls->hLeftCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->bName);
	SendMessage(_mainWindowControls->hRightCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->bName);
	SendMessage(_mainWindowControls->hEditCommanderName,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->bName);

	MessageBox(NULL, L"Commander Saved...", L"Saved", MB_OK);

	return 1;
}

int commander::getNameLength()
{
	int i = 0;
	while (bName[i] != '\0')
	{
		++i;
	}
	return i;
}