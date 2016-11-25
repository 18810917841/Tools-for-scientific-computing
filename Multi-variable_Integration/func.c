# include<math.h>
# include "main.h"

double low0 = 0;
double up0 = 1;
double num[NVAR] = {10,10};

double low1(double *params)
{
	return sqrt(1-params[0]*params[0]);
}

double up1(double *params)
{
	return -sqrt(1-params[0]*params[0]);
}


double func(double *params)
{
	double R = cos(params[0])* cos(params[1])* cos(params[2])* cos(params[3])* cos(params[4])* cos(params[5]);
	return R;
}
