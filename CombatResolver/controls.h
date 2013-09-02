#pragma once
#include <Windows.h>
#include <CommCtrl.h>



//Left combatant stat boxes
#define LEFT_ATTACK 101
#define LEFT_DEFENSE 102
#define LEFT_HP 103
#define LEFT_ATTACK_BONUS 104
#define LEFT_DEFENSE_BONUS 105
#define LEFT_HP_BONUS 106
#define LEFT_ATTACK_TOTAL 107
#define LEFT_DEFENSE_TOTAL 108
#define LEFT_HP_TOTAL 109

//right combatant stat boxes
#define RIGHT_ATTACK 101
#define RIGHT_DEFENSE 102
#define RIGHT_HP 103
#define RIGHT_ATTACK_BONUS 104
#define RIGHT_DEFENSE_BONUS 105
#define RIGHT_HP_BONUS 106
#define RIGHT_ATTACK_TOTAL 107
#define RIGHT_DEFENSE_TOTAL 108
#define RIGHT_HP_TOTAL 109


//Buttons
#define MELEE_COMBAT 201
#define RANGED_ATTACK 202

//Drop downs
#define LEFT_DROP_DOWN 301
#define RIGHT_DROP_DOWN 302


//Outcomes




//Control Class
class mainWindowControls
{
public:
	mainWindowControls(HWND hWnd);
	~mainWindowControls();

	//left unit stat boxes
	HWND hLeftComboBox;
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
	HWND hRightComboBox;
	HWND hRightAttack;
	HWND hRightDefense;
	HWND hRightHP;
	HWND hRightAttackBonus;
	HWND hRightDefenseBonus;
	HWND hRightHPBonus;
	HWND hRightAttackTotal;
	HWND hRightDefenseTotal;
	HWND hRightHPTotal;



};





