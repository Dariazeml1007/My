#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>


#include "printQE.h"
#include "ColorsText.h"


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
        case InfinityRoots:

            PaintConsol(Blue);
            printf ("Infinity roots");
            PaintConsol (White);

            break;

        case NoRoots :

            PaintConsol(Turquoise);
            printf ("No roots");
            PaintConsol (White);

            break;

        case OneRoot :

            PaintConsol (Pink);

            printf ("One root : x1 = ");
            printf ("%f", data -> x1);

            PaintConsol (White);

            break;

        case TwoRoots:

            PaintConsol (Pink);

            printf ("First root : x1 = %f\n", data -> x1);
            printf ("Second root : x2 = %f", data -> x2);

            PaintConsol (White);
            break;

        default :
            assert (false);

    }

}
