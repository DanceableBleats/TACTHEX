#include "controls.h"

mainWindowControls::mainWindowControls(HWND hWnd)
{

	// Create a push button                   BUTTON EXAMPLE!
	hWndTestButton1=CreateWindowEx(NULL,
		"BUTTON",
		"Test",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		300,
		400,
		100,
		24,
		hWnd,
		(HMENU)TEST_BUTTON_1,
		GetModuleHandle(NULL),
		NULL);



	//Drop Downs
	hLeftUnitComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		50, 
		50, 
		220, 
		20, 
		hWnd, 
		(HMENU)LEFT_UNIT_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);

	hRightUnitComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		550, 
		50, 
		220, 
		20, 
		hWnd, 
		(HMENU)RIGHT_UNIT_DROP_DOWN, 
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
        SendMessage(hLeftUnitComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) unitname);
		SendMessage(hRightUnitComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) unitname); 
    }

	hLeftCommanderComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		50, 
		90, 
		220, 
		20, 
		hWnd, 
		(HMENU)LEFT_COMMANDER_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);

	hRightCommanderComboBox=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		550, 
		90, 
		220, 
		20, 
		hWnd, 
		(HMENU)RIGHT_COMMANDER_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);




      
    // Send the CB_SETCURSEL message to display an initial item 
    //  in the selection field  
    //  SendMessage(hLeftCommanderComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	//  SendMessage(hRightCommanderComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);



	//Left stat boxes
	hLeftAttack=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		50,
		140,
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
		180,
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
		220,
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
		140,
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
		180,
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
		220,
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
		140,
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
		180,
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
		220,
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
		140,
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
		180,
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
		220,
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
		140,
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
		180,
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
		220,
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
		140,
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
		180,
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
		220,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_HP_TOTAL,
		GetModuleHandle(NULL),
		NULL);

	//Outcomes
	hWinner=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		380,
		290,
		60,
		20,
		hWnd,
		(HMENU)WINNER,
		GetModuleHandle(NULL),
		NULL);

	hLeftRemainingHP=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		300,
		290,
		60,
		20,
		hWnd,
		(HMENU)LEFT_REMAINING_HP,
		GetModuleHandle(NULL),
		NULL);

	hRightRemainingHP=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		460,
		290,
		60,
		20,
		hWnd,
		(HMENU)RIGHT_REMAINING_HP,
		GetModuleHandle(NULL),
		NULL);




}

mainWindowControls::~mainWindowControls()
{
}