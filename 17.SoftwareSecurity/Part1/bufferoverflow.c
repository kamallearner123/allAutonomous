#include <stdio.h>
#include <string.h>

void check_authenticated (char *pass) {

    int validated = 0;
    char buff[3];
    strncpy(buff, pass,4);
    printf("validated = %d\n", validated);
    return;
}

int main()
{
    char *pass = "1234";
    check_authenticated(pass);
    return 0;
}
