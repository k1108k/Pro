#include<stdio.h>
#include<conio.h>
//#include <windows.h>
#include"Common.h"

//  盤面出力関数
void BoardPrint(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int koma[][N]) {
    int i, j, k;

    /*HANDLE h;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h, &csbi);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN);*/

	
    
	system("cls");

    //	player2の手駒表示	
    puts("");
    
    for (i = 0;i<40;i++) {
        printf("%5d[", i + 1);
        switch (p2_poke[i]) {
            //  駒なし 
        case KARA:
            printf("　");
            break;
            //  computer駒
        case GYOKU_C:
            printf("空");
            break;
        case HISYA_C:
            printf("天");
            break;
        case KAKU_C:
            printf("飯");
            break;
        case KIN_C:
            printf("ベ");
            break;
        case GIN_C:
            printf("ピ");
            break;
        case KEIMA_C:
            printf("ト");
            break;
        case KYOUSYA_C:
            printf("ク");
            break;
        case HU_C:
            printf("ヤ");
            break;
        case TOKIN_C:
            printf("サ");
            break;
        case NARIGIN_C:
            printf("ナ");
            break;
        case NARIKEI_C:
            printf("ナ");
            break;
        case NARIKYOU_C:
            printf("ナ");
            break;
        case RYU_C:
            printf("ブ");
            break;
        case UMA_C:
            printf("セ");
            break;
        default:
            break;
        }
        printf("] ");
    }
    printf("                                [ player2の手駒 ]");
    puts("");
    puts("");
    puts("");
    
    printf("           ");
    for (i = 0;i < 9;i++) {
        printf("%5d", i+1);
    }
    puts("");
    printf("            ");
    // マスの上端
    for (i = 0;i < N + 2;i++) {
        if (i == 0 || i == N + 1) {
            printf("+");
        }
        else if (i == N) {
            printf("――");
        }
        else {
            printf("――-");
        }
    }
    // 中間マス
    for (i = 0;i < N;i++) {
        // マスの左辺を半角スペースをあける
        puts("");
        printf("           ");
        printf("%d",i+1);
        printf("| ");
        // コマ
        for (j = 0;j < N;j++) {
            switch (koma[i][j]) {
            //  駒なし 
            case KARA:
                printf("　");
                break;
            //  player駒
            case GYOKU_P:  
				//system("color,bat");
                printf("王");
                break;
            case HISYA_P:
                printf("飛");
                break;
            case KAKU_P:
                printf("角");
                break;
            case KIN_P:
                printf("金");
                break;
            case GIN_P:
                printf("銀");
                break;
            case KEIMA_P:
                printf("桂");
                break;
            case KYOUSYA_P:
                printf("香");
                break;
            case HU_P:
                printf("歩");
                break;
			case TOKIN_P:
				printf("と");
                break;
			case NARIGIN_P:
				printf("成");
                break;
			case NARIKEI_P:
				printf("成");
                break;
			case NARIKYOU_P:
				printf("成");
                break;
			case RYU_P:
				printf("龍");
                break;
			case UMA_P:
				printf("馬");
                break;
            //  computer駒
            case GYOKU_C:                  
                printf("空");
                break;
            case HISYA_C:
                printf("天");
                break;
            case KAKU_C:
                printf("飯");
                break;
            case KIN_C:
                printf("ベ");
                break;
            case GIN_C:
                printf("ピ");
                break;
            case KEIMA_C:
                printf("ト");
                break;
            case KYOUSYA_C:
                printf("ク");
                break;
            case HU_C:
                printf("ヤ");
                break;
			case TOKIN_C:
				printf("サ");
                break;
			case NARIGIN_C:
				printf("ナ");
                break;
			case NARIKEI_C:
				printf("ナ");
                break;
			case NARIKYOU_C:
				printf("ナ");
                break;
			case RYU_C:
				printf("ブ");
                break;
			case UMA_C:
				printf("セ");
                break;
            default:
                break;
            }
            printf(" | ");
        }
        //  中間線
        if (i != N - 1) {
            puts("");
            printf("            ");
            for (k = 0; k < N; k++) {
                printf("|――");
            }
            printf("|");
        }
    }

    puts("");
    printf("            ");
    // マスの下端
    for (i = 0;i < N + 2;i++) {
        if (i == 0 || i == N + 1) {
            printf("+");
        }
        else if (i == N) {
            printf("――");
        }
        else {
            printf("――-");
        }
    }

	
    puts("");
	puts("");
	//	player1の手駒表示
	puts("");
	printf("                                [ player1の手駒 ]\n");
	for(i=0;i<40;i++){
		printf("%5d[",i+1);
		switch (p1_poke[i]) {
            //  駒なし 
            case KARA:
                printf("　");
                break;
            //  player駒
            case GYOKU_P:				
                printf("王");
                break;
            case HISYA_P:
                printf("飛");
                break;
            case KAKU_P:
                printf("角");
                break;
            case KIN_P:
                printf("金");
                break;
            case GIN_P:
                printf("銀");
                break;
            case KEIMA_P:
                printf("桂");
                break;
            case KYOUSYA_P:
                printf("香");
                break;
            case HU_P:
                printf("歩");
                break;
			case TOKIN_P:
				printf("と");
                break;
			case NARIGIN_P:
				printf("成");
                break;
			case NARIKEI_P:
				printf("成");
                break;
			case NARIKYOU_P:
				printf("成");
                break;
			case RYU_P:
				printf("龍");
                break;
			case UMA_P:
				printf("馬");
                break;
			default:
				break;
		}
		printf("] ");
	}

	puts("");
    puts("");
}