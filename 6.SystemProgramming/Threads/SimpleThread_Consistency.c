
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int jobs_done;

void * t1(void *ptr)
{
    int itrs = 10000;
    while(itrs--)
        jobs_done++;
}

void * t2(void *ptr)
{
    int itrs = 10000;
    while(itrs--)
        jobs_done++;
}
int main()
{
    pthread_t tid1, tid2;

        pthread_create(&tid1, NULL, t1, NULL);
        pthread_create(&tid2, NULL, t2, NULL);


        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
    printf("jobs_done = %d\n", jobs_done);
while(1);
}

/*
 *
 * 1) Thread id
 * 2) PC, SP, Regs
 * 3) Signal mask
 */
