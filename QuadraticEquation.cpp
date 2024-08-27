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
#include "ArgvArgcQE.h"


typedef enum
{
    SUCCESS = 0,
    FAILED = 1

} SystemResult;



int main (const int argc, const char* argv[])
{
    struct Argv_type Flags = {};
    if (argc == 1)
        UsingQuadraticEquation ();

    DefineArgv (argc, argv, &Flags);

    if (Flags.is_help)
        PrintHelp ();

    if (Flags.is_test)
        AllTestCheck ();

    if (Flags.is_file)
    {
        const char nameOfFile[] = "file.txt";
        ArrayStructsFromFile (nameOfFile);
    }

    if (Flags.user_file)
        ArrayStructsFromFile (argv[Flags.f_index]);

    if (Flags.is_solve)
        UsingQuadraticEquation ();

    return SUCCESS;
}

