#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "math.h"
#include "hash_gen.h"

int main(int argc, char **argv)
{
    int num =10, seq_num;
    time_t t1, init_time;

    printf("Current user : %s\n", getenv("USER"));
    
    if (strncmp("root", getenv("USER"), strlen("root")) != 0) {
        printf("Sorry... you are not root user\nGoing to Quit\n");
        printf("Please run as root or sudo root\n");
        return 100;
    }

    printf("Fib num = %d\n", gen_fib_num(num));

    (void)time(&init_time);

    while(num--) {
        printf("Time in seconds = %lu\n", time(&t1));
        seq_num = gen_fib_num(-1);
        printf("Fib num = %d\n", seq_num);
        if (0 > seq_num)
            break;
        //sleep(seq_num);
    }



    /*Testing hash generator */
    printf("Key 1 = %s\n",get_token("ab", 3));

    int index = 1;
    char *key;
    while(key = get_token(NULL,0))
    {
        printf("Key %d = %s\n", index, key);
        index++;
    }

    return 0;
}
