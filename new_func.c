#include <stdio.h>
#include <math.h>       /*オリジナルnewton.cの方に関数のプロト宣言を書いておけば、関数を別ファイルで読み込める！！*/

double f(double x)
{
	return( x + cos(x));
}

double df(double x)
{
	return(1. - sin(x));

}
