#include<iostream>
#include<omp.h>

using std::cout;
using std::endl;

// This program fills an array from 0 -> N-1, then adds up the entries
// i.e. sum = 0 + 1 + ... + N-1 
// Then waits for the threads to syncrohnize and then adds one
// NOTE:  Parallel answer will be +1 of the serial answer

int main()
{
	int N = 10;
	int * x = new int[N];
	double sum = 0.0;	

	#pragma omp parallel shared(x)
	{
		// It will still work without schedule, but prints wont be nice
		#pragma omp for schedule(static,5)
		for(int i = 0; i < N; i++)
		{
			#ifdef _OPENMP
			cout << "Thread id = " << omp_get_thread_num() 
			     << " itr = " << i << endl;
			#endif 
			x[i] = i;
		}
		
		#pragma omp barrier
		// Make sure all threads are done
		
		#pragma omp for reduction(+:sum)
		for(int i = 0; i < N; i++)
		{
			sum = sum + x[i];
		}
	
		#pragma omp atomic
		sum += 1;	
	}

	for(int i = 0; i < N; i++)
		cout << x[i] << endl;
	
	cout << "sum = " << sum << endl;
	return 0;
}
	
		
