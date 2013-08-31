//-----------------//
// NOT MY INCLUDES //
//-----------------//
#include <windows.h>

//-------------//
// MY INCLUDES //
//-------------//
#include "globals.h"
#include "enums.h"
#include "menus.h"
#include "controls.h"

//----------//
// CONTROLS //
//----------//
//what are these?
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

//----------//
// FORWARDS //
//----------//
LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//---------------//
// PROGRAM ENTRY //
//---------------//
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)

{
	WNDCLASSEX  WndEx;                             

    MSG msg;

    WndEx.cbSize            = sizeof(WNDCLASSEX);                   /* The size, in bytes, of this structure. */
    WndEx.style             = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;   /* The class style(s) */              
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

 


	 /* Register the windows class */
    if (!RegisterClassEx(&WndEx))
    {
        MessageBox(NULL, "Failed to register class", "ERROR", MB_OK | MB_ICONERROR);
        return 0;
    }
 
    /* Create the window */
    if (!(hWnd = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, /* The extended window style */
                                clsName,                            /* A pointer to a string that contains the class name */
                                title,                              /* A pointer to a string that contains the title of the window */
                                WS_OVERLAPPEDWINDOW |               /* The style of the window being created */
                                WS_CLIPSIBLINGS | WS_CLIPCHILDREN,             
                                CW_USEDEFAULT, CW_USEDEFAULT,       /* initial x,y position of the window */
                                1024, 768,                           /* initial x,y size of the window */
                                NULL,                               /* A handle to the parent or owner window */
                                NULL,                               /* A handle to a menu */
                                hInstance,                          /* A handle to the instance of the window */
                                NULL)))                             /* lParam */
    {  
        MessageBox(NULL, "Failed to create the window", "ERROR", MB_OK | MB_ICONERROR);
        return 0;
    }
 
	// Create the main menu
    CreateMainMenu(hWnd);

    /* The window is initially hidden, we need to show it */
    ShowWindow(hWnd, SW_SHOW); 

	// Initialize controls
	initControls(hWnd);
 
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
				/* Message created when the user tries to close the window */
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

							case CBN_SELCHANGE:
								/*do stuff*/
								break;

							/*case BUTTON_1:
								MessageBox(hWnd, "Button", "Button", MB_ICONINFORMATION);
								break;*/
						}	
					} break;
				default:
					return DefWindowProc(hWnd,uMsg,wParam,lParam);
		}
}
