#include<stdio.h>
#include"Common.h"

//  ���u���邩�`�F�b�N����֐�
int CheckOfKoma(int *which,int _koma[][N],  int _row_dy,  int _col_dx) {
    switch (*which) {   //  ��ԃ`�F�b�N
    case 0: //  player1
        if (_koma[_row_dy][_col_dx] > 0 && _koma[_row_dy][_col_dx] < 9) {   //  player1�̋�
            return 1;   //  ����ɒu�����Ƃ��Ă��邽�ߍē��́@caee2������
        }
		if (_koma[_row_dy][_col_dx] > 20 && _koma[_row_dy][_col_dx] < 27) {   //  player1�̋�
            return 1;   //  ����ɒu�����Ƃ��Ă��邽�ߍē��́@caee2������
        }
        break;

    case 1: //  player2
        if (_koma[_row_dy][_col_dx] > 10 && _koma[_row_dy][_col_dx] < 19) { //  player2�̋�
            return 1;
        }
		if (_koma[_row_dy][_col_dx] > 30 && _koma[_row_dy][_col_dx] < 37) { //  player2�̋�
            return 1;
        }
        break;
    }
    return 0;
}