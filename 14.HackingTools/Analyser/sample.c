#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile const int a=100;

volatile const int *b;

/* Readonly*/
void * t1(void *ptr)
{
	//*b = 400; //By mistake: Avoid//
	sleep(2);
	printf("Thread t1: *b = %d\n", *b);	
	sleep(100);
	return NULL;
}

/*interrupt*/
void * t2(void *ptr)
{
	int *c = (int *)b; //Intentional//
	*c = 300;
	printf("Thread t2: *b = %d\n", *b);	
	sleep(100);
	return NULL;
}

int main()
{
	b = &a;
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, t1, NULL);
	pthread_create(&tid2, NULL, t2, NULL);
	sleep(5);

}
