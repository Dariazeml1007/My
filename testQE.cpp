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


Status_file arrayStructsFromFile()
{
    check_ flag = TestCheckCORRECT;
    struct Square_parameters SP_file;
    FILE * pFile = NULL;

    pFile = fopen ("file.txt","r");
    if (pFile == NULL)
    {
        return Failed_Open_Error;
    }

    while ((fscanf (pFile,"%d, %lf, %lf, %lf, %lf, %lf, %d",
     &SP_file.TestNumber, &SP_file.a, &SP_file.b, &SP_file.c, &SP_file.correct_x1, &SP_file.correct_x2, (int *)&SP_file.correct_NRoots)) == 7)
    {

        if ((TestCheck (&(SP_file))) == TestCheckERROR)
            flag = TestCheckERROR;

    }

    if (flag == TestCheckCORRECT)
    {

        printf ("All tests successfully completed \n");

    }

    else
    {

        printf ("Some tests failed/n");

    }

    if ((fclose(pFile)) == 0)
        return Success_Read_File;
    return Not_Closed;
}

/**
* TestCheck
* @brief Print error, if a test fails
* @param [in] struct Square_parameters data - struct for check
*/


check_ TestCheck (struct Square_parameters *data)
{
    Solving_parameters test_param = {(data -> a), (data -> b), (data -> c), .x1 = 0, .x2 = 0};
    AmountOfRoots NRoots = SolveQuadratic (&test_param);

    if (NRoots != (data -> correct_NRoots))
    {
        PaintConsol (Red);
        printf ("Error test number %d, Different amount of roots NRoots = %d, correct_NRoots = %d \n", (data -> TestNumber), NRoots, (data -> correct_NRoots));
        return TestCheckERROR;
    }

    if(NRoots == OneRoot)
    {
        if (IsZero ((test_param.x1) - (data -> correct_x1)))
        {
            PaintConsol (Yellow);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TestCheckCORRECT ;
        }
        else
        {
            PaintConsol (Red);
            printf ("Error test number %d : Not correct value of root x1 = %lf, correct x1 = %lf \n", (data -> TestNumber), test_param.x1, (data -> correct_x1));
            return TestCheckERROR;
        }
    }

    if(NRoots == TwoRoots)
    {
        if ((IsZero ((test_param.x1) - (data -> correct_x1)) && (IsZero ((test_param.x2) - (data -> correct_x2))))
         || ((IsZero ((test_param.x2) - (data -> correct_x1)) && IsZero ((test_param.x1) - (data -> correct_x2)))))
        {
            PaintConsol (Yellow);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TestCheckCORRECT;
        }

        else
        {
            PaintConsol (Red);
            printf ("Error test number %d : Not correct values of roots x1 = %lf, x2 = %lf, correct_x1 = %lf, correct_x2 = %lf \n",
            (data -> TestNumber), (test_param.x1), (test_param.x2), (data -> correct_x1), (data -> correct_x2));
            return TestCheckERROR;
        }
    }

    if (NRoots == NoRoots || NRoots == InfinityRoots)
    {
        if (IsZero (test_param.x1) && IsZero(test_param.x2) && IsZero(data -> correct_x1) && IsZero(data -> correct_x2))
        {
            PaintConsol (Yellow);
            printf ("Test numbert %d successfully completed \n", (data -> TestNumber));
            return TestCheckCORRECT;
        }
        else
        {
            PaintConsol (Red);
            printf ("Error with test number %d : Amount of roots doesn't match to roots's value \n", (data -> TestNumber));
            return TestCheckERROR;
        }
    }

   return TestCheckERROR;
}



/**
* AllTestCheck
* @brief return Success, if everything is alright
*/

check_ AllTestCheck (void)
{
    PaintConsol (Blue);
    printf ("Tests are running \n");
    check_ flag = TestCheckCORRECT;
    struct Square_parameters array_sp [] =
    {
        {1, 1, 0, -4, 2, -2, TwoRoots},
        {2, 0, 0, 3, 0, 0, InfinityRoots},
        {3, 0, 4, 2, -0.5, 0, OneRoot},
        {4, 1, -0.7, 0.1, 0.5, 0.2, TwoRoots},
        {5, 1, -5, 0, 5, 0, TwoRoots},
        {6, 1, 5, 7, 0, 0, NoRoots},
        {7, 0 , 0 , 0, 0, 0, InfinityRoots}
    };

    int length = sizeof(array_sp)/sizeof(array_sp[0]);

    for (int i = 0; i < length; i++)
    {

        if ((TestCheck (&(array_sp[i]))) == TestCheckERROR)
            flag = TestCheckERROR;
    }

    if (flag == TestCheckCORRECT)
    {
        PaintConsol (Green);
        printf ("All tests successfully completed \n");


    }

    else
    {
        PaintConsol (Red);
        printf ("Some tests failed");

    }
    PaintConsol (White);
    return flag;
}

