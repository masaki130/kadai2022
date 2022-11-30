#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define c 10
#define m 10

int main() 
{
	int i, x;
	srand((unsigned)time(NULL));
	for(i = 0; i < c; i++)
	{
		x = (int)(rand() / (double)RAND_MAX * m);
		printf("%d\n", x);
	}
	return 0;
}
