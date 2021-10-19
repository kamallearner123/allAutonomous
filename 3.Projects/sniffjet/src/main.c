#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    printf("Current user : %s\n", getenv("USER"));
    
    if (strncmp("root", getenv("USER"), strlen("root")) != 0) {
        printf("Sorry... you are not root user\nGoing to Quit\n");
        printf("Please run as root or sudo root\n");
        return 100;
    }
    return 0;
}
