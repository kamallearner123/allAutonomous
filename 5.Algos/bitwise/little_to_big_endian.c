#include <stdio.h>
int main()
{
	unsigned int a = 0xAABBCCDD;
	unsigned int b= 0;


	b = (a>>24) | (a<<24) | ((a&0x00ff0000)>>8) | ( (a&0x0000ff00)<<8);

	printf("b = %X\n", b);
}
