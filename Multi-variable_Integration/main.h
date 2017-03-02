#ifndef MAIN_H
#define MAIN_H
#define NVAR 2
#define PI 3.1415927

extern int thistask, totaltask, namelen;
extern double (*low[NVAR])(double *);
extern double (*up[NVAR])(double *);

#endif