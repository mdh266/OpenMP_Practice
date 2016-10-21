#include<stdio.h>
#include<omp.h>

int main()
{
	
	int s = 0, i, n = 5;
	int extra = 2;

	#pragma omp parallel
	{
		#pragma omp for reduction(+:s)
			for(i = 0; i < n; i++)
			{	
				s = s + 1;
			}

		// EACH THREAD WILL DO THE FOLLOWING ONE AT A TIME
		#pragma omp critical 
			s = s + extra; 

		// WITHOUT THE BARRIER, YOU MIGHTGET ONE THREAD FINISHING FIRST
		// AND  PRINTING s = 7, THEN THE NEXT THREAD FINISHING AND 
		// PRINTING s = 9

		#pragma omp barrier
			printf("s = %i \n", s);
	}

//			printf("%i \n", s);
	return 0;
}
		
