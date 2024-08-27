#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "solveQE.h"


const double EPS = 1e-7;

COMPARE ComparisonDoubles (double a, double b)
{
    if (a - b > EPS)
        return GREATER;

    else if (fabs (a - b) < EPS)
        return EQUAL;

    else
        return LESS;
}

bool IsZero (double a)
{
    if (fabs (a) < EPS)
        return true;

    return false;
}

void UsingQuadraticEquation ()
{
    double a = 0, b = 0, c = 0;
    GetCofficients (&a, &b, &c);

    double x1 = 0, x2 = 0;// Roots
    Solving_parameters cofficients_roots = {a, b, c, x1, x2};
    AmountOfRoots nRoots = SolveQuadratic (&cofficients_roots);// Amount of roots

    PrintRoots (nRoots, &cofficients_roots);
}

/**
* Solve Quadratic
* @brief function for solving a quadratic equation (cases considered inside)
* @param [in] a - structure Solving_parameters
*/

AmountOfRoots SolveQuadratic (Solving_parameters *data)
{
    assert (data != NULL);
    assert (isfinite (data -> a));
    assert (isfinite (data -> b));
    assert (isfinite (data -> c));


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
* @param [in] a - structure Solving_parameters
*/

AmountOfRoots CalculateLineal (Solving_parameters *data)
{
    if (ComparisonDoubles (data -> b, 0) == EQUAL)
        return INFINITY_ROOTS;

    if (ComparisonDoubles (data -> c, 0) == EQUAL)
        data -> x1 = (data -> c) / (data -> b);
    else
        data -> x1 = -(data -> c) / (data -> b);

    return ONE_ROOT;
}


/**
* Calculate Square
* @brief Considering the square case
* @param [in] a - structure Solving_parameters
*/

AmountOfRoots CalculateSquare (Solving_parameters *data)
{
    double d = 0; // discriminant
    d = (data -> b) * (data -> b) - 4 * (data -> a) * (data -> c);

    switch (ComparisonDoubles(d, 0))
    {
    case EQUAL :

        data -> x1 = -(data -> b) / (2 * (data -> a));

        return ONE_ROOT;

    case GREATER :
    {
        double sqrt_d = sqrt(d);

        data -> x1 = (-(data -> b) + sqrt_d) / (2 * (data -> a));
        data -> x2 = (-(data -> b) - sqrt_d) / (2 * (data -> a));

        return TWO_ROOTS;
    }

    case LESS :

        return NO_ROOTS;

    default :

        assert (false);
    }

}
