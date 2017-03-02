SHELL=/bin/bash

CC       = mpicc
OPTIMIZE = -O2 -Wall -std=c99
MPICHLIB = -lmpich
MPICHINCL=

NCORE      :=$(grep -c ^processor /proc/cpuinfo)
GSL_INCL    = $(shell pkg-config --cflags gsl)
GSL_LIBS    = $(shell pkg-config --libs gsl)
LAPACK_INCL = -I/usr/include/
LAPACK_LIBS = -llapacke -llapack -lblas -lcblas -lgfortran

EXEC     = integral
OBJS     = main.o integral1.o integral2.o func.o
INCL     = Makefile main.h integral1.h integral2.h func.h
OPTIONS  = $(OPTIMIZE)

CFLAGS   = $(OPTIONS) $(GSL_INCL) $(LAPACK_INCL) $(CBLAS_INCL)
LIBS     = $(GSL_LIBS) $(LAPACK_LIBS) $(CBLAS_LIBS)


$(EXEC):$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

$(OBJS): $(INCL)

clean:
	rm -f $(OBJS) $(EXEC) *~ *~
