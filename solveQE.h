#ifndef SQUARE_SOLVER
#define SQUARE_SOLVER

#include "dataQE.h"
#include "scanfQE.h"
#include "printQE.h"

COMPARE ComparisonDoubles (double a, double b);
bool IsZero (double a);

void UsingQuadraticEquation ();
AmountOfRoots SolveQuadratic  (Solving_parameters *data);
AmountOfRoots CalculateLineal (Solving_parameters *data);
AmountOfRoots CalculateSquare (Solving_parameters *data);

#endif // SQUARE_SOLVER
