#include <stdio.h>

#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
	key_t tok;
	tok = ftok("./shm.c", 100);

	printf("Tok = %d\n", tok);
	if (tok == -1)
	{
		perror("Issue..");
	}
}

