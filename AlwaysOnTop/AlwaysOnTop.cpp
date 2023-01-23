#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;
HWND topWindow[128];
int topCount = 0;
int main(int args) {
	RegisterHotKey(NULL, 1, MOD_ALT, VK_F1);    // Regist hot key: ALT + F1
    MSG msg = { 0 };
    printf("Always On Top (0)\n");
    

    while (GetMessage(&msg, NULL, 0, 0)) {    // Message queue
        switch (msg.message) {
        case WM_HOTKEY:
        {
            if (1 == msg.wParam) {
                HWND hwnd = GetForegroundWindow();    // Get hwnd of topest window
                bool top = false;
                // Check if the window is TOPMOST
                for (int i = 0; i < topCount; i++) {
                    if (topWindow[i] == hwnd) {
                        SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);     // Set window NOTOPMOST
                        topWindow[topCount] = 0;
                        topCount--;
                        top = true;
                        break;
                    }
                }

                if (top == false) {
                    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);    // Set window TOPMOST

                    topCount++;
                    topWindow[topCount - 1] = hwnd;    // Record window hwnd
                }
                system("cls");
                printf("Always On Top (%d)\n", topCount);
                for (int i = 0; i < topCount; i++) {
                    printf("  Hwnd %d: %d", i, (int)topWindow[i]);    // Print window hwnd in console
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