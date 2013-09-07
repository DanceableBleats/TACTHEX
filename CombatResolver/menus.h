#pragma once

// Add new popup menu
#define ADDPOPUPMENU(hmenu, string) \
    HMENU hSubMenu = CreatePopupMenu(); \
    AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, string);

// Add a menu item
#define ADDMENUITEM(hmenu, ID, string) \
    AppendMenu(hSubMenu, MF_STRING, ID, string);

void CreateMainMenu(HWND hWnd)
{
    HMENU hMenu = CreateMenu();
 
    ADDPOPUPMENU(hMenu, L"&File");
    ADDMENUITEM(hMenu, ID_FILE_EXIT, L"&Exit");
    ADDMENUITEM(hMenu, ID_FILE_MSG, L"&Show message");
 
    SetMenu(hWnd, hMenu);
}