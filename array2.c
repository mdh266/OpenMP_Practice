#include<stdio.h>
#include<stdlib.h>


// SAME AS ARRAY1.C but uses calloc instead of malloc

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

	int * array = (int *)  calloc(5, sizeof(int));
	
	for(i = 0; i < N; i++)
	{
		array[i] = i;
	}

	print(array,N);

	free(array);

	printf("Freed the array!");

	return 0;
}
