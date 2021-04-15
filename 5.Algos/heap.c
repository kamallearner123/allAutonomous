#include <stdio.h>
#define MAX 100
#define swap(a,b) {
int tail = 0;
int arra[MAX];

void insert(int a)
{
	int tmp_tail = tail;
	arra[tail] = a;

	while(tmp_tail > 0)
	{
		if (arra[tmp_tail]>arra[(tmp_tail-1)/2]) 
		{
			arra[tmp_tail] = arra[(tmp_tail-1)/2];
			arra[(tmp_tail-1)/2] = a;
		}
		tmp_tail = (tmp_tail-1)/2;
	}

	tail ++;
}

void print_array() 
{
	int i;
	for (i=0; i<tail; i++)
		printf("%d ",arra[i]);
}


int pop()
{
	int loc = 0;
	int ret_val = arra[loc];

	if (tail ==0)
	{
		printf("Empty...\n");
		return -1;
	}

	if (tail==1)
	{
		tail=0;
		return ret_val;
	}

	if (tail == 2)
	{
		arra[0] = arra[1];
		return ret_val;
	}


	while(loc<tail)
	{
		if (arra[(loc+1)*2] >arra[(loc+1)*2-1])
			arra[loc] = arra[(loc+1)*2];
		else
			arra[loc] = arra[(loc+1)*2-1];


	}
	tail--;

}

int main()
{
	int data = 0;

	int max;
	printf("How many ?");
	scanf("%d", &max);
	for (int i=0; i<max; i++)
	{
		scanf("%d",&data);
		insert(data);
	}

	print_array();
		
}
