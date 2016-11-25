#include <stdlib.h>
#include <math.h>
#include <string.h>

# include "func.h"
# include "integral1.h"

double m_integral(double x, double *params)
{
	int i = params[nvar];
	double *new_params = (double *)malloc((nvar+1)*sizeof(double));
	memcpy(new_params, params, (nvar+1)*sizeof(double));
	new_params[nvar] = i + 1;
	if(i != 0)
		new_params[i-1] = x;

    double result = 0;
	if(i == nvar)
		result = func(new_params);
	else
		result = s_intgral(&m_integral, new_params, low[i], up[i], num[i]);
    free(new_params);
    return result;
}
