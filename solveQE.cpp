#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "solveQE.h"


const double EPS = 1e-7;

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

/**
* Solve Quadratic
* @brief function for solving a quadratic equation (cases considered inside)
* @param [in] a - structure Solving_parameters
*/

AmountOfRoots SolveQuadratic (Solving_parameters *data)
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
* @param [in] a - structure Solving_parameters
*/

AmountOfRoots CalculateLineal (Solving_parameters *data)
{
    if (ComparisonDoubles (data -> b, 0) == EQUAL)
        return InfinityRoots;

    if (ComparisonDoubles (data -> c, 0) == EQUAL)
        data -> x1 = (data -> c) / (data -> b);
    else
        data -> x1 = -(data -> c) / (data -> b);

    return OneRoot;
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
