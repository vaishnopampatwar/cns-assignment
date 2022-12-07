#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
    int tid;
    int i,j;
    int rows,cols;

    printf("Enter Number of Rows of matrices\n");
    scanf("%d",&rows);
    printf("Enter Number of Columns of matrices\n");
    scanf("%d",&cols);

    int a[rows][cols];
    int b[rows][cols];
    int c[rows][cols];

    int *d,*e,*f;

    printf("Enter %d elements of first matrix\n",rows*cols);
    for(i=0;i<rows;i++)
    for(j=0;j<cols;j++)
        {
        scanf("%d",&a[i][j]);
        }

    printf("Enter %d elements of second matrix\n",rows*cols);
    for(i=0;i<rows;i++)
    for(j=0;j<cols;j++)
        {
        scanf("%d",&b[i][j]);
        }

    d=(int *)malloc(sizeof(int)*rows*cols);
    e=(int *)malloc(sizeof(int)*rows*cols);
    f=(int *)malloc(sizeof(int)*rows*cols);

    d=(int *)a;
    e=(int *)b;
    f=(int *)c;
    #pragma omp parallel num_threads(rows*cols)
    {
        tid=omp_get_thread_num();
        f[tid]=d[tid]+e[tid];
    }

    printf("Values of Resultant Matrix C are as follows:\n");

    for(i=0;i<rows;i++)
    for(j=0;j<cols;j++)
        {
        printf("Value of C[%d][%d]=%d\n",i,j,c[i][j]);
        }
    return 0;
}
