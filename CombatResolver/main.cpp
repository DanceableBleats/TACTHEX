//-----------------//
// NOT MY INCLUDES //
//-----------------//
#ifndef _AFX_H_
#define _AFX_H_
#include <afx.h>
#endif
//#include <windows.h>
//#include <iostream> //moved to unit_commanders.h

//-------------//
// MY INCLUDES //
//-------------//
//#include "globals.h"
#include "enums.h"
#include "menus.h"
#include "controls.h"
#include "unit_classes.h"
#include "unit_commanders.h"


//----------//
// CONTROLS //
//----------//
//what are these?
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

//----------//
// FORWARDS //
//----------//
LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//LRESULT ChldProc(HWND hChWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//class windowControls;

//=========//
// GLOBALS //
//=========//
const char *clsName = "TactHEX Battle Calculator";
//const char *chldName = "Commanders";
char *title = "TactHEX Battle Calculator";
//char *chldTitle = "Commanders";
bool running = true;
HWND hWnd = NULL;
HWND hChWnd = NULL;
mainWindowControls *_mainWindowControls;
unit* leftUnit = NULL;
unit* rightUnit = NULL;
commanderList* leftCommander = NULL;
commanderList* rightCommander = NULL;

//---------------//
// PROGRAM ENTRY //
//---------------//
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)

{
	WNDCLASSEX  WndEx, ComWndw;                             

	MSG msg;

	WndEx.cbSize            = sizeof(WNDCLASSEX);                   /* The size, in bytes, of this structure. */
	WndEx.style             = CS_HREDRAW | CS_VREDRAW /*| CS_OWNDC*/;   /* The class style(s) */              
	WndEx.lpfnWndProc       = (WNDPROC)WndProc;                     /* A pointer to the window procedure. */           
	WndEx.cbClsExtra        = 0;                                    /* The number of extra bytes to allocate following the window-class structure. */
	WndEx.cbWndExtra        = 0;                                    /* The number of extra bytes to allocate following the window instance. */
	WndEx.hIcon             = LoadIcon(NULL, IDI_APPLICATION);      /* A handle to the class icon. */
	WndEx.hCursor           = LoadCursor(NULL, IDC_ARROW);          /* A handle to the class cursor. */
	WndEx.hbrBackground     = (HBRUSH)COLOR_APPWORKSPACE;           /* A handle to the class background brush. */
	WndEx.lpszMenuName      = NULL;                                 /* We're not using a menu here */
	WndEx.lpszClassName     = clsName;                              /* A pointer to a string that contains the class name */   
	WndEx.hInstance         = hInstance;                            /* A handle to the instance that contains the window procedure for the class. */          
	WndEx.hIconSm           = LoadIcon(NULL, IDI_APPLICATION);      /* A handle to a small icon that is associated with the window class */

	
//	ComWndw.cbSize			= sizeof(WNDCLASSEX);					
//	ComWndw.style			= CS_HREDRAW | CS_VREDRAW /*| CS_OWNDC*/;
//	ComWndw.lpfnWndProc		= (WNDPROC)ChldProc;
//	ComWndw.cbClsExtra		= 0;
//	ComWndw.cbWndExtra		= 0;
//	ComWndw.hIcon			= LoadIcon(NULL, IDI_APPLICATION);  
//	ComWndw.hCursor			= LoadCursor(NULL, IDC_ARROW);
//	ComWndw.hbrBackground	= (HBRUSH)COLOR_APPWORKSPACE;
//	ComWndw.lpszMenuName	= NULL;
//	ComWndw.lpszClassName	= chldName;
//	ComWndw.hInstance		= hInstance;
//	ComWndw.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);


	 /* Register the windows class */
    if (!RegisterClassEx(&WndEx))
    {
        MessageBox(NULL, "Failed to register class: Main Application Window", "ERROR", MB_OK | MB_ICONERROR);
        return 0;
    }

	/*if (!RegisterClassEx(&ComWndw))
	{
		MessageBox(NULL, "Failed to register class: Child Window", "ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}*/
 
    /* Create the window */
    if (!(hWnd = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, /* The extended window style */
                                clsName,                            /* A pointer to a string that contains the class name */
                                title,                              /* A pointer to a string that contains the title of the window */
                                WS_OVERLAPPEDWINDOW |                /* The style of the window being created */
                                WS_CLIPCHILDREN,           
                                CW_USEDEFAULT, CW_USEDEFAULT,       /* initial x,y position of the window */
                                1024, 768,                           /* initial x,y size of the window */
                                NULL,                               /* A handle to the parent or owner window */
                                NULL,                               /* A handle to a menu */
                                hInstance,                          /* A handle to the instance of the window */
                                NULL)))                             /* lParam */
    {  
        MessageBox(NULL, "Failed to create window: Main Application Window", "ERROR", MB_OK | MB_ICONERROR);
        return 0;
    }

/*	if (!(hChWnd = CreateWindowEx(WS_EX_WINDOWEDGE,
								chldName,
								chldTitle,
								 WS_CHILD | WS_CAPTION 
									| WS_SYSMENU | WS_THICKFRAME 
									| WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
								CW_USEDEFAULT, CW_USEDEFAULT,
								4, 3,
								hWnd,
								NULL,
								hInstance,
								NULL)))
	{
		MessageBox(NULL, "Failed to create window: Child Window", "ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}
	//else
	//{
	//	MessageBox(NULL, "Child Window Success", "SUCCESS", MB_OK | MB_ICONERROR);
	//}*/




 
	// Create the main menu
    CreateMainMenu(hWnd);

    /* The window is initially hidden, we need to show it */
    ShowWindow(hWnd, SW_SHOW); 

	
	//make sure the files needed exist, otherwise create them. 
	std::ofstream newFile;
	newFile.open ("commanders.bin");
	newFile.close();
	newFile.open ("comm_back.bin");
	newFile.close();
	
	//load the commander objects
	leftCommander = new commanderList();
	rightCommander - new commanderList();


	// Create Control Object
	//initControls(hWnd);
	_mainWindowControls = new mainWindowControls(hWnd);
 
    /* The main message loop */
    while(running)                             
    {
        /* Are there any messages in the message queue? */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))  
        {
            /* translate and dispatch the message */
            TranslateMessage(&msg);        
            DispatchMessage(&msg);         
		}
    }
    return msg.wParam;

}

LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		
		switch (uMsg)
		{
		case LOWORD(LEFT_UPDATE):
			{
				//populate left unit stat boxes
				SetWindowText(_mainWindowControls->hLeftAttack, leftUnit->sAttack);
				SetWindowText(_mainWindowControls->hLeftDefense, leftUnit->sDefense);
				SetWindowText(_mainWindowControls->hLeftHP, leftUnit->sHP);

				//Calculate left unit totals
				CString sTotalAttack, sTotalDefense, sTotalHP;
				int totalAttack = (leftUnit->attack + 1/*add commander bonuses here*/);
				int totalDefense = (leftUnit->attack + 1/*add commander bonuses here*/);
				int totalHP = (leftUnit->hp + 1/*add commander bonuses here*/);
				sTotalAttack.Format("%d", totalAttack);
				sTotalDefense.Format("%d", totalDefense);
				sTotalHP.Format("%d", totalHP);
				
				//populate left unit totals
				SetWindowText(_mainWindowControls->hLeftAttackTotal, (LPCSTR) sTotalAttack);
				SetWindowText(_mainWindowControls->hLeftDefenseTotal, (LPCSTR) sTotalDefense);
				SetWindowText(_mainWindowControls->hLeftHPTotal, (LPCSTR) sTotalHP);
			}
			return 0;

		case LOWORD(RIGHT_UPDATE):
			{
				SetWindowText(_mainWindowControls->hRightAttack, rightUnit->sAttack);
				SetWindowText(_mainWindowControls->hRightDefense, rightUnit->sDefense);
				SetWindowText(_mainWindowControls->hRightHP, rightUnit->sHP);

				//Calculate right unit totals
				CString sTotalAttack, sTotalDefense, sTotalHP;
				int totalAttack = (rightUnit->attack + 1/*add commander bonuses here*/);
				int totalDefense = (rightUnit->attack + 1/*add commander bonuses here*/);
				int totalHP = (rightUnit->hp + 1/*add commander bonuses here*/);
				sTotalAttack.Format("%d", totalAttack);
				sTotalDefense.Format("%d", totalDefense);
				sTotalHP.Format("%d", totalHP);
				
				//populate right unit totals
				SetWindowText(_mainWindowControls->hRightAttackTotal, (LPCSTR) sTotalAttack);
				SetWindowText(_mainWindowControls->hRightDefenseTotal, (LPCSTR) sTotalDefense);
				SetWindowText(_mainWindowControls->hRightHPTotal, (LPCSTR) sTotalHP);

			}
			return 0;

		case WM_CLOSE: 
			DestroyWindow(hWnd);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			running = false;
			return 0;
					
		case WM_COMMAND:
			{
				switch(LOWORD(wParam))
				{ 		
				case ID_FILE_EXIT:
					PostQuitMessage(0);
					running = false;
					break;
								
				case ID_FILE_MSG:
					MessageBox(hWnd, "Hello!", "Message", MB_ICONINFORMATION);
					break;

				case TEST_BUTTON_1:	
					MessageBox(hWnd, "TEST!", "TEST", MB_ICONINFORMATION);
					break;	

			
				}// End of LOWORD Switch

				switch(HIWORD(wParam))
				{
				case CBN_SELCHANGE:
					if ((HWND)lParam == _mainWindowControls->hLeftUnitComboBox)
					{
						int itemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
						if (leftUnit == NULL)
						{
							leftUnit = new unit((UNIT_CLASS)itemIndex);
						}
						else 
						{
							leftUnit->~unit();
							leftUnit = new unit((UNIT_CLASS)itemIndex);
						}
						SendMessage(hWnd, LOWORD(LEFT_UPDATE), 0, 0);
					}
					if ((HWND)lParam == _mainWindowControls->hRightUnitComboBox)
					{
						int itemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
						if (rightUnit == NULL)
						{
							rightUnit = new unit((UNIT_CLASS)itemIndex);
						}
						else 
						{
							rightUnit->~unit();
							rightUnit = new unit((UNIT_CLASS)itemIndex);
						}
						SendMessage(hWnd, LOWORD(RIGHT_UPDATE), 0, 0);
					}//end of IF lParam == _mainWindowControls->hRightComboBox
					break; //Break out of CASE: CBN_SELCHANGE
				}
			}
			break;// Break out of CASE: WM_COMMAND Should this be return 0;?

		default:
			return DefWindowProc(hWnd,uMsg,wParam,lParam);
		}//end of switch(umsg)
}


