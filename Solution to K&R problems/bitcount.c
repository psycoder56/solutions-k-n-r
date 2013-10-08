#include <stdio.h>


int bitcount(unsigned int x);

void main()
{
	unsigned int x = 1;
	//bitcount(x);
	printf("The count of bit '1' in %u is %d\n", x, bitcount(x));
}

int bitcount(unsigned int x)
{
	int count = 0;
	if (x)
	{
		count = 1;
	}

	for (x;(x &= (x-1));)
	{
		count++;
	}
	return count;
}