#include<stdio.h>
#include<omp.h>

// This program assigns each thrads value of prod initially equal to
// 1 and then does the for loop in a reductesc manor.  Then at the
// end of the work share multiplies each threads value of prod 
// by the master threads prod to give the answer

int main()
{
	int n = 5;
	int i;
	int prod = 2;

	#pragma omp parallel
	{
		// without the reduction we would still get the same answer... 
		// but it would take much longer?
	
		// IF it was reduction(+:prod) each threads initial value of prod
		// would be set to 0 and then multiplied and then if prod was 
		// initially 2, it would add the results at the end.

		#pragma omp for reduction(*:prod)	
		for(i = 1; i <= n; i++)
		{
			prod = prod*i;

			#ifdef _OPENMP
				printf("Thread %i at itr %i has value %i \n",
					omp_get_thread_num(), i, prod);
			#endif
		}
		
		printf("prod = %i \n ", prod);
	}
	
	return 0;
}
