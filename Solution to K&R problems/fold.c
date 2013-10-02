#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000
#define COL 102

void fold(FILE *fp1, FILE *fp2);

void main()
{
	FILE *file_rd, *file_wt;
	fold(file_rd, file_wt);
}

void fold(FILE *fprd, FILE *fpwt)
{
	fprd = fopen("file1.txt", "r");
	fpwt = fopen("file2.txt","w+");

	char content[COL];
	while ( fgets( content, sizeof(content), fprd ) != NULL )
	{
		printf("Content is: %s--\n", content);
		if ( content[strlen(content)-1] == '\n' )
		{
			printf("Succesful");
			break;
		}
		if( (content[strlen(content)-1] == '\t') || (content[strlen(content)-1] == ' ') || (content[strlen(content)-1] == '\0') || (content[strlen(content)-1] == '\n') )
		{
			content[strlen(content)-1] = '\n';
			fputs(content, fpwt);
			fputs("\nfile\n", fpwt);
		}
		else if (content[strlen(content)-1] == '\n')
		{
			fputs(content, fpwt);
		}
		else
		{
			
		}
		memset(content, '\0', sizeof(content));
	}
}