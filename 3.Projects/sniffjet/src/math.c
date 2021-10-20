#include "math.h"

int gen_fib_num(int num) 
{
    static int init = 0;
    int tmp;
    static int a,b;
    static int resp;
    if (num > 0) {
        init = 1;
        a = 0;
        b = 1;
        resp = num;
    }

    while(resp > 1) {
        resp --;
        tmp = a+b;
        a = b;
        b = tmp;
        return tmp;
    }

    if (init == 0) {
        printf("Generator is not initialized\n");
        return -1;
    }

    if (resp <= 0 )
    {
        return -1;
    }

    resp --;
    return a+b;
}
