#include <stdio.h>	/*gnuplotでグラフ化してみよう！*/
#include <stdlib.h>
#include <time.h>
#define c 10	/*cを大きくしていき平均値を求める*/
#define m 10	/*0からmまでの乱数を表示*/

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
