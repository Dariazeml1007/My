#ifndef SQUARE_SOLVER
#define SQUARE_SOLVER

#include "dataQE.h"

compare_ ComparisonDoubles (double a, double b);
bool IsZero (double a);

AmountOfRoots SolveQuadratic (Solving_parameters *data);
AmountOfRoots CalculateLineal (Solving_parameters *data);
AmountOfRoots CalculateSquare (Solving_parameters *data);

#endif // SQUARE_SOLVER
