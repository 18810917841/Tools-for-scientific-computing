#ifndef FUNC_C
#define FUNC_C

extern double low0;
extern double up0;
extern double LOW[NVAR];
extern double UP[NVAR];
extern double NUM[NVAR];

double func(double *params);
double low1(double *params);
double up1(double *params);
#endif
