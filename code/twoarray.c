#include<stdio.h>
#include<omp.h>
// #include<pthread.h>
int main(){
    int v1[5]={1,2,3,4,5};
    int v2[5]={11,22,43,54,55};
    int v3[5];
    int tid;
    #pragma omp parallel
    {
        tid=omp_get_thread_num();
        v3[tid]=v1[tid]+v2[tid];
        printf("v3[%d]=%d\n",tid,v3[tid]);
    }
    return 0;
}