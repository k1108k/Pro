#include<stdio.h>
#include"Common.h"

//@I—¹”»’èŠÖ”
int CheckOfEnd(int koma[][N]){
	int i,j,flag=0;
	
	//	‰¤è

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(koma[i][j] == GYOKU_P || koma[i][j] == GYOKU_C){
				flag++;
			}
		}
	}

	return flag;
}