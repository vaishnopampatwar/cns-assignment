#include<omp.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


int main(){
	
	#pragma omp parallel num_threads(5)
	{
		printf("thread No. %d  Hello World\n", omp_get_thread_num());
	}
    return 0;
}