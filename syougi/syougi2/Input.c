#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"Common.h"
#include"CheckOfKoma.h"
#include<stdlib.h>
#include"CheckOfInput.h"
#include"CheckOfArea.h"
#include"BoardPrint.h"
#include"CheckOfKoma_scope.h"
#include"CheckOfJump_over.h"
#include"Position_koma.h"
#include"CheckOfTegoma.h"

//  player入力関数
int Input(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int *which,int koma[][N]) {
    char row_c, col_c[100];
    char row_y, col_x[100];
    int row_i, col_i;           //  自駒マス変数
    int row_dy=0, col_dx=0;     //  移動後マス変数
    int i,flag = 1;
	int tegoma,num;
    int zerohan, hikaku;
    int tegoma_num,input;   //  手駒指定用の関数
    
    
    while (flag) {		
        puts("");        
        rewind(stdin);
        //scanf("%*[^\n]%*c"); //なぜこっちでは入力待ちになる?
        printf("《 player %d の手番 》\n", (*which) + 1);
        printf("移動する駒     （行）（列）\n");
        printf("手駒を使う場合 （０）（手駒番号）: ");
        scanf("%c %s", &row_c,col_c);        
        //scanf("%*[^\n]%*c");
        rewind(stdin);
        //  手駒を使う選択をされた場合   １文字目0を入力
        zerohan = atoi(&row_c);
        if (zerohan == 0) {      // 0.1を１つめに入力するとどうなるか？                  
            if (row_c != '0') {
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                printf("\n整数値を２つ入力してぴょん");
                continue;
            }                      
            //  ２つ目の入力が２桁までの整数値かチェック         
            
            //  修正！！
			if (col_c[1] == '\0') {
                if(col_c[0] < '1' || col_c[0] > '9'){
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n手駒番号は１～４０の間で入力してぽ");
                    continue;
				}
			}
			if(col_c[1] != '\0') {
                if(!(col_c[0] < '1' && col_c[0] > '9')){
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n手駒番号は１～４０の間で入力してぽ");
                    continue;
				}
			}
            if (strlen(col_c) > 2 || (!((col_c[1] >= '0' && col_c[1] <= '9') || col_c[1] == '\0'))) {
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n手駒番号は１～４０の間で入力してぽ");
                    continue;           
            }    
            tegoma_num = atoi(col_c);
            switch (*which) {
            case 0:
                switch (p1_poke[tegoma_num-1]) {
                    //  駒なし 
                case KARA:
                    system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\nそこに手駒は入ってないよ～ん");
                    continue;
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
                    break;
                }
                break;
            case 1:
                switch (p2_poke[tegoma_num - 1]) {
                    //  駒なし 
                case KARA:
                    system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\nそこに駒はない～んす");
                    continue;
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
                    break;
                }
                break;
            }
            printf("　でおｋ? \nおｋ・・・1　だめぽ・・・0 : ");
            scanf("%d", &input);
            if (input == 1) {
                CheckOfTegoma(tegoma_num, count1, count2, p1_poke, p2_poke, koma, which);
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                return 0;
            }
            else {
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                continue;
            }                       
        }
        //  手駒を使わない選択をされた場合
        if (strlen(col_c) != 1) {
            system("cls");
            BoardPrint(count1,count2,p1_poke,p2_poke,koma);
            printf("\n整数値でイレテピョン");            
            continue;
        }        
        flag = CheckOfInput(count1,count2,p1_poke,p2_poke,which,koma,row_c,col_c);  //  自駒か確認
        if (flag == 1) {
            continue;
        }
        row_i = atoi(&row_c) - 1;       //入力値は＋１のためー１して配列の要素番号にあわせる
        col_i = atoi(&col_c[0]) - 1;    //

        
        //  どこに移動するかを確認する
        flag = 1;
        while (flag) {
            while (flag) {  //  入力チェック        
                puts("");
                rewind(stdin);
                printf("どこに移動しゅる? （行）（列） :  ");
                scanf("%c %s", &row_y, col_x);
                //scanf("%*^[\n]%*c");
                rewind(stdin);
                if (strlen(col_x) != 1) {   //　小数または文字が入力されたのでダメ
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n整数値を入力してぴょん");
                    continue;
                }
                flag = CheckOfArea(count1,count2,p1_poke,p2_poke,koma, row_y, col_x, &row_dy, &col_dx);   //  戻り値０なら入力チェックおｋ           
            }

            row_dy--;    //入力値は＋１のためー１して配列の要素番号にあわせる
            col_dx--;     //

            //  駒能力の範囲内の移動か           
            flag = CheckOfKoma_scope(koma, row_i, col_i, row_dy, col_dx);    //　戻り値0ならおｋ
            if (flag == 1) {     //  １なら移動先を再入力
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\nその駒の移動範囲を超えているよん");
                continue;
            }

            
            //  移動先に自駒がないかチェック            
            flag = CheckOfKoma(which, koma,  row_dy, col_dx);   //　移動できるか確認
            if (flag == 1) {     //  １なら移動先を再入力
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\nそこには自分の駒があるよん");  
                continue;
            }

            // 移動方向の駒を飛び越えていないかチェック
            flag = CheckOfJump_over(koma, row_i, col_i, row_dy, col_dx);
            if (flag == 1) {     //  １なら移動先を再入力
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n駒を飛び越えているよん");
                
            }
                  
        }

		//	駒を置き換える
        Position_koma(count1,count2,p1_poke,p2_poke,which,koma,row_i,col_i,row_dy,col_dx);
		system("cls");
		BoardPrint(count1,count2,p1_poke,p2_poke,koma); 
	}
}
