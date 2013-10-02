#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char *string);

void main()
{
	char s[] = {"Hello Prashant\n I am Prashant"};
	printf("String is %s\n", s);
	char *str = (char *)malloc(sizeof(s));
	str = reverse(s);
	printf("String is %s\n", str);
}

char* reverse (char *string)
{
	int len = strlen(string);
	char rev_string[len];
	int i = 0;
	for (i = 0;i<len;i++ )
	{
		*(rev_string + i) = *(string + (len-i-1));
	}
	*(rev_string + i) = '\0';
	strcpy(string, rev_string);
	return string;
}