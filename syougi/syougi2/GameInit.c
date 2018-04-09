#include<stdio.h>
#include"Common.h"

//  �Ֆʏ������֐�
void GameInit(int koma[][N]) {
    int i, j;

    for (i = 0;i < N;i++) {
        for (j = 0;j < N;j++) {
            switch (i) {
            case 0:     //  computer���@���ԁ`�ʁ`����
                if (j < 5) {
                    koma[i][j] = j + 11;
                }
                else {
                    koma[i][j] = 10 + N - j;
                }
                break;
            case N - 1:   //  player���@���ԁ`���`����
                if (j < 5) {
                    koma[i][j] = j + 1;
                }
                else {
                    koma[i][j] = N - j;
                }
                break;
            case 1:    //  computer���@��ԁ@�p
                koma[i][1] = HISYA_C;
                koma[i][7] = KAKU_C;
                koma[i][j] = KARA;
                break;
            case N - 2:     //  player���@�p�@���
                koma[i][1] = KAKU_P;
                koma[i][7] = HISYA_P;
                koma[i][j] = KARA;
                break;
            case 2:     //  computer��   ��
                koma[i][j] = HU_C;
                break;
            case N - 3:   //  player���@��
                koma[i][j] = HU_P;
                break;
            case 3:     //  ��Ȃ�
            case 4:
            case 5:
                koma[i][j] = KARA;
                break;
            default:
                break;
            }
        }
    }
}