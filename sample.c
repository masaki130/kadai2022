/*SPDX-FileCopyrightText: 2022 Masaki Mitani*/
/*SPDX-License-Identifier: BSD-3-Cause*/
#include <stdio.h>	/*動作確認済み*/
#include <ctype.h>	/*総英単語数も表示出来た！！*/	/*文字と回数のソート完了！！*/	/*乱数の表示も出来た！！*/
#include <stdlib.h>	/*乱数で必要*/
#include <time.h>
#include <unistd.h>

int main(void) {
	char line[1000000];
	int i, K;
	int count[1000000];
	int v = 0;

	printf("\n");
	printf("----標準入力した英文の、数字や記号を空白に置換すると以下のようになる。----\n\n");

	for(int k = -1; k < 150; k++) {			/*各出力回数を初期化しておく*/
		count[k+1] = 0;					/*最初の配列には、Aかaの出力回数が入る*/
	}

	FILE *f = fopen("result2.c", "r");	/*result.c読み込む*/
	while(fgets(line, 1000000, f) != NULL) {		/*読み込んだデータを配列lineに格納*/

		for(i = 0; line[i] != '\0'; i++) {		/*ヌル文字判定できた！　文字が間違っていた*/
			if(isalpha(line[i])) {		/*配列がアルファベットかを判定*/	
				printf("%c", line[i]);	/*配列を出力  確認用*/
				/*nNum = i + 1;*/		/*配列の要素数を格納　最終的に全文字数が分かる*/

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
	
	printf("\n");
	printf("----大文字と小文字を区別しない時、頻出順に並べると以下のようになる。----\n\n");

	for(int h = 0; h < NUM; h++) {
		v += count[h];

		printf("%cの出力回数は%d回です。\n",alpha[h], count[h]);	/*文字と回数のソート結果を表示　頻出順*/	
	}
	printf("\n");
	printf("----総英単語数：M = %d個です。----\n\n", v);			/*総英単語数を表示*/
	
	printf("----1次近似の文字列生成----\n\n");
	srand((unsigned int)time(NULL));
	for(int y = 0; y < 15000; y++) {		/**/
		K = 1 + rand() % 117297;
		/*printf("----生成した乱数：k = %d----\n\n", K);*/	/*確認用*/
		if(K < 117297) {
		if(isalpha(line[K])) {		/*この配列がアルファベットの時*/
		        /*printf("5");*/ printf("%c", line[K]);	/*アルファベットを出力*/

		} else if(line[K] == 32){
			printf(" ");		/*スペースの時、空白を出力*/
		} else {			/**/
			/*printf(" ");*/	
		}
		}
	}
	/*sleep(1);*/	
	printf("\n\n");

	return 0;
}
