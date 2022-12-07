// #include<omp.h>
// #include<stdio.h>
// #include<pthread.h>
// #include<stdlib.h>
// #include<bits/stdc++.h>
// using namespace std;
// void parallelAddition (unsigned N, const double *A, const double *B, double *C)
// {
//     unsigned i;

//     #pragma omp parallel for shared (A,B,C,N) private(i) schedule(static)
//     for (i = 0; i < N; ++i)
//     {
//         C[i] = A[i] + B[i];
//         printf("thread No. %d Number : %d", omp_get_thread_num(), C[i]);  
//         cout<<endl;
//     }
// }
// int main(int argc, char* argv[]){
	
// 	#pragma omp parallel
// 	{
//         int n=5;
//         double a[5]={1,2,3,4,5};
//         double b[5]={11,22,43,54,55};
//         double c[5];
// 		parallelAddition(n,a,b,c);
// 	}
//     return 0;
// }

#include<iostream>
#include<omp.h>
#include<pthread.h>
using namespace std;
int main(){
    int v1[5]={1,2,3,4,5};
    int v2[5]={11,22,43,54,55};
    int v3[5];
    int tid;
    #pragma opm parallel num_threads(5)
    {
        for(int i=0;i<5;i++){
            // tid=omp_get_thread_num();
            v3[i]=v1[i]+v2[i];
            // printf("v3[%d]=%d\n",tid,v3[tid]);
            cout<<" c["<<omp_get_thread_num()<<"]="<<v3[i];
        }
    }
    return 0;
}