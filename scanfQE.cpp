#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "scanfQE.h"
#include "ColorsText.h"
/**
*Gets coefficient
*
* @brief Reading a coefficient as long as the input is not a number
* @param [out] out - result of scanning
* @param [in]  sym - name of coefficient
*/

void GetCofficient (double *out, char sym)
{
    printf ("%c = ", sym);
    char str[256];

    while (scanf ("%lf", out) != 1)
    {
        if (scanf("%s", str) == 1 && strcmp(str,"exit") == 0)
            exit(EXIT_FAILURE);

        PaintConsol (Red);
        printf("Error, try again \n");
        PaintConsol (White);
        printf ("%c = ", sym);
        while (getchar() != '\n')
            ;

    }
}

/**
* Gets coefficients
* @brief Reading all coefficients by using GetCofficient function
* @param [in] *a - pointer to coefficient a
* @param [in] *b - pointer to coefficient b
* @param [in] *c - pointer to coefficient c
*/

void GetCofficients (double *a, double *b, double *c)
{
    GetCofficient(a, 'a');
    GetCofficient(b, 'b');
    GetCofficient(c, 'c');
}

