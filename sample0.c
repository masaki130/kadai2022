/*SPDX-FileCopyrightText: 2022 Masaki Mitani*/
/*SPDX-License-Identifier: BSD-3-Cause*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
int i, j, k;
double x, y;
	srand((unsigned int)time(NULL));
	/*i = rand() % 10 + 1;*/
	x = (double)rand() / RAND_MAX;
	y = (double)rand() / RAND_MAX;
	printf("x成分：%.1lf\n", x);
	printf("y成分：%.1lf\n", y);
return 0;
}
