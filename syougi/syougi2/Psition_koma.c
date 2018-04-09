#include"Common.h"

//	駒ポケット変数
int count1,player_poke[];
int count2,player_poke[];

//	駒を置く関数
void Position_koma(int _koma[][N],int _row_i,int _col_i,int _row_dy,int _col_dx){
	//	駒を置き換える
	_koma[_row_dy][_col_dx] = _koma[_row_i][_col_i];
	_koma[_row_i][_col_i] = KARA;

	//	手駒ポケット変数に取った駒を格納

}