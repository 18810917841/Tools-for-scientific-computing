#include <math.h>
#include "main.h"

double low0 = -1;
double up0 = 1;
double NUM[NVAR] = {100, 100};
double LOW[NVAR] = {0, 0};
double UP[NVAR] = {0, 0};

double low1(double *params)
{
    if (params[0] <= 1 && params[0] >= -1)
        return -sqrt(1 - params[0] * params[0]);
    else
        return 0;
    // return 0;
}

double up1(double *params)
{
    if (params[0] <= 1 && params[0] >= -1)
        return sqrt(1 - params[0] * params[0]);
    else
        return 0;
    // return 1.57;
}

double func(double *params)
{
    // double R = cos(params[0]) * cos(params[1]);
    double R = 1;
    return R;
}
