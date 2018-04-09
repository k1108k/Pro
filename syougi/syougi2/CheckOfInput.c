#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Common.h"
#include"BoardPrint.h"

//  入力チェック関数
int CheckOfInput(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int *which,int koma[][N],char _row, char _col[100]) {
    int input,row,col;
    
            //  数字を数値に変換        
            row = atoi(&_row);
            col = atoi(_col);
                    
            // 　範囲以外なら最入力        
            if ((row <= 0 || row > 9) || (col <= 0 || col > 9)) {   //範囲チェック関数に置き換え必要
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n１～９の整数値を入力しなさいyo");
                return 1;
            }

           //   動かす駒の確認
            switch(*which){               
            case 0:
                switch (koma[row-1][col-1]) {
                    //  駒なし 
                case KARA:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n駒がない～んす");
                    return 1;
                    //  player駒
                case GYOKU_P:
                    printf("[ 玉 ]");
                    break;
                case HISYA_P:
                    printf("[ 飛車 ]");
                    break;
                case KAKU_P:
                    printf("[ 角 ]");
                    break;
                case KIN_P:
                    printf("[ 金 ]");
                    break;
                case GIN_P:
                    printf("[ 銀 ]");
                    break;
                case KEIMA_P:
                    printf("[ 桂馬 ]");
                    break;
                case KYOUSYA_P:
                    printf("[ 香車 ]");
                    break;
                case HU_P:
                    printf("[ 歩 ]");
                    break;   
				case TOKIN_P:
					printf("[ と金 ]");
					break;   
				case NARIGIN_P:
					printf("[ 成銀 ]");
					break;   
				case NARIKEI_P:
					printf("[ 成桂 ]");
					break;   
				case NARIKYOU_P:
					printf("[ 成香 ]");
					break;   
				case RYU_P:
					printf("[ 龍 ]");
					break;   
				case UMA_P:
					printf("[ 馬 ]");
					break;   
                default:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n敵のコマだよん");
                    return 1;                    
                }
                break;
            case 1:
                switch (koma[row-1][col-1]) {
                    //  駒なし 
                case KARA:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n駒がない～んす");
                    return 1;
                case GYOKU_C:
                    printf("[ カカロット ]");
                    break;
                case HISYA_C:
                    printf("[ 悟天 ]");
                    break;
                case KAKU_C:
                    printf("[ 悟飯 ]");
                    break;
                case KIN_C:
                    printf("[ ベジータ ]");
                    break;
                case GIN_C:
                    printf("[ ピッコロ ]");
                    break;
                case KEIMA_C:
                    printf("[ トランクス（未来） ]");
                    break;
                case KYOUSYA_C:
                    printf("[ クリリンwith18号 ]");
                    break;
                case HU_C:
                    printf("[ ヤムチャ ]");
                    break;
				case TOKIN_C:
					printf("[ ミスターサタン ]");
					break;   
				case NARIGIN_C:
					printf("[ ナメック星人 ]");
					break;   
				case NARIKEI_C:
					printf("[ ナメック星人 ]");
					break;   
				case NARIKYOU_C:
					printf("[ ナメック星人 ]");
					break;   
				case RYU_C:
					printf("[ 魔人ブー ]");
					break;   
				case UMA_C:
					printf("[ セル ]");
					break;   
                default:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n敵のコマだよん");
                    return 1;                    
                }
                break;
            }
            printf("　でおｋ? \nおｋ・・・1　だめぽ・・・0 : ");
            scanf("%d", &input);
            if (input == 1) {
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                return 0;
            }
            
            system("cls");
            BoardPrint(count1,count2,p1_poke,p2_poke,koma);
            return 1;
}