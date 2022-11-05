/*SPDX-FileCopyrightText: 2022 Masaki Mitani*/
/*SPDX-License-Identifier: BSD-3-Cause*/
#include <stdio.h>	/*別ファイルから読み込んだ文字列を配列に格納し出力できる*/
#include <ctype.h>	/*別ファイルの読み込み成功！*/

int main(void) {
	char line[100000];
	int i, j, k;

	FILE *f = fopen("result.c", "r");	/*result.c読み込む*/
	while(fgets(line, 100000, f) != NULL) {		/*読み込んだデータを配列lineに格納*/

		for(i=0; i<1000; i++) {	/*30文字以内を出力*/
			printf("%c", line[i]);			/*読み込んだ文字列を表示 読み込んだことを確認*/

			/*if(line == NULL) {
			 * printf("終了です。\n");
			 * break;
			 * } else {
			 * printf("文字以外が入力されました。\nエラー\n");
			 * }*/
		}
	}
	printf("\n");
	/*fclose(f);*/
	return 0;
}
