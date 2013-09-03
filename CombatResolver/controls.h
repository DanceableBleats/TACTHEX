#pragma once
#include <Windows.h>
#include <CommCtrl.h>

//Update (Application Messages)
#define LEFT_UPDATE						901
#define RIGHT_UPDATE					902

//Left combatant stat boxes
#define LEFT_ATTACK						101
#define LEFT_DEFENSE					102
#define LEFT_HP							103
#define LEFT_ATTACK_BONUS				104
#define LEFT_DEFENSE_BONUS				105
#define LEFT_HP_BONUS					106
#define LEFT_ATTACK_TOTAL				107
#define LEFT_DEFENSE_TOTAL				108
#define LEFT_HP_TOTAL					109

//right combatant stat boxes
#define RIGHT_ATTACK					111
#define RIGHT_DEFENSE					112
#define RIGHT_HP						113
#define RIGHT_ATTACK_BONUS				114
#define RIGHT_DEFENSE_BONUS				115
#define RIGHT_HP_BONUS					116
#define RIGHT_ATTACK_TOTAL				117
#define RIGHT_DEFENSE_TOTAL				118
#define RIGHT_HP_TOTAL					119

//Buttons
#define TEST_BUTTON_1					201
#define MELEE_COMBAT					202
#define RANGED_ATTACK					203

//Drop downs
#define LEFT_UNIT_DROP_DOWN				301
#define LEFT_COMMANDER_DROP_DOWN		302
#define RIGHT_UNIT_DROP_DOWN			303
#define RIGHT_COMMANDER_DROP_DOWN		304

//Outcomes
#define WINNER							401
#define LEFT_REMAINING_HP				402
#define RIGHT_REMAINING_HP				403



//Control Class
class mainWindowControls
{
public:
	mainWindowControls(HWND hWnd);
	~mainWindowControls();

	//combo boxes
	HWND hLeftUnitComboBox;
	HWND hRightUnitComboBox;	
	HWND hLeftCommanderComboBox;
	HWND hRightCommanderComboBox;
	
	//Buttons
	HWND hWndTestButton1;

	//left unit stat boxes
	HWND hLeftAttack;
	HWND hLeftDefense;
	HWND hLeftHP;
	HWND hLeftAttackBonus;
	HWND hLeftDefenseBonus;
	HWND hLeftHPBonus;
	HWND hLeftAttackTotal;
	HWND hLeftDefenseTotal;
	HWND hLeftHPTotal;


	//right unit stat boxes
	HWND hRightAttack;
	HWND hRightDefense;
	HWND hRightHP;
	HWND hRightAttackBonus;
	HWND hRightDefenseBonus;
	HWND hRightHPBonus;
	HWND hRightAttackTotal;
	HWND hRightDefenseTotal;
	HWND hRightHPTotal;

	//Outcomes
	HWND hWinner;
	HWND hLeftRemainingHP;
	HWND hRightRemainingHP;


};





