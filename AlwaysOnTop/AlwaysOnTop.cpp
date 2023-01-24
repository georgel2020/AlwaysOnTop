#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

HWND topWindow[128];    // Always On Top windows. 
int topCount = 0;

int modKey, vKey;
// modKey: ALT = 1, CONTROL = 2, SHIFT = 4, WIN = 8. 
// vKey: [Virtual Key Codes](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes). 

bool showWindow;

int main()
{
    ifstream fin("config.txt");    // Read config file. 
    fin >> modKey >> vKey;
    fin >> showWindow;

    if(!showWindow) ShowWindow(GetConsoleWindow(), SW_HIDE);    // Hide console window. 

    if (RegisterHotKey(NULL, 1, modKey, vKey) == false) {
        printf("Error: Cannot register hotkey\n");    // Register fail. 
        getchar();
    }    // Regist hot key: ALT + F1. 
    else {
        MSG msg = { 0 };
        printf("Always On Top (0)\n");

        while (GetMessage(&msg, NULL, 0, 0)) {    // Message queue. 
            switch (msg.message) {
            case WM_HOTKEY:
            {
                if (1 == msg.wParam) {
                    HWND hwnd = GetForegroundWindow();    // Get hwnd of topest window. 
                    bool top = false;
                    // Check if the window is TOPMOST
                    for (int i = 0; i < topCount; i++) {
                        if (topWindow[i] == hwnd) {
                            SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);     // Set window NOTOPMOST. 
                            topWindow[topCount] = 0;
                            topCount--;
                            top = true;
                            break;
                        }
                    }

                    if (top == false) {
                        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);    // Set window TOPMOST. 

                        topCount++;
                        topWindow[topCount - 1] = hwnd;    // Record window hwnd. 
                    }
                    system("cls");
                    printf("Always On Top (%d)\n", topCount);
                    for (int i = 0; i < topCount; i++) {
                        printf("  Hwnd %d: %d", i, (int)topWindow[i]);    // Print window hwnd in console. 
                        if (topWindow[i] == hwnd) {
                            printf(" <");
                        }
                        printf("\n");
                    }
                }
                break;
            }
            default:
                break;
            }
        }
    }
}