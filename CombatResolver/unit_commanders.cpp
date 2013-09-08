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
	
	fCommanderList = CreateFile(L"commanders.bin",		
                       GENERIC_READ,					
                       0,								
                       NULL,							
                       OPEN_EXISTING,					
                       FILE_ATTRIBUTE_NORMAL,			
                       NULL);							
	if (fCommanderList == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"Unable to open file: commanders.bin.", L"ERROR", NULL);
	}


	TCHAR buffer[60];
	DWORD  dwBytesRead = 0;
	if (ReadFile(fCommanderList, buffer, 56, &dwBytesRead, NULL) == FALSE);
	{
		MessageBox(NULL, L"Unable to read from file.", L"ERROR", NULL);
	}

	if (dwBytesRead == 56)
	{
		int attack = bufftoi(&buffer[50], 2);
		int defense = bufftoi(&buffer[52], 2);
		int hp = bufftoi(&buffer[54], 2);

		TCHAR *p_name = bufftrim(buffer, 50);

		commander* p_commander = new commander(p_name, attack, defense, hp);
		commanderVector.push_back(p_commander);

	}
	else if (dwBytesRead > 0 && dwBytesRead < 56)
	{
		MessageBox(NULL, L"Corrupt line, less than 56 characters read", L"ERROR", NULL);
	}

	CloseHandle(fCommanderList);


//	//std::fstream fCommanderList;  //moved to header
//	
//	fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in | std::ios::out);
//	if (fCommanderList.is_open())
//	{
//		//place pointer at beginning of file
//		fCommanderList.seekg(0,std::ios::beg);
//
//		while (!fCommanderList.eof())
//		{
//			TCHAR name[50], att[3], def[3], bhp[3];
//			memset(name, ' ', 50);
//			int attack = 0, defense = 0, hp = 0;
//MessageBox(NULL, L"Breakpoint.", L"breakpoint", NULL);
//			//read one line
//			fCommanderList.read(name, 50);
//			fCommanderList.read(att, 2);
//			fCommanderList.read(def, 2);
//			fCommanderList.read(hp, 2);
//
//			//trim
//			TCHAR *p_buff = bufftrim(name, 50);
//		
//			//convert to ints
//			att[2] = '\0';
//			def[2] = '\0';
//			bhp[2] = '\0';
//			attack = bufftoi(att);
//			defense = bufftoi(def);
//			hp = bufftoi(bhp);
//
//			commander* p_commander = new commander(p_buff, attack, defense, hp);
//			commanderVector.push_back(p_commander);
//		}
//
//		fCommanderList.close();	
//		
//	}//end of if (fCommanderList.is_open())
//	else 
//	{
//		MessageBox(NULL, L"Failed to open file.", L"ERROR", MB_OK | MB_ICONERROR);
//	}
//	MessageBox(NULL, L"Breakpoint 2.", L"breakpoint 2", NULL);
}

commanderList::~commanderList()
{

}

bool commanderList::saveList()
{
	//DeleteFile(L"comm_back.bin"); <--false param below specifies overwrite if exists.
	if (CopyFile(L"commanders.bin", L"comm_back.bin", FALSE) == FALSE)
	{
		MessageBox(NULL, L"Unable to create backup comm_back.bin", L"ERROR", NULL);
	}


	//fListBackup.open("comm_back.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	//fCommanderList.open("commanders.bin", std::ios::binary | std::ios::in);



	//save commanders
	fCommanderList = CreateFile(L"commanders.bin",		
                       GENERIC_WRITE,					
                       0,								
                       NULL,							
                       OPEN_EXISTING,					
                       FILE_ATTRIBUTE_NORMAL,			
                       NULL);							
	if (fCommanderList == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"Unable to open file: commanders.bin.", L"ERROR", NULL);
		return 0;
	}
	else
	{
		if (!commanderVector.empty())
		{
			for (iter = commanderVector.begin(); iter != commanderVector.end(); iter++)
			{
				TCHAR buff[60];
				memset(buff, ' ', 56);
			
				int len = (*iter)->getNameLength();

	MessageBox(NULL, L"Breakpoint 1.", L"Breakpoint", NULL);
				for (int i = 0; i < len; ++i)
				{
					buff[i] = (*iter)->bName[i];
				}//end of inner FOR loop
				buff[50] = (*iter)->bAttackBonus[0];
				buff[51] = (*iter)->bAttackBonus[1];
				buff[52] = (*iter)->bDefenseBonus[0];
				buff[53] = (*iter)->bDefenseBonus[1];
				buff[54] = (*iter)->bHPBonus[0];
				buff[55] = (*iter)->bHPBonus[1];
	MessageBox(NULL, L"Breakpoint 2.", L"Breakpoint", NULL);
				DWORD dwBytesWritten;
				DWORD dwBytesToWrite = 56;
				MessageBox(NULL, L"Breakpoint 3.", L"Breakpoint", NULL);
				if (FALSE == WriteFile( 
								fCommanderList,				// open file handle
								buff,						// start of data to write
								dwBytesToWrite,				// number of bytes to write
								&dwBytesWritten,			// number of bytes that were written
								NULL));						// no overlapped structure
				{
					MessageBox(NULL, L"Error: unable to write to commanders.bin.", L"ERROR", NULL);
					return 0;
				}

			}//end of for
		}//end of IF !commanderVector.empty()
		return 1;
	}

//
//	if (fCommanderList.is_open())
//	{
//		fCommanderList.seekg(0, std::ios::beg);
//		for (iter = commanderVector.begin(); iter != commanderVector.end(); iter++)
//		{
//			TCHAR buff[60];
//			memset(buff, ' ', 56);
//			int len = (*iter)->getNameLength();
//
//			for (int i = 0; i < len; ++i)
//			{
//				buff[i] = (*iter)->bName[i];
//			}//end of inner FOR loop
//
//			buff[51] = (*iter)->bAttackBonus[0];
//			buff[52] = (*iter)->bAttackBonus[1];
//			buff[53] = (*iter)->bDefenseBonus[0];
//			buff[54] = (*iter)->bDefenseBonus[1];
//			buff[55] = (*iter)->bHPBonus[0];
//			buff[56] = (*iter)->bHPBonus[1];
//
//			fCommanderList.write((char*)buff, 56);
//		}//end of outer FOR loop
//		MessageBox(NULL, L"List Saved.", L"saved", MB_OK);
//	}
//	else
//	{
//		MessageBox(NULL, L"Failed to open file: commanders.bin.", L"ERROR", MB_OK | MB_ICONERROR);
//		return 0;
//	}
//	fCommanderList.close();
//	return 1;
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