#include "unit_commanders.h"


commander::commander(CString name, int a, int d, int hp)
{
	attackBonus = a;
	defenseBonus = d;
	hpBonus = hp;

	csName = name;

	csAttackBonus.Format("%d\n", attackBonus);
	csDefenseBonus.Format("%d\n", defenseBonus);
	csHPBonus.Format("%d\n", hpBonus);
}

commander::commander(int a, commanderList *p_commanderList)
{
	attackBonus = p_commanderList->commanderVector.at(a)->attackBonus;
	defenseBonus = p_commanderList->commanderVector.at(a)->defenseBonus;
	hpBonus = p_commanderList->commanderVector.at(a)->hpBonus;
	
	csName = p_commanderList->commanderVector.at(a)->csName;

	csAttackBonus.Format("%d\n", attackBonus);
	csDefenseBonus.Format("%d\n", defenseBonus);
	csHPBonus.Format("%d\n", hpBonus);
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
			char name[50], nums[6];
			memset(name, ' ', 50);
			memset(nums, '0', 6);
			int attack = 0, defense = 0, hp = 0;

			//read one line
			fCommanderList.read(name, 50);
			fCommanderList.read(nums, 6);

			//convert to CString and trim
			CString csName(name, 50);
			csName.TrimRight(); 
		
			//convert to ints
			attack = ((nums[0] - '0') * 10) + (nums[1] - '0');
			defense = ((nums[2] - '0') * 10) + (nums[3] - '0');
			hp = ((nums[4] - '0') * 10) + (nums[5] - '0');

			commander* p_commander = new commander(csName, attack, defense, hp);
			commanderVector.push_back(p_commander);
		}

		fCommanderList.close();	
		
	}//end of if (fCommanderList.is_open())
	else 
	{
		MessageBox(NULL, "Failed to open file.", "ERROR", MB_OK | MB_ICONERROR);
	}
}

commanderList::~commanderList()
{
	// MOVED TO SEPRATE FUNCTION
	/*
	fListBackup.open("comm_back.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in);

	//Create backup
	if (fListBackup.is_open() && fCommanderList.is_open())
	{
		char buff[56];
		fCommanderList.seekg(0,std::ios::beg);
		fListBackup.seekg(0,std::ios::beg);
		while (!fCommanderList.eof())
		{
			memset(buff, ' ', 56);
			fCommanderList.read(buff, 56);
			fListBackup.write(buff, 56);
		}
		fListBackup.close();
		fCommanderList.close();//close out and reset state flags
	}
	else
	{
		MessageBox(NULL, "Failed to open one or more files.", "ERROR", MB_OK | MB_ICONERROR);
	}

	//save commanders
	fListBackup.open("commanders.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	if (fCommanderList.is_open())
	{
		for (iter = commanderVector.begin(); iter != commanderVector.end(); iter++)
		{
			char buff[56];
			memset(buff, ' ', 56);
			int len = (*iter)->sName.GetLength();

			for (int i = 0; i <= len; ++i)
			{
				buff[i] = (*iter)->sName[i];
			}//end of inner FOR loop

			buff[51] = (*iter)->sAttackBonus[0];
			buff[52] = (*iter)->sAttackBonus[1];
			buff[53] = (*iter)->sDefenseBonus[0];
			buff[54] = (*iter)->sDefenseBonus[1];
			buff[55] = (*iter)->sHPBonus[0];
			buff[56] = (*iter)->sHPBonus[1];

			fCommanderList.write(buff, 56);
		}//end of outer FOR loop
		fCommanderList.close();

	
	}
	else
	{
		MessageBox(NULL, "Failed to open file: commanders.bin.", "ERROR", MB_OK | MB_ICONERROR);
	}
	*/
}

bool commanderList::saveList()
{
	fListBackup.open("comm_back.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in);

	//Create backup
	if (fListBackup.is_open() && fCommanderList.is_open())
	{
		char buff[56];
		fCommanderList.seekg(0,std::ios::beg);
		fListBackup.seekg(0,std::ios::beg);
		while (!fCommanderList.eof())
		{
			memset(buff, ' ', 56);
			fCommanderList.read(buff, 56);
			fListBackup.write(buff, 56);
		}
		fListBackup.close();
		fCommanderList.close();//close out and reset state flags
	}
	else
	{
		MessageBox(NULL, "Failed to open one or more files.", "ERROR", MB_OK | MB_ICONERROR);
	}

	//save commanders
	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::out | std::ios::trunc);

	if (fCommanderList.is_open())
	{
		fCommanderList.seekg(0, std::ios::beg);
		for (iter = commanderVector.begin(); iter != commanderVector.end(); iter++)
		{
			char buff[60];
			memset(buff, ' ', 56);
			int len = (*iter)->csName.GetLength();

			for (int i = 0; i < len; ++i)
			{
				buff[i] = (*iter)->csName[i];
			}//end of inner FOR loop

			buff[51] = (*iter)->csAttackBonus[0];
			buff[52] = (*iter)->csAttackBonus[1];
			buff[53] = (*iter)->csDefenseBonus[0];
			buff[54] = (*iter)->csDefenseBonus[1];
			buff[55] = (*iter)->csHPBonus[0];
			buff[56] = (*iter)->csHPBonus[1];

			fCommanderList.write(buff, 56);
		}//end of outer FOR loop
		MessageBox(NULL, "List Saved.", "saved", MB_OK);
	}
	else
	{
		MessageBox(NULL, "Failed to open file: commanders.bin.", "ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}
	fCommanderList.close();
	return 1;
}

bool commanderList::saveCommander(CString name, int a, int d, int hp)
{
	commander* p_commander = new commander(name, a, d, hp);
	commanderVector.push_back(p_commander);

	//update combo boxes
	SendMessage(_mainWindowControls->hLeftCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->csName.GetBuffer());
	SendMessage(_mainWindowControls->hRightCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->csName.GetBuffer());
	SendMessage(_mainWindowControls->hEditCommanderName,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) p_commander->csName.GetBuffer());

	MessageBox(NULL, "Commander Saved...", "Saved", MB_OK);

	return 1;
}