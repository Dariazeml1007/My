#ifndef SQUARE_ARGS
#define SQUARE_ARGS


#include "dataQE.h"
#include "ColorsText.h"


void DefineArgv (const int argc, const char *argv[], struct Argv_type *flags);
bool IsNotFlag (const char *argv);

#endif //SQUARE_ARGS
