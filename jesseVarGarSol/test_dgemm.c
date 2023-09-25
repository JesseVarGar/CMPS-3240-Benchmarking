#include <stdio.h>
#include <stdlib.h>

/*
float fdot( int length, float *X, float *Y ) {
  float sum = 0.0;
   
  for( int i = 0; i < length; i++ )
    sum += X[i] * Y[i]; 

  return sum;
}
*/

void dgemm (size_t n, double *A, double *B, double *C)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
			double cij = C[i+j*n];
			for (size_t k = 0; k < n; k++)
				cij += A[i+k*n] * B[k+j*n];
			C[i+j*n] = cij;
		}
}

//  The benchmark
int main( void ) {
  const int N = 1024; // The benchmark runs on a fixed size of work
  printf( "Running DGEMM operation of size %d x 1\n", N );

  double *A = (double *) malloc( N * N * sizeof(double) );      // First vector
  double *B = (double *) malloc( N * N * sizeof(double) );      // Second vector
  double *C = (double *) malloc( N * N * sizeof(double) );

   // Carry out the operation
   dgemm( N, A, B, C );

   // Free up the memory
   free( A );
   free( B );
   free( C );

   return 0;
}
