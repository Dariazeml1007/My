#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

#include "dataQE.h"
#include "testQE.h"
#include "scanfQE.h"
#include "solveQE.h"
#include "printQE.h"
#include "ColorsText.h"


typedef enum
{
    SUCCESS = 0,
    FAILED = 1

} SystemResult ;


int main(int argc, char* argv[])
{

    if (argc == 1 || (argc == 2 && strcmp (argv[1], "--solve") == 0 ))
    {
        double a = 0, b = 0, c = 0;
        GetCofficients (&a, &b, &c);

        double x1 = 0, x2 = 0;// Roots
        Solving_parameters cofficients_roots = {a, b, c, x1, x2};
        AmountOfRoots NRoots = SolveQuadratic (&cofficients_roots);// Amount of roots

        PrintRoots (NRoots, &cofficients_roots);

    }

    else if (argc == 2 &&  strcmp (argv[1], "--test") == 0)
    {

        AllTestCheck();
    }

    else if (argc == 2 && strcmp (argv[1], "--help") == 0)
    {

        printf ("You can:\n"
        "test my program by using <--test>\n"
        "try to use my program by using <--solve> \n"
        "load your own tests from file.txt by using <--file>");

    }

    else if (argc == 2 && strcmp (argv[1], "--file") == 0)
    {
        return arrayStructsFromFile();
    }

    return SUCCESS;
}




