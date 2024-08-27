#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

#include "printQE.h"
#include "ColorsText.h"


void PrintHelp()
{
    PaintConsole (BLUE);

    printf ("You can:\n"
            "test my program by using <--test>\n"
            "try to use my program by using <--solve> \n"
            "load your own tests from file by using <--file NameOfFile> \n");

    PaintConsole (WHITE);
}

/**
* Print Roots
* @brief Print answers
* @param [in] NRoots - amount of roots
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/



void PrintRoots (AmountOfRoots NRoots, Solving_parameters *data)
{
    assert (data != NULL);

    switch (NRoots)
    {
        case INFINITY_ROOTS:

            PaintConsole(BLUE);
            printf ("Infinity roots \n");
            PaintConsole (WHITE);

            break;

        case NO_ROOTS :

            PaintConsole (TURQUOISE);
            printf ("No roots \n");
            PaintConsole (WHITE);

            break;

        case ONE_ROOT :

            PaintConsole (PINK);

            printf ("One root : x1 =  \n");
            printf ("%f", data -> x1);

            PaintConsole (WHITE);

            break;

        case TWO_ROOTS:

            PaintConsole (PINK);

            printf ("First root : x1 = %f\n", data -> x1);
            printf ("Second root : x2 = %f\n", data -> x2);

            PaintConsole (WHITE);
            break;

        default :
            assert (false);

    }

}
