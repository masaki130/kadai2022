/*SPDX-FileCopyrightText: 2022 Masaki Mitani*/
/*SPDX-License-Identifier: BSD-3-Cause*/
#include <stdio.h>	/*動作確認済み*/
#include <ctype.h>	/*最新版*/	/*A～Zまでの最終カウント数を表示できた！*/


int main(void) {
	char line[1000];
	int i;
	int count[110];
	
	printf("\n");
	printf("----標準入力した英文の、数字や記号を空白に置換すると以下のようになる。----\n\n");

	for(int k = -1; k < 100; k++) {			/*各出力回数を初期化しておく*/
		count[k+1] = 0;					/*最初の配列には、Aかaの出力回数が入る*/
	}

	FILE *f = fopen("result.c", "r");	/*result.c読み込む*/
	while(fgets(line, 1000, f) != NULL) {		/*読み込んだデータを配列lineに格納*/

		/*printf("文字を入力してください\n");*/
		/*scanf("%s", line);*/	/*&は要らない！！*/
			
		for(i = 0; line[i] != '\0'; i++) {		/*ヌル文字判定できた！　文字が間違っていた*/
			if(isalpha(line[i])) {		/*配列がアルファベットかを判定*/	
				printf("%c", line[i]);	/*配列を出力  確認用*/

				for(int j = 0; j < 100; j++) {
					if(line[i] == 65 + j || line[i]  == 97 + j) {		/*配列がAか、aに一致する時*/
						count[j] = count[j] + 1;			/*出力回数をカウント*/	/*jに11以降も入っていた*/
						/*printf("%cの合計出力回数は%d回です。\n", 65 + j, count[j]);*/  /*各文字の出力回数をカウント 2回ダプル*/		
												
					}
				}

			} else if(line[i] == 46) {	/*配列にピリオドが入った時*/
				printf(".");
			} else if(line[i] == '\0') {	/*配列にNULL文字が入った時*/
				/*printf("終了\n");*/
				/*break;*/			/*強制終了*/
			} else {
				printf(" ");            /*空白を出力*/
			}
		}
	}

/*whileのループ終了*/
char line2[10000];
int i2;
printf("\n");
printf("\n");
printf("----先頭部の10行を、数字や記号を空白に置換して表示すると以下のようになる。----\n\n");

FILE *c	= fopen("result.c", "r");
while(fgets(line2, 10000, c) != NULL) {           /*読み込んだデータを配列lineに格納*/

	for(i2 = 0; i2 < 1500; i2++) {              /*i2を変えることで、文字数を制限できる！！*/
		if(isalpha(line2[i2])) {          /*配列がアルファベットかを判定*/
			printf("%c", line2[i2]);  /*配列を出力  確認用*/

		} else if(line2[i2] == 46) {      /*配列にピリオドが入った時*/
			printf(".");
		} else if(line2[i2] == '\0') {    /*配列にNULL文字が入った時*/
			                                
		} else {
			printf(" ");            /*空白を出力*/
		}
	}
}

/*whileのループ終了*/


	printf("\n");
	printf("\n");

	int NUM = 26;
	char alpha[200];	/*最終結果の時に使うアルファベットを格納する配列*/

	for(int m = 0; m < NUM; m++) {		/*アルファベットの配列に、各アルファベットのアスキーコードを代入*/
		alpha[m] = 65+m;
	}

	int s, t, tmp, tmp1;					/*ソートの為に変数を3つ用意する*/
	for(s = 0; s < NUM - 1; s++) {
		for(t = s + 1; t < NUM; t++) {
			if(count[t] > count[s]) {
				tmp = count[t];		/*出力回数をソート*/
				count[t] = count[s];
				count[s] = tmp;

				tmp1 = alpha[t];	/*文字をソート*/
				alpha[t] = alpha[s];
				alpha[s] = tmp1;
			}
		}
	}

	printf("----大文字と小文字を区別しない時、頻出順に並べると以下のようになる。----\n\n");
	for(int h = 0; h < NUM; h++) {
		printf("%cの出力回数は%d回です。\n",alpha[h], count[h]);	/*ソートの結果を表示　頻出順*/	
	}

	/*printf("\n");*/
	/*fclose(f);*/
	return 0;
}
