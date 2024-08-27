#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "ColorsText.h"


void PaintConsole (Color color)
{
    HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE);
    switch(color)
    {
        case RED :
            SetConsoleTextAttribute (console, FOREGROUND_RED);
            break;

        case BLUE:
            SetConsoleTextAttribute (console, FOREGROUND_BLUE);
            break;

        case GREEN:
            SetConsoleTextAttribute (console, FOREGROUND_GREEN);
            break;

        case PINK:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_BLUE);
            break;

        case TURQUOISE:
            SetConsoleTextAttribute (console, FOREGROUND_GREEN | FOREGROUND_BLUE);

            break;

        case YELLOW:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_GREEN);
            break;

        case WHITE:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;

        default :
            printf ("Not available color");
    }
}
