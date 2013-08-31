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


//Outcomes




//initialize function
int initControls(HWND hWnd);

