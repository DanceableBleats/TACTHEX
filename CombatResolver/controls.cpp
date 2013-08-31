#include "controls.h"

/*	// Create a push button                   BUTTON EXAMPLE!
	HWND hWndButton=CreateWindowEx(NULL,
		"BUTTON",
		"CLICK!",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		50,
		220,
		100,
		24,
		hWnd,
		(HMENU)BUTTON_1,
		GetModuleHandle(NULL),
		NULL);
	*/


int initControls(HWND hWnd)
{
	//Drop Down
	HWND hLeftComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		50, 
		50, 
		220, 
		20, 
		hWnd, 
		(HMENU)LEFT_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);

	TCHAR units[11][25] =  {TEXT("~"), TEXT("Swordsman~"), TEXT("Pikeman~"), TEXT("Pikeman (fortified)~"), TEXT("Archer~"),
		TEXT("Cavalry~"), TEXT("Cavalry (charging)~"), TEXT("Flyer~"), TEXT("Flyer (diving)~"), TEXT("Undead~"), TEXT("Bandit~")};
	TCHAR unitname[25]; 
	
	for (int i = 0; i < 11; ++i)
    {
        memset(&unitname,0,sizeof(unitname));
		int j = 0;
		while (units[i][j] != '~')
		{
			unitname[j] = units[i][j];
			++j;
		}


        // Add string to combobox.
        SendMessage(hLeftComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) unitname); 
    }
      
    // Send the CB_SETCURSEL message to display an initial item 
    //  in the selection field  
    SendMessage(hLeftComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);



	//stat boxes
	HWND hLeftAttack=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		50,
		100,
		60,
		20,
		hWnd,
		(HMENU)LEFT_ATTACK,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftDefense=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		50,
		140,
		60,
		20,
		hWnd,
		(HMENU)LEFT_DEFENSE,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftHP=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		50,
		180,
		60,
		20,
		hWnd,
		(HMENU)LEFT_HP,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftAttackBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		130,
		100,
		60,
		20,
		hWnd,
		(HMENU)LEFT_ATTACK_BONUS,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftDefenseBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		130,
		140,
		60,
		20,
		hWnd,
		(HMENU)LEFT_DEFENSE_BONUS,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftHPBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		130,
		180,
		60,
		20,
		hWnd,
		(HMENU)LEFT_HP_BONUS,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftAttackTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		210,
		100,
		60,
		20,
		hWnd,
		(HMENU)LEFT_ATTACK_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftDefenseTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		210,
		140,
		60,
		20,
		hWnd,
		(HMENU)LEFT_DEFENSE_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	HWND hLeftHPTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		210,
		180,
		60,
		20,
		hWnd,
		(HMENU)LEFT_HP_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	return 1;
}