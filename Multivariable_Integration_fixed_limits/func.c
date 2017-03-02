# include<math.h>
# define PI 3.1415927

int nvar = 6;
double low[6] = {0,0,0,0,0,0};
double up[6] = {1.57,1.57,1.57,1.57,1.57,1.57};
double num[6] = {10,10,10,10,10,10};

double func(double *params)
{
	double R = cos(params[0])* cos(params[1])* cos(params[2])* cos(params[3])* cos(params[4])* cos(params[5]);
	return R;
}
