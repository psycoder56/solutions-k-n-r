#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

char* spaces_to_tab(char* string, int nspaces);
void check(char *result_str);

int main()
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
	result_str = spaces_to_tab(string, nspaces);
	printf("The tabs have been changed into spaces: %s\n", result_str);
}

char* spaces_to_tab(char* string, int nspaces)
{
	char str[strlen(string)+1];
	int count_space = 0;
	int count_tab = 0;
	for ( int i = 0, j = 0;i<=strlen(string);i++,j++ )
	{
		if ( *(string + i) == ' ' )
		{
			--j;
			count_space++;
			continue;
		}
		else
		{
			if ( count_space > 0 )
			{
				count_tab = count_space/nspaces;
				count_space = count_space%nspaces;

				int k = j;
				for (k;k<(j+count_tab);k++ )
				{
					*(str + k) = '\t';
				}
				j = k;

				for (k;k<(j+count_space);k++ )
				{
					*(str + k) = ' ';
				}
				j = k;
				count_space = 0;
			}
			*(str + j) = *(string + i);
		}
	}

	strcpy(string, str);
	//check(string);
	return string;
}


/*
 * Function to check whether the resultant string contains
 * any tabs or not and count the no. of spaces contained in it.
 *
void check(char *result_str)
{
	int no_spaces = 0, no_tabs = 0;
	for ( int i = 0;i<=strlen(result_str);i++ )
	{
		if ( *(result_str + i) == '\t' )
		{
			++no_tabs;
		}
		else if ( *(result_str + i) == ' ' )
		{
			++no_spaces;
		}
	}
	printf("Contains %d spaces & %d tabs\n",no_spaces, no_tabs);
}
*/