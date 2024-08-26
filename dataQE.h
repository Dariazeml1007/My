#ifndef SQUARE_DATA
#define SQUARE_DATA

typedef enum
{
    Red,
    Green,
    Blue,
    Turquoise,
    White,
    Pink,
    Yellow

} color;

typedef enum
{
    Success_Read_File = 0,
    Failed_Open_Error = 1,
    Not_Closed = -1

} Status_file;

typedef enum
{
    InfinityRoots = -1,
    NoRoots = 0,
    OneRoot = 1,
    TwoRoots = 2

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

#endif // SQUARE_DATA
