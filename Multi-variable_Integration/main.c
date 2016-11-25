#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

# include "main.h"
# include "func.h"
# include "integral2.h"

int thistask, totaltask, namelen;
double (* low[NVAR]) (double *);
double (* up[NVAR]) (double *);

int main(int argc, char **argv)
{
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &thistask);
	MPI_Comm_size(MPI_COMM_WORLD, &totaltask);
	MPI_Get_processor_name(proc_name, &namelen);
	MPI_Barrier(MPI_COMM_WORLD);
	
	clock_t start, finish; 
	double Total_time; 
	
	double integral_value = 0;
	double L = up0-low0;
	double I = low0;
	double delta = L / totaltask;
	low0 = I + thistask * delta;
	up0= I + (thistask+1) * delta;
	num[0] /= totaltask;

	low[1] = low1;
	up[1] = up1;

		
	double *params = (double *)malloc((NVAR+1)*sizeof(double));
	params[NVAR] = 0;
	start = clock(); 
	double result = m_integral(0,params);
	finish = clock();
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Reduce(&result, &integral_value, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	Total_time = (double)(finish-start) / CLOCKS_PER_SEC;
	if(thistask ==0)
	{
		printf( "%f seconds\n", Total_time); 
		printf("integral_value = %lf \n",integral_value);
	}
	MPI_Finalize();
}
