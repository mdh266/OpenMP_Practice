#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int print(int * x, int n);

int main()
{
	int n = 1000;
	int i;
	int sum = 0;

	double * x = (double *) malloc(n*sizeof(int));


	// NOTE:  THIS WILL DISPLAY num threads = 1
	// since not in a parallel region and havent spawned more
	// than one thread.

	#ifdef _OPENMP
		printf("Before parallel region Num threads = %i \n",
			 omp_get_num_threads() );
		printf("Main thread = %i\n", omp_get_thread_num());
	#endif

	// NOTICE YOU MUST DECLARE x to be shared at the beginning of the parallel
	// region and NOT at the workshare construct

	#pragma omp parallel shared(x)	
	{	

		// NOW MORE THAN ONE THREAD HAS BEEN SPAWNED  
		// SO EACH THREAD WILL PRINT OUT THE NUMBER OF THREADS THERE
		// ARE	
	
		#ifdef _OPENMP
			printf("In parallel region: Num threads = %i \n",
				 omp_get_num_threads() );
		#endif


		// WITHOUT THE FOR WORK SHARE CONSTRUCT EACH THREAD WILL
		// DO THE FOR LOOP

		// schedule chunk size tells us how many iterations in a row
		// we will do

		#pragma omp for schedule(dynamic,8)
		for(i = 0; i < n; i++)
		{
			#ifdef _OPENMP
				printf("Thread %i at itr %i \n", 
					omp_get_thread_num(), i);
			#endif
			
			x[i] = (double)i;
		}
	}

	
//	print(x,n);

	free(x);


	return 0;
}

int print(int * x, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%i \n", x[i]);
	}
	
	return 0;
}
