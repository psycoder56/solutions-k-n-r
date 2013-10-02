#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

char* tab_to_space(char *string, int nspaces);
//void check(char *result_str);

void main()
{
	int nspaces;
	printf("How many spaces do you want for 1 tab-space: ");
	scanf("%d", &nspaces);
	
	printf("\nEnter the line\n=============\n");
	char string[MAX];
	fflush(stdin);
	fgets( string, sizeof(string), stdin );
	printf("\n");

	char *result_str = ( char *)malloc(sizeof(string));
	result_str = tab_to_space(string, nspaces);
	printf("The tabs have been changed into spaces: %s\n", result_str);
}

char* tab_to_space(char *string, int nspaces)
{
	char result_string[nspaces*(strlen(string))];
	int i = 0,j = 0;
	for ( i, j; i<=strlen(string); i++,j++ )
	{
		printf("Count : %d", i);
		if ( *(string + i) == '\t' )
		{
			int k = j;
			for ( k;k<=(j+nspaces-1);k++ )
			{
				*(result_string + k) = ' ';
			}
			j = k-1;
		}
		else
		{
			*(result_string + j) = *(string + i);
		}
	}
	strcpy(string, result_string);
	//check(string);
	return string;
}

/*
 * Function to check whether the resultant string contains
 * any tabs or not and count the no. of spaces contained in it.
 *
void check(char *result_str)
{
	int no_spaces = 0;
	for ( int i = 0;i<=strlen(result_str);i++ )
	{
		if ( *(result_str + i) == '\t' )
		{
			printf("String contains tabs\n");
			break;
		}
		else if ( *(result_str + i) == ' ' )
		{
			no_spaces++;
		}
	}
	printf("Contains %d no. of spaces\n",no_spaces);
}
 */