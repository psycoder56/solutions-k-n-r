/*
 * Incomplete code
 * Exercise 1-22: Fold long input lines into multiple short lines. Currently, working fine
 *								for lines having only a single space between them
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000
#define COL 102

void fold(FILE *fp1, FILE *fp2);
char* remove_leading_whitespaces(char* content);

void main()
{
	FILE *file_rd, *file_wt;
	fold(file_rd, file_wt);
}

void fold(FILE *fprd, FILE *fpwt)
{
	fprd = fopen("file1.txt", "r");
	fpwt = fopen("file2.txt","w+");
	printf("breakpoint start1\n");
	char content[COL];
	//char *content = ( char *)malloc(COL);
	printf("breakpoint start2\n");
	while ( fgets( content, sizeof(content), fprd ) != NULL )
	{
		printf("breakpoint 1\n");
		strcpy(content, remove_leading_whitespaces(content));
		printf("Content : %s", content);
		if ( strlen(content) < COL-1 )
		{
			printf("breakpoint 2\n");
			fputs(content, fpwt);
		}
		//else if( ( *(content + COL) == '\t') || (*(content + COL) == ' ') || (*(content + COL) == '\n') )
		else if( ( content[COL] == '\t') || (content[COL] == ' ') || (content[COL] == '\n') )
		{
			printf("breakpoint 3\n");
			content[strlen(content)-1] = '\n';
			fputs(content, fpwt);
		}
		else
		{
			printf("breakpoint 4\n");
			int seek = 0;
			for (int k = (strlen(content)-1);k >= 0; --k )
			{
				++seek;
				if ( (*(content + k) == ' ') || (*(content + k) == '\t') )
				{
					printf("breakpoint 5\n");
					/*if ( (*(content + k - 1) == ' ') || (*(content + k - 1) == '\t') )
					{
						--seek;
						continue;
					}
					else
					{*/
						*(content + k) = '\n';
						*(content + k + 1) = '\0';
						break;
					//}
				}
			}
			fputs(content, fpwt);
			fseek(fprd, -(seek), SEEK_CUR);
		}
		memset(content, '\0', sizeof(content));
	}
}

char* remove_leading_whitespaces(char* content)
{
	printf("breakpoint 6\n");
	while ( ( *content == ' ' ) || (*content == '\t') )
	{
		++content;
	}
	
	return content;
}