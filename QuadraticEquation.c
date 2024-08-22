#include <stdio.h>
#include <math.h>
#include <string.h>

const double EPS = 1e-7;

typedef enum
{
    BIGGER,
    SMALLER,
    EQUAL

} compare_;

typedef enum
{
    InfinityRoots,
    NoRoots,
    OneRoot,
    TwoRoots

} AmountOfRoots;


void get_cofficient (double *out, char sym);
void get_cofficients (double *a, double *b, double *c);
AmountOfRoots SolveQuadratic (double a, double b, double c, double *x1, double *x2);
AmountOfRoots CalculateSquare (double a, double b, double c, double *x1, double *x2);
AmountOfRoots CalculateLineal (double b, double c, double *x1);
void PrintRoots (int NRoots, double *x1, double *x2);
int TestCheck (int TestNumber, double a, double b, double c, double correct_x1, double correct_x2, int correct_NRoots);
char *AllTestCheck (void);
compare_ Comparison_doubles (double a, double b);

int main(void)
{
    double a = 0, b = 0, c = 0;
    get_cofficients(&a, &b, &c);

    double x1 = 0, x2 = 0;// Roots
    AmountOfRoots NRoots = SolveQuadratic (a, b, c, &x1, &x2);// Amount of roots

    PrintRoots (NRoots, &x1, &x2);

    //printf("%s", AllTestCheck ());
    return 0;
}

/**
* Gets coefficient
*
* @brief Reading a coefficient as long as the input is not a number
* @param [out] out - result of scanning
* @param [in]  sym - name of coefficient
*/

void get_cofficient (double *out, char sym)
{
    printf ("%c = ", sym);
    while (scanf ("%lf", out) != 1)
    {
        printf("Error, try again \n");
        printf ("%c = ", sym);
        while (getchar() != '\n')
            ;

    }
}

/**
* Gets coefficients
* @brief Reading all coefficients by using get_cofficient function
* @param [in] *a - pointer to coefficient a
* @param [in] *b - pointer to coefficient b
* @param [in] *c - pointer to coefficient c
*/

void get_cofficients (double *a, double *b, double *c)
{
    get_cofficient(a, 'a');
    get_cofficient(b, 'b');
    get_cofficient(c, 'c');
}

/**
* Solve Quadratic
* @brief function for solving a quadratic equation (cases considered inside)
* @param [in] a - coefficient a
* @param [in] b - coefficient b
* @param [in] c - coefficient c
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/

AmountOfRoots SolveQuadratic (double a, double b, double c, double *x1, double *x2)
{
    if (Comparison_doubles (a,0) == EQUAL)
    {
        return CalculateLineal (b, c, x1);
    }
    else
    {
        return CalculateSquare (a, b, c, x1, x2);
    }
}

/**
* Calculate Lineal
* @brief Considering the lineal case
* @param [in] b - coefficient b
* @param [in] c - coefficient c
* @param [in] x1 - pointer to the first root
*/

AmountOfRoots CalculateLineal (double b, double c, double *x1)
{
    if (Comparison_doubles (b,0) == EQUAL)
        return InfinityRoots; // infinity
    else
        *x1 = -c / b;
        return OneRoot; //not a quadratic equation, lineal
}

/**
* Calculate Square
* @brief Considering the square case
* @param [in] a - coefficient a
* @param [in] b - coefficient b
* @param [in] c - coefficient c
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/

AmountOfRoots CalculateSquare (double a, double b, double c, double *x1, double *x2)
{
    double d = 0; // discriminant
    d = b * b - 4 * a * c;

    if (d == 0)
    {
        *x1 = -b / (2 * a);

        return OneRoot;// 1 root
    }

    else if (d > 0)
    {
        *x1 = (-b + sqrt(d)) / (2 * a);
        *x2 = (-b - sqrt(d)) / (2 * a);

        return TwoRoots;
    }

    else
        return NoRoots; // no roots
}

/**
* Print Roots
* @brief Print answers
* @param [in] NRoots - amount of roots
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/

void PrintRoots (int NRoots, double *x1, double *x2)
{
    switch (NRoots)
    {
        case InfinityRoots:
            printf ("Infinity roots");
            break;

        case NoRoots :
            printf ("No roots");
            break;

        case OneRoot :
            printf ("One root : x1 = ");
            printf ("%f", *x1);
            break;

        case TwoRoots:
            printf ("First root : x1 = %f\n", *x1);
            printf ("Second root : x2 = %f", *x2);
            break;

        default :
            printf ("ERROR");
    }
}

/**
* TestCheck
* @brief Print error, if a test fails
* @param [in] TestNumber - a number of test
* @param [in] correct_NRoots - expected amount of roots
* @param [in] correct_x1 - expected x1
* @param [in] correct_x2 - expected x2
* @param [in] a - coefficient a
* @param [in] b - coefficient b
* @param [in] c - coefficient c
*/

int TestCheck (int TestNumber, double a, double b, double c, double correct_x1, double correct_x2, int correct_NRoots)
{
    double x1 = 0, x2 = 0;
    int NRoots = SolveQuadratic (a, b, c, &x1, &x2);
    if (NRoots != correct_NRoots || x1 != correct_x1 || x2 != correct_x2)
    {
        printf ("Error test %d, a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf, NRoots = %lf, correct_x1 = %lf, correct_x2 = %lf, correct_NRoots = %lf",
                TestNumber, a, b, c, x1, x2, NRoots, correct_x1, correct_x2, correct_NRoots);
        return -1;
    }
    else
        return 1;

}

/**
* AllTestCheck
* @brief return Success, if everything is alright
*/

char *AllTestCheck (void)
{

    if (
    TestCheck (1, 2, 3, -5, 1, -2.5, 2) &&
    TestCheck (2, 0, 0, -5, 0, 0, -1) &&
    TestCheck (3, 0, 3, 6, -2, 0, 1)
        )
        printf("Success");

}

compare_ Comparison_doubles (double a, double b)
{
    if (a - b > EPS)
        return BIGGER;
    else if (fabs(a - b) < EPS)
        return EQUAL;
    else
        return SMALLER;
}
