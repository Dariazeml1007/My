#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "ColorsText.h"


void PaintConsol (color a)
{
    HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE);
    switch(a)
    {
        case Red :
            SetConsoleTextAttribute (console, FOREGROUND_RED);
            break;

        case Blue:
            SetConsoleTextAttribute (console, FOREGROUND_BLUE);
            break;

        case Green:
            SetConsoleTextAttribute (console, FOREGROUND_GREEN);
            break;

        case Pink:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_BLUE);
            break;

        case Turquoise:
            SetConsoleTextAttribute (console, FOREGROUND_GREEN | FOREGROUND_BLUE);

            break;

        case Yellow:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_GREEN);
            break;

        case White:
            SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;

        default :
            printf ("Not available color");
    }
}
