#include "controls.h"
//#include "unit_classes.h"
#include "unit_commanders.h"

//extern commander* leftCommander;
//extern commander* rightCommander;
extern commanderList* editCommander;



mainWindowControls::mainWindowControls(HWND hWnd)
{

	// Create a push button                   BUTTON EXAMPLE!
	hWndTestButton1=CreateWindowEx(NULL,
		"BUTTON",
		"test",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		360,
		320,
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
		400, 
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
		400, 
		20, 
		hWnd, 
		(HMENU)RIGHT_COMMANDER_DROP_DOWN, 
		GetModuleHandle(NULL),
		NULL);

	hEditCommanderName=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		260, 
		400, 
		300, 
		20, 
		hWnd, 
		(HMENU)COMMANDER_NAME, 
		GetModuleHandle(NULL),
		NULL);

	//Move this to a redraw message case in the windproc and call it from here. Add in a function to delete
	// delete all strings and then re-add so that we can er-draw all three lists whenever the contents changes.
	for (editCommander->iter = editCommander->commanderVector.begin(); editCommander->iter != editCommander->commanderVector.end(); (editCommander->iter)++)
	{
		std::vector<commander*>::iterator iter2 = editCommander->iter;
		
		SendMessage(hLeftCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) (*iter2)->csName.GetBuffer());
		SendMessage(hRightCommanderComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) (*iter2)->csName.GetBuffer());
		SendMessage(hEditCommanderName,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) (*iter2)->csName.GetBuffer());
		
	}


      
    // Send the CB_SETCURSEL message to display an initial item 
    //  in the selection field  
	//SendMessage(hLeftCommanderComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	//SendMessage(hRightCommanderComboBox, CBN_SETCURSEL, (WPARAM)0, (LPARAM)0);
	

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



	//=========================//
	// Commander edit controls //
	//=========================//

	//Combo Box   //moved up to other combo boxes
/*	hEditCommanderName=CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_COMBOBOX, 
		TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		260, 
		400, 
		300, 
		20, 
		hWnd, 
		(HMENU)COMMANDER_NAME, 
		GetModuleHandle(NULL),
		NULL);
		*/

	//Edits
	hEditCommanderAttack=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		380,
		440,
		60,
		20,
		hWnd,
		(HMENU)COMMANDER_ATTACK_BONUS,
		GetModuleHandle(NULL),
		NULL);

	


	hEditCommanderDefense=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		380,
		480,
		60,
		20,
		hWnd,
		(HMENU)COMMANDER_DEFENSE_BONUS,
		GetModuleHandle(NULL),
		NULL);

	hEditCommanderHP=CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"",
		WS_CHILD|WS_VISIBLE,
		380,
		520,
		60,
		20,
		hWnd,
		(HMENU)COMMANDER_HP_BONUS,
		GetModuleHandle(NULL),
		NULL);

	//Buttons
	hNewCommanderButton=CreateWindowEx(NULL,
		"BUTTON",
		"New",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		260,
		560,
		100,
		24,
		hWnd,
		(HMENU)COMMANDER_NEW,
		GetModuleHandle(NULL),
		NULL);

	hSaveCommanderButton=CreateWindowEx(NULL,
		"BUTTON",
		"Save",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		380,
		560,
		100,
		24,
		hWnd,
		(HMENU)COMMANDER_SAVE,
		GetModuleHandle(NULL),
		NULL);

	hDeleteCommanderButton=CreateWindowEx(NULL,
		"BUTTON",
		"Delete",
		WS_TABSTOP|WS_VISIBLE|
		WS_CHILD|BS_DEFPUSHBUTTON,
		500,
		560,
		100,
		24,
		hWnd,
		(HMENU)COMMANDER_DELETE,
		GetModuleHandle(NULL),
		NULL);
}

mainWindowControls::~mainWindowControls()
{
}