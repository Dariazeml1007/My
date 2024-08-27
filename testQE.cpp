#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <conio.h>

#include "dataQE.h"
#include "testQE.h"
#include "solveQE.h"
#include "ColorsText.h"

StatusFile ArrayStructsFromFile(const char *nameOfFile)
{
    CHECK flag = TEST_CHECK_CORRECT;
    struct Square_parameters Square_test_file = {};
    FILE *pFile = NULL;

    pFile = fopen (nameOfFile,"r");
    if (pFile == NULL)
    {
        return FAILED_OPEN_ERROR;
    }

    while ((fscanf (pFile,"%d, %lf, %lf, %lf, %lf, %lf, %d",
                    &Square_test_file.TestNumber, &Square_test_file.a, &Square_test_file.b, &Square_test_file.c,
                    &Square_test_file.correct_x1, &Square_test_file.correct_x2, (int *)&Square_test_file.correct_NRoots)) == 7)
    {

        if ((TestCheck (&(Square_test_file))) == TEST_CHECK_ERROR)
            flag = TEST_CHECK_ERROR;

    }

    if (flag == TEST_CHECK_CORRECT)
    {
        PaintConsole (GREEN);
        printf ("All tests successfully completed \n");

    }

    else
    {
        PaintConsole (RED);
        printf ("Some tests failed/n");

    }
    PaintConsole (WHITE);
    if ((fclose (pFile)) == 0)
        return SUCCESS_READ_FILE;
    return NOT_CLOSED;
}


/**
* TestCheck
* @brief Print error, if a test fails
* @param [in] struct Square_parameters data - struct for check
*/

CHECK TestCheck (struct Square_parameters *data)
{
    Solving_parameters test_param = {(data -> a), (data -> b), (data -> c), .x1 = 0, .x2 = 0};
    AmountOfRoots nRoots = SolveQuadratic (&test_param);

    if (nRoots != (data -> correct_NRoots))
    {
        PaintConsole (RED);
        printf ("Error test number %d, Different amount of roots NRoots = %d, correct_NRoots = %d \n", (data -> TestNumber), nRoots, (data -> correct_NRoots));
        return TEST_CHECK_ERROR;
    }

    if(nRoots == ONE_ROOT)
    {
        if (IsZero ((test_param.x1) - (data -> correct_x1)))
        {
            PaintConsole (YELLOW);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TEST_CHECK_CORRECT ;
        }
        else
        {
            PaintConsole (RED);
            printf ("Error test number %d : Not correct value of root x1 = %lf, correct x1 = %lf \n", (data -> TestNumber), test_param.x1, (data -> correct_x1));
            return TEST_CHECK_ERROR;
        }
    }

    if(nRoots == TWO_ROOTS)
    {
        if ((IsZero ((test_param.x1) - (data -> correct_x1)) && (IsZero ((test_param.x2) - (data -> correct_x2))))
         || ((IsZero ((test_param.x2) - (data -> correct_x1)) && IsZero ((test_param.x1) - (data -> correct_x2)))))
        {
            PaintConsole (YELLOW);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TEST_CHECK_CORRECT;
        }

        else
        {
            PaintConsole (RED);
            printf ("Error test number %d : Not correct values of roots x1 = %lf, x2 = %lf, correct_x1 = %lf, correct_x2 = %lf \n",
                    (data -> TestNumber), (test_param.x1), (test_param.x2), (data -> correct_x1), (data -> correct_x2));
            return TEST_CHECK_ERROR;
        }
    }

    if (nRoots == NO_ROOTS || nRoots == INFINITY_ROOTS)
    {
        if (IsZero (test_param.x1) && IsZero(test_param.x2) && IsZero(data -> correct_x1) && IsZero(data -> correct_x2))
        {
            PaintConsole (YELLOW);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TEST_CHECK_CORRECT;
        }
        else
        {
            PaintConsole (RED);
            printf ("Error with test number %d : Amount of roots doesn't match to roots's value \n", (data -> TestNumber));
            return TEST_CHECK_ERROR;
        }
    }

   return TEST_CHECK_ERROR;
}


/**
* AllTestCheck
* @brief return Success, if everything is alright
*/

CHECK AllTestCheck (void)
{
    PaintConsole (BLUE);
    printf ("Tests are running \n");
    CHECK flag = TEST_CHECK_CORRECT;
    struct Square_parameters array_sp [] =
    {
        {1, 1,    0,  -4,    2,  -2, TWO_ROOTS},
        {2, 0,    0,   3,    0,   0, INFINITY_ROOTS},
        {3, 0,    4,   2, -0.5,   0, ONE_ROOT},
        {4, 1, -0.7, 0.1,  0.5, 0.2, TWO_ROOTS},
        {5, 1,   -5,   0,    5,   0, TWO_ROOTS},
        {6, 1,    5,   7,    0,   0, NO_ROOTS},
        {7, 0,    0,   0,    0,   0, INFINITY_ROOTS}
    };

    int length = sizeof(array_sp)/sizeof(array_sp[0]);

    for (int i = 0; i < length; i++)
    {
        assert (0 <= i && i < length);

        if ((TestCheck (&(array_sp[i]))) == TEST_CHECK_ERROR)
            flag = TEST_CHECK_ERROR;
    }

    if (flag == TEST_CHECK_CORRECT)
    {
        PaintConsole (GREEN);
        printf ("All tests successfully completed \n");

    }

    else
    {
        PaintConsole (RED);
        printf ("Some tests failed \n");

    }
    PaintConsole (WHITE);
    return flag;
}

