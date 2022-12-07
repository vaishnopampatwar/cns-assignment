#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
static int sum =0;
int main()
{
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
    #pragma omp parallel for
        for(int i=1; i<=100;i++)
        {
                printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
                printf("Sum is %d ",sum);
                cout<<endl;
        }
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    cout<<exec_time;
    return 0;
}