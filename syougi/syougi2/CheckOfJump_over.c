#include"Common.h"

//  ����щz���Ĉړ����Ă��Ȃ����`�F�b�N����֐�
int CheckOfJump_over(int _koma[][N], int _row_i, int _col_i, int _row_dy, int _col_dx) {
    int i, j;
    int dy[] = { -1 , -1 , -1 , 0 , 1 , 1 ,  1 , 0 };   //  �}�X���� ���ォ�玞�v����
    int dx[] = { -1 ,  0 ,  1  , 1 , 1 , 0 , -1, -1 };  //  
     //  i�̐��@��u�P�v�@���u�T�v�@���u�V�v�@�E�u�R�v�@����u�O�v�@�E��u�Q�v�@�E���u�S�v�@�����u�U�v

    switch (_koma[_row_i][_col_i]) {
    case KYOUSYA_P:
        for (i = _row_i-1;i > _row_dy;i--) {
            if (_koma[i][_col_i] != KARA) {
                return 1;
            }            
        }
        break;
    case  KYOUSYA_C:
        for (i = _row_i+1;i < _row_dy;i++) {
            if (_koma[i][_col_i] != KARA) {
                return 1;
            }
        }
        break;
    case HISYA_P:
    case HISYA_C:
	case RYU_P:
	case RYU_C:
        if (_row_i > _row_dy) {
            for (i = _row_i-1;i > _row_dy;i--) {
                if (_koma[i][_col_i] != KARA) {
                    return 1;
                }
            }
        }
        else if (_row_i < _row_dy) {
            for (i = _row_i+1;i < _row_dy;i++) {
                if (_koma[i][_col_i] != KARA) {
                    return 1;
                }
            }
        }        
         else if (_col_i > _col_dx) {
            for (j = _col_i-1;j > _col_dx;j--) {
                if (_koma[_row_i][j] != KARA) {
                    return 1;
                }
            }
        }
        else if (_col_i < _col_dx) {
            for (j = _col_i+1;j < _col_dx;j++) {
                if (_koma[_row_i][j] != KARA) {
                    return 1;
                }
            }
        }
        break;
    case KAKU_P:       
    case KAKU_C:
	case UMA_P:
	case UMA_C:
        for (i = 0;i <= 6;i += 2) {
            for (j = 1;j < 9;j++) {
                if (_row_dy == _row_i + dy[i] * j && _col_dx == _col_i + dx[i] * j) {
                    switch (i) {
                    case 2:
                    case 4:
                        for (j = 1;j <= _col_dx - _col_i - 1;j++) {
                            if (_koma[_row_i + dy[i] * j][_col_i + dx[i] * j] != KARA) {
                                return 1;
                            }
                        }
                        break;
                    case 0:
                    case 6:
                        for (j = 1;j <= _col_i - _col_dx - 1;j++) {
                            if (_koma[_row_i + dy[i] * j][_col_i + dx[i] * j] != KARA) {
                                return 1;
                            }
                        }
                        break;
                    }
                }
            }
        }
        break;
    }
    return 0;
}