#include <sys/mman.h>
#include <stdio.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <unistd.h>

int main()
{
	char *ptr;

	int fd;

	fd = open("./sample.txt",O_CREAT);

	ptr = mmap(NULL, 1024*2014, PROT_NONE, MAP_SHARED, fd, 0);
	*ptr = 'H';
	close(fd);
	return 0;
}
