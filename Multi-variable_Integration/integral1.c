#include <stdio.h>
#include <math.h>

double s_intgral(double (*F)(double, double *), double *params, double a, double b, int N)
{
    double h = (b - a) / 2.0 / N;
    int i = 0;
    double x_0 = a;
    double x_1 = a + h;
    double x_2 = a + 2 * h;
    double f_0 = F(x_0, params);
    double f_1 = F(x_1, params);
    double f_2 = F(x_2, params);
    double Sum = 0;
    double sum = 0;
    for (i = 0; i < N; i++)
    {
        sum = f_0 / 3 + 4 * f_1 / 3 + f_2 / 3;
        sum *= h;
        Sum += sum;
        x_0 = x_2;
        x_1 = x_0 + h;
        x_2 = x_1 + h;
        f_0 = f_2;
        f_1 = F(x_1, params);
        f_2 = F(x_2, params);
    }
    return Sum;
}
