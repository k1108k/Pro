#include"Common.h"
#include"BoardPrint.h"
//#include<windows.h>
#include<stdio.h>

//  �}�X�͈͓̔����`�F�b�N����֐�
int CheckOfArea(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int koma[][N], char _row_y, char _col_x[100],int *_row_dy,int *_col_dx) {
    *_row_dy = atoi(&_row_y);   //  char�^�ړ���ϐ��̒��g��int�^�ɕϊ�
    *_col_dx = atoi(_col_x);        //
    if (*_row_dy == 0 || *_row_dy > 9 || *_col_dx == 0 || *_col_dx > 9) {
        system("cls");
        BoardPrint(count1,count2,p1_poke,p2_poke,koma);
        printf("\n�P�`�X�͈͓̔��œ��͂��Ă҂��");
        return 1;   //  �ē���
    }
    return 0;   //  ����
}