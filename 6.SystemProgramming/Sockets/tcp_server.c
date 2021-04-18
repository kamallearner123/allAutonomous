#include <stdio.h>
int main()
{
	socket_t sd;
	struct sockaddr_in addr;

	sd = socket(AF_INET, SOCK_STREAM, 0);

	addr.sun_family = AF_UNIX;
	addr
