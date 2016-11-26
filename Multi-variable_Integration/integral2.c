#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "main.h"
#include "func.h"
#include "integral1.h"

double m_integral(double x, double *params)
{
    int i = params[NVAR];
    double *new_params = (double *)malloc((NVAR + 1) * sizeof(double));
    memcpy(new_params, params, (NVAR + 1) * sizeof(double));
    new_params[NVAR] = i + 1;
    if (i != 0)
    {
        new_params[i - 1] = x;
        if (i < NVAR)
        {
            LOW[i] = low[i](new_params);
            UP[i] = up[i](new_params);
        }
    }
    else
    {
        LOW[i] = low0;
        UP[i] = up0;
    }

    double result = 0;
    if (i == NVAR)
        result = func(new_params);
    else
        result = s_intgral(LOW[i], UP[i], NUM[i], &m_integral, new_params);
    free(new_params);
    return result;
}
