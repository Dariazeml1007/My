#ifndef SQUARE_DATA
#define SQUARE_DATA

typedef enum
{
    RED,
    GREEN,
    BLUE,
    TURQUOISE,
    WHITE,
    PINK,
    YELLOW

} Color;

// F2  rename
typedef enum
{
    SUCCESS_READ_FILE = 0,
    FAILED_OPEN_ERROR = 1,
    NOT_CLOSED = -1

} StatusFile;

typedef enum
{
    INFINITY_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2

} AmountOfRoots;

typedef enum
{
    GREATER = 1,
    LESS = -1,
    EQUAL = 0

} COMPARE;

typedef enum
{
    TEST_CHECK_ERROR = 1,
    TEST_CHECK_CORRECT = 0

} CHECK;


struct Solving_parameters
{
    double a, b, c;
    double x1, x2;
};

struct Square_parameters
{
    int TestNumber;
    double a, b, c;
    double correct_x1, correct_x2;
    AmountOfRoots correct_NRoots;

};

struct Argv_type
{
    bool is_file    = false;
    bool is_test    = false;
    bool user_file  = false;
    bool is_help    = false;
    bool is_solve   = false;

    int f_index = 0;
};

#endif // SQUARE_DATA
