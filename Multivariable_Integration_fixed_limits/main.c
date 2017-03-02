#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

# include "func.h"
# include "integral2.h"

int thistask, totaltask, namelen;

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
	double L = up[0]-low[0];
	double I = low[0];
	double delta = L / totaltask;
	low[0] = I + thistask * delta;
	up[0] = I + (thistask+1) * delta;
	num[0] /= totaltask;
		
	double *params = (double *)malloc((nvar+1)*sizeof(double));
	params[nvar] = 0;
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
