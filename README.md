# AlwaysOnTop
A small tool to make a window always stay on the top. 
## Usage
1. Edit the config file. 
    ```
    MOD_KEY V_KEY
    BOOL_SHOWWINDOW
    INT_STARTUPSOUND INT_WINDOWTOPSOUND INT_WINDOWNOTOPSOUND INT_SOUNDLASTTIME
    ```
    For `MOD_KEY`: ALT = 1, CONTROL = 2, SHIFT = 4, WIN = 8. 

    For `V_KEY`: see [Virtual Key Codes](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes). 

    For `INT_STARTUPSOUND`, `INT_WINDOWTOPSOUND` and `INT_WINDOWNOTOPSOUND`, input an integer that describes the sound (Hz). 

    For `INT_SOUNDLASTTIME`, input an integer (ms). 

    Note: If you are using [Windows Terminal](https://learn.microsoft.com/zh-cn/windows/terminal/install) in Windows 11, the `BOOL_SHOWWINDOW` will not work. 

2. Run the app. 

3. Active a window and press the hot key. 
