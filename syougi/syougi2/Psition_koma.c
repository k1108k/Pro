#include"Common.h"

//	��|�P�b�g�ϐ�
int count1,player_poke[];
int count2,player_poke[];

//	���u���֐�
void Position_koma(int _koma[][N],int _row_i,int _col_i,int _row_dy,int _col_dx){
	//	���u��������
	_koma[_row_dy][_col_dx] = _koma[_row_i][_col_i];
	_koma[_row_i][_col_i] = KARA;

	//	���|�P�b�g�ϐ��Ɏ��������i�[

}