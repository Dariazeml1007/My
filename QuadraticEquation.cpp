#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

const double EPS = 1e-7;

typedef enum
{
    InfinityRoots,
    NoRoots,
    OneRoot,
    TwoRoots

} AmountOfRoots;


typedef enum
{
    BIGGER = 1,
    SMALLER = -1,
    EQUAL = 0

} compare_;

typedef enum
{
    TestCheckERROR = 1,
    TestCheckCORRECT = 0

} check_ ;

typedef enum
{
    SUCCESS = 0,
    FAILED = 1
} SystemResult ;


/**
* struct Square_parameters
*
* @brief Description of structure for check function
*/

struct Square_parameters
{
    int TestNumber;
    double a, b, c;
    double correct_x1, correct_x2;
    AmountOfRoots correct_NRoots;

};

struct Solving_parameters
{
    double a, b, c;
    double x1, x2;
};

typedef struct Solving_parameters SP;

void GetCofficient (double *out, char sym);
void GetCofficients (double *a, double *b, double *c);

AmountOfRoots SolveQuadratic (SP *data);
AmountOfRoots CalculateSquare (SP *data);
AmountOfRoots CalculateLineal (SP *data);

void PrintRoots (AmountOfRoots NRoots, SP *data);

check_ TestCheck (struct Square_parameters *data );
check_ AllTestCheck (void);

compare_ ComparisonDoubles (double a, double b);
bool IsZero (double a);


int main(void)
{
    if ( AllTestCheck() != TestCheckCORRECT)
    {
        return FAILED;
    }

    else
    {
        double a = 0, b = 0, c = 0;
        GetCofficients(&a, &b, &c);

        double x1 = 0, x2 = 0;// Roots

        SP cofficients_roots = {a, b, c, x1, x2};


        AmountOfRoots NRoots = SolveQuadratic (&cofficients_roots);// Amount of roots

        PrintRoots (NRoots, &cofficients_roots );
    }

    return SUCCESS;
}

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

/**
* Solve Quadratic
* @brief function for solving a quadratic equation (cases considered inside)
* @param [in] a - coefficient a
* @param [in] b - coefficient b
* @param [in] c - coefficient c
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/

AmountOfRoots SolveQuadratic (SP *data)
{
    assert (data != NULL);
    assert (isfinite(data -> a));
    assert (isfinite(data -> b));
    assert (isfinite(data -> c));



    if (ComparisonDoubles ((data -> a),0) == EQUAL)
    {
        return CalculateLineal (data);
    }
    else
    {
        return CalculateSquare (data);
    }
}

/**
* Calculate Lineal
* @brief Considering the lineal case
* @param [in] b - coefficient b
* @param [in] c - coefficient c
* @param [in] x1 - pointer to the first root
*/

AmountOfRoots CalculateLineal (SP *data)
{
    if (ComparisonDoubles (data -> b,0) == EQUAL)
        return InfinityRoots;
    else
        data -> x1 = -(data -> c) / (data -> b);
        return OneRoot;
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

AmountOfRoots CalculateSquare (SP *data)
{
    double d = 0; // discriminant
    d = (data -> b) * (data -> b) - 4 * (data -> a) * (data -> c);

    switch (ComparisonDoubles(d, 0))
    {

    case EQUAL :

        data -> x1 = -(data -> b) / (2 * (data -> a));

        return OneRoot;

    case BIGGER :

        data -> x1 = (-(data -> b) + sqrt(d)) / (2 * (data -> a));
        data -> x2 = (-(data -> b) - sqrt(d)) / (2 * (data -> a));

        return TwoRoots;

    case SMALLER :

        return NoRoots;

    default :

        assert(false);


    }

}

/**
* Print Roots
* @brief Print answers
* @param [in] NRoots - amount of roots
* @param [in] x1 - pointer to the first root
* @param [in] x2 - pointer to the second root
*/

void PrintRoots (AmountOfRoots NRoots, SP *data)
{
    assert (data != NULL);


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
            printf ("%f", data -> x1);
            break;

        case TwoRoots:
            printf ("First root : x1 = %f\n", data -> x1);
            printf ("Second root : x2 = %f", data -> x2);
            break;

        default :
            assert(false);
    }
}

/**
* TestCheck
* @brief Print error, if a test fails
* @param [in] struct Square_parameters data - struct for check

*/

check_ TestCheck (struct Square_parameters *data)
{
    double x1 = 0, x2 = 0;
    SP test_param = {(data -> a), (data -> b), (data -> c), x1, x2};
    AmountOfRoots NRoots = SolveQuadratic (&test_param);

    if (IsZero(NRoots - (data -> correct_NRoots)) && IsZero((test_param.x1) - (data -> correct_x1)) && IsZero((test_param.x2) - (data -> correct_x2)))
    {
        printf("Test number %d successfully completed \n", data -> TestNumber);
        return TestCheckCORRECT;
    }
    else
      printf ("Error test %d, a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf "
              "NRoots = %d, correct_x1 = %lf, correct_x2 = %lf, correct_NRoots = %d\n",
                (data -> TestNumber), (data -> a), (data -> b), (data -> c), (test_param.x1), (test_param.x2),
                NRoots, (data -> correct_x1), (data -> correct_x2) , (data -> correct_NRoots));
    return TestCheckERROR;

}

/**
* AllTestCheck
* @brief return Success, if everything is alright
*/

check_ AllTestCheck (void)
{
    printf("Tests are running \n");
    check_ flag = TestCheckCORRECT;
    struct Square_parameters array_sp [] =
    {
        {1, 1, 0, -4, 2, -2, TwoRoots},
        {2, 0, 0, 3, 0, 0, InfinityRoots},
        {3, 0, 4, 2, -0.5, 0, OneRoot},
        {4, 1, -0.7, 0.1, 0.5, 0.2, TwoRoots},
        {5, 1, -5, 0, 5, 0, TwoRoots},
        {6, 1, 5, 7, 0, 0, NoRoots},
        {7, 0 , 0 , 0, 0 , 0, InfinityRoots}
    };

    int length = sizeof(array_sp)/sizeof(array_sp[0]);

    for (int i = 0; i < length; i++)
    {
        if ((TestCheck(&(array_sp[i]))) == TestCheckERROR)
            flag = TestCheckERROR;
    }
    if (flag == TestCheckCORRECT)

        printf("All tests successfully completed \n");

    else

        printf ("Some tests failed/n");


    return flag;
}

compare_ ComparisonDoubles (double a, double b)
{
    if (a - b > EPS)
        return BIGGER;

    else if (fabs(a - b) < EPS)
        return EQUAL;

    else
        return SMALLER;
}

bool IsZero (double a)
{
    if (fabs(a) < EPS)
        return true;
    return false;
}
