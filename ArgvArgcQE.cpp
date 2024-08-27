#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

#include "dataQE.h"
#include "ColorsText.h"
#include "ArgvArgcQE.h"


bool IsNotFlag(const char *argv)
{
    if (strcmp (argv, "--help") == 0 || strcmp (argv, "--solve") == 0
        || strcmp (argv, "--file") == 0 || strcmp (argv, "--test") == 0)
        return false;
    return true;
}


void DefineArgv (const int argc, const char *argv[], struct Argv_type *flags)
{
    for (int i = 1; i < argc; (i)++)
    {
        if (strcmp (argv[i], "--solve") == 0)
        {
            flags -> is_solve = true;
        }

        else if (strcmp (argv[i], "--help") == 0)
        {
            flags -> is_help = true;
        }
        else if (strcmp (argv[i], "--test") == 0)
        {
            flags -> is_test = true;
        }
        else if (strcmp (argv[i], "--file") == 0)
        {
            if ((i) < (argc - 1) && IsNotFlag (argv[(i) + 1]))
            {
                flags -> user_file = true;
                flags -> f_index = ++i;
            }
            else
                flags -> is_file = true;

        }

    }

}




