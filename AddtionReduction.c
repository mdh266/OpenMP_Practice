#include<stdio.h>
#include<omp.h>

int main()
{
	double asum = 0.0;
	int i, n = 5;

	#pragma omp parallel
	{
		// NOTICE: if it was changed to (*,asum) final asum would be initialized
		// and then multiply the threads private asums together giving 0 for ans?

		// ALSO: Each THREAD has their own copy of asum which they keep doing
		// the for loop operation over and over again until you reach the end.
		
		#pragma omp for reduction(+:asum) // schedule(static)
		for(i = 0; i < n; i++)
		{
			asum = asum + i;
			printf("Thread %i 's at itr %i has value of asum = %f \n"
				,omp_get_thread_num(),i,asum);

		}
	}
	
	printf("asum = %f \n", asum);
}

