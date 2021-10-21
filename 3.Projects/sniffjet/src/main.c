#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "math.h"

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
        sleep(seq_num);
    }
    return 0;
}
