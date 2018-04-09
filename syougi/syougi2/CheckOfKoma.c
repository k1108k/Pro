#include<stdio.h>
#include"Common.h"

//  駒を置けるかチェックする関数
int CheckOfKoma(int *which,int _koma[][N],  int _row_dy,  int _col_dx) {
    switch (*which) {   //  手番チェック
    case 0: //  player1
        if (_koma[_row_dy][_col_dx] > 0 && _koma[_row_dy][_col_dx] < 9) {   //  player1の駒
            return 1;   //  自駒に置こうとしているため再入力　caee2も同じ
        }
		if (_koma[_row_dy][_col_dx] > 20 && _koma[_row_dy][_col_dx] < 27) {   //  player1の駒
            return 1;   //  自駒に置こうとしているため再入力　caee2も同じ
        }
        break;

    case 1: //  player2
        if (_koma[_row_dy][_col_dx] > 10 && _koma[_row_dy][_col_dx] < 19) { //  player2の駒
            return 1;
        }
		if (_koma[_row_dy][_col_dx] > 30 && _koma[_row_dy][_col_dx] < 37) { //  player2の駒
            return 1;
        }
        break;
    }
    return 0;
}