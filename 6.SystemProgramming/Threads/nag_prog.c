#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global_value = 0;

/* Readonly*/
void * t1(void *ptr)
{

        int local_value_t1 = 100000;
        printf("Thread t1 \n");
        while (local_value_t1--)
        {
          global_value++;
        }
        return NULL;
}

void * t2(void *ptr)
{

        int local_value_t2 = 100000;
        printf("Thread t2 \n");
        while (local_value_t2--)
        {
          global_value++;
        }
        return NULL;
}

int main()
{
        pthread_t tid1, tid2;

        pthread_create(&tid1, NULL, t1, NULL);
        pthread_create(&tid2, NULL, t2, NULL);
        
       // t1(NULL);
       // t2(NULL);
        
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        
        printf("global_value is %d \n", global_value); 

}
