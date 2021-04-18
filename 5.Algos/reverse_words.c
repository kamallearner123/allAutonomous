#include <stdio.h>
#include <string.h>

void reverse_subword(char *data, int len)
{

	printf("sub string before:%s:\n Len = %d\n", data, len);
	char tmp;
                        for (int i = 0; i<len/2; i++)
                        {
                                tmp = data[i];
                                data[i] = data[len-i-1];
                                data[len-i-1] = tmp;
                        }
	printf("sub string = :%s:\n", data);
}

void reverse_words(char *data)
{
	int len = 0;
	char *tmpptr=data;
	reverse_subword(data, strlen(data));
	int j=0, start=0;

	while (1)
	{	
		printf("c = %c\n",data[j]);
		if (data[j] == ' ' || data[j] == 0)
		{
			reverse_subword(data+start, len);
			start +=len+1;
			len = -1;

			if (data[j] == 0)
				return;
		}
		len ++;
		j++;
	}

}


int main()
{
	char data[] = "Hello Kamal";

	reverse_words(data);
	printf("After reverse = %s\n", data);

}
