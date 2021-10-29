#include <stdio.h>
#include <string.h>

int main()
{

    char *nums = "abc";
    int len = 5;
    int combs = strlen(nums);

    char *key = malloc(len+1);
    key[len] = 0;
    for (int i=0; i<len-1; i++)
        combs = combs*strlen(nums);



    for (int i =0; i<combs; i++)
    {
        for (j=0; j<strlen(nums); j++)
        {
            key[j] = nums[] 
        }


    }

    printf("Combs = %d\n", combs);
}
