#include <stdio.h>
#include <syslog.h>
int main()
{
	openlog(NULL, 10, NULL);
	syslog("FAC", "Error %d", 100);
	closelog();
}
