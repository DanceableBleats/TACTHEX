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




mainWindowControls::mainWindowControls(HWND hWnd)
{
	//Drop Downs
	hLeftComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		50, 
		50, 
		220, 
		20, 
		hWnd, 
		(HMENU)LEFT_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);

	hRightComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		550, 
		50, 
		220, 
		20, 
		hWnd, 
		(HMENU)RIGHT_DROP_DOWN, 
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
		SendMessage(hRightComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) unitname); 
    }
      
    // Send the CB_SETCURSEL message to display an initial item 
    //  in the selection field  
    SendMessage(hLeftComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	SendMessage(hRightComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);



	//Left stat boxes
	hLeftAttack=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftDefense=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftHP=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftAttackBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftDefenseBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftHPBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftAttackTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftDefenseTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	hLeftHPTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
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

	//Right stat boxes
	hRightAttack=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		550,
		100,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_ATTACK,
		GetModuleHandle(NULL),
		NULL);

	hRightDefense=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		550,
		140,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_DEFENSE,
		GetModuleHandle(NULL),
		NULL);

	hRightHP=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		550,
		180,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_HP,
		GetModuleHandle(NULL),
		NULL);

	hRightAttackBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		630,
		100,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_ATTACK_BONUS,
		GetModuleHandle(NULL),
		NULL);

	hRightDefenseBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		630,
		140,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_DEFENSE_BONUS,
		GetModuleHandle(NULL),
		NULL);

	hRightHPBonus=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		630,
		180,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_HP_BONUS,
		GetModuleHandle(NULL),
		NULL);

	hRightAttackTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		710,
		100,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_ATTACK_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	hRightDefenseTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		710,
		140,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_DEFENSE_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	hRightHPTotal=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		710,
		180,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_HP_TOTAL,
		GetModuleHandle(NULL),
		NULL);
}

mainWindowControls::~mainWindowControls()
{
}