#include"Common.h"
#include"BoardPrint.h"
//#include<windows.h>
#include<stdio.h>

//  マスの範囲内かチェックする関数
int CheckOfArea(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int koma[][N], char _row_y, char _col_x[100],int *_row_dy,int *_col_dx) {
    *_row_dy = atoi(&_row_y);   //  char型移動後変数の中身をint型に変換
    *_col_dx = atoi(_col_x);        //
    if (*_row_dy == 0 || *_row_dy > 9 || *_col_dx == 0 || *_col_dx > 9) {
        system("cls");
        BoardPrint(count1,count2,p1_poke,p2_poke,koma);
        printf("\n１～９の範囲内で入力してぴょん");
        return 1;   //  再入力
    }
    return 0;   //  おｋ
}