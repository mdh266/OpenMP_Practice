#include<stdio.h>
#include<stdlib.h>  // NEED THIS FOR MALLOC AND FREE


// Practice with malloc and free

int print(int * x, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%i \n", x[i]);
}


int main()
{
	int N = 5;
	int i;

	int * array = (int *)  malloc(5*sizeof(int));
	
	for(i = 0; i < N; i++)
	{
		array[i] = i;
	}

	print(array,N);

	free(array);

	printf("Freed the array!");

	return 0;
}
