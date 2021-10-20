#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "math.h"

int main(int argc, char **argv)
{
    int num =10;

    printf("Current user : %s\n", getenv("USER"));
    
    if (strncmp("root", getenv("USER"), strlen("root")) != 0) {
        printf("Sorry... you are not root user\nGoing to Quit\n");
        printf("Please run as root or sudo root\n");
        return 100;
    }

    printf("Fib num = %d\n", gen_fib_num(num));

    while(num--) {
        printf("Fib num = %d\n", gen_fib_num(-1));
    }
    return 0;
}
