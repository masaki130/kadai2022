#include <stdio.h>
#include <math.h>
#define EPS 0.0000001
#define NMAX 100

void newton(double );
double f(double );
double df(double );

int main() {
	double x;
	printf("xに数字を入力して下さい。\n");
	printf("x = ");
	scanf("%lf", &x);
	newton(x);      /*newton関数の結果が代入される*/


	return 0;
}


void newton(double x)
{
	/*printf("x = %lf\n", x);*/
	int n = 0;      /*繰り返しの回数*/
	double d;       /*Δを表す*/

	do {
		d = -f(x) / df(x);
		x += d;
		n++;
	} while(fabs(d) > EPS && n < NMAX);
	if(n == NMAX)
	{
		printf("error!\n");
	} else {
		printf("x = %lf\n", x);
	}
}
