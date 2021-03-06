#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#define min(x, y) ((x)<(y)?(x):(y))

double* gen_matrix(int n, int m);
int mmult(double *c, double *a, int aRows, int aCols, double *b, int bRows, int bCols);
void compare_matrix(double *a, double *b, int nRows, int nCols);

/** 
    Program to multiply a matrix times a matrix using both
    mpi to distribute the computation among nodes and omp
    to distribute the computation among threads.
*/

int main(int argc, char* argv[])
{
  if(argc>2){
  int nrows, ncols;
  double *aa;	/* the A matrix */
  double *bb;	/* the B matrix */
  double *cc1;	/* A x B computed using the omp-mpi code you write */
  double *cc2;	/* A x B computed using the conventional algorithm */
  int myid, numprocs;
  double starttime, endtime;
  MPI_Status status;
  /* insert other global variables here */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  
  FILE *inputFileOne;
  char *fileOne;
  char *fileTwo;
  FILE *inputFileTwo;
  char *lineTwo = NULL;
  char *read = (char*)malloc(1028);
  int colOne,rowOne,colTwo,rowTwo;
  char* tocken;
  
  if((inputFileOne = fopen("test.txt","r")) != NULL){
	  //continue;
	  printf("here\n");
	  printf(argv[1]);
  }
  if((inputFileTwo = fopen("testTwo.txt","r")) != NULL){
	  //continue;
	  printf("here2");
  }
  if(fgets(read,20,inputFileOne)!= NULL){
	  printf("%s",read);
  }
  tocken = strtok(read," ");
  rowOne = atoi(tocken);
  tocken = strtok(0," ");
  colOne = atoi(tocken);
  printf("%d\n",rowOne);
  printf("%d\n",colOne);
  if(fgets(read,20,inputFileTwo)!= NULL){
  printf("%s",read);
  }
   tocken = strtok(read," ");
   rowTwo = atoi(tocken);
  tocken = strtok(0," ");
  colTwo = atoi(tocken);
  printf("%d\n",rowTwo);
  printf("%d\n",colTwo);
  fileOne = (char*)malloc(rowOne*colOne);
  fileTwo = (char*)malloc(rowTwo*colTwo);
  if(fgets(fileOne,(rowOne*colOne),inputFileOne) != NULL){
	  printf("hereFinal");
  }
  if(fgets(fileTwo,(rowTwo*colTwo),inputFileTwo) != NULL){
	  printf("hereFinal");
  }
  /*if (argc > 1) {
    nrows = atoi(argv[1]);
    ncols = nrows;
    if (myid == 0) {
      // Master Code goes here
      aa = gen_matrix(nrows, ncols);
      bb = gen_matrix(ncols, nrows);
      cc1 = malloc(sizeof(double) * nrows * nrows); 
      starttime = MPI_Wtime();
      /* Insert your master code here to store the product into cc1 */
     /* endtime = MPI_Wtime();
      printf("%f\n",(endtime - starttime));
      cc2  = malloc(sizeof(double) * nrows * nrows);
      mmult(cc2, aa, nrows, ncols, bb, ncols, nrows);
      compare_matrices(cc2, cc1, nrows, nrows);
    } else {
      // Slave Code goes here
    }
  } else {
    fprintf(stderr, "Usage matrix_times_vector <size>\n");
  }
  MPI_Finalize();
  return 0;
  }*/
	}
  else{
	  printf("Imput two file names");
	}
}
