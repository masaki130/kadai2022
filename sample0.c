/*SPDX-FileCopyrightText: 2022 Masaki Mitani*/
/*SPDX-License-Identifier: BSD-3-Cause*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
int i, j;
int Max = 10;
int count = 0;
double x, y, k;
	srand((unsigned int)time(NULL));
	/*i = rand() % 10 + 1;*/
	for(j = 0; j < Max; j++) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		if((x-0.5) * (x-0.5) + (y-0.5) * (y-0.5) <= 0.5 * 0.5) {
			/*printf("(x,y)=(%.1lf,%.1lf)\n", x, y);*/
			count += 1;

		}
	}
	/*printf("点が円の内側に入る回数：%d\n", count);*/
	k = (double)count / (double)Max;	/*k:円の面積*/
	printf("%.1lf\n", k);
return 0;
}
