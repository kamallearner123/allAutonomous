#include <stdio.h>
#include <pthread.h>

#define MAX_COL 10
#define MAC_ROW 10

void one_job(int *a, int *b, int row, int col, int size, int *result)
{
	int sum = 0;
	for (int i=0; i<size; i++)
	{
		sum += *(a+row+i) *(*(b+(col*i)));
	}
	*result = sum;
}

void mat_mul(int *a, int *b, int *c, int m, int n, int x, int y)
{
	int  i,j;
	if (n!=x)
	{
		printf("Not suitable!!!\n");
		return;
	}

	for (i=0; i<m; i++)
	{
		for (j=0; j<y; j++)
		{
			one_job(a,b+j,(i*m),y,n,(c+(i*n)+j));
		}
	}

	return;
}

int main()
{
	int a[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
	int b[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
	int c[3][3] = {0};

	mat_mul((int*)&a, (int *)*b, (int*)&c, 3,3,3,3);

	int i,j;

	for (i=0; i<3; i++)
    {
		for(j=0; j<3; j++)
        {
			printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    pthread_t pid;

}
