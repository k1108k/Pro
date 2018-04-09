#include<stdio.h>
#include"Common.h"
#include "BoardPrint.h"
#include "GameInit.h"
#include "Input.h"
#include "CheckOfKoma.h"
#include "Change_Player.h"
#include "CheckOfEnd.h"
//#include "windows.h"

int main(){
    int koma[N][N];
    int which = 0;  //　手番変数
	int flag = 2;
	//	手駒ポケット
	int count1=0,count2=0;
    int p1_poke[40] = { 0 }, p2_poke[40] = { 0 };
    //  メインループ
	//　盤面初期化
	GameInit(koma);
    while (flag != 1) {       
        //　盤面出力
        BoardPrint(&count1,&count2,p1_poke,p2_poke,koma);
        //  player　入力            
        Input(&count1,&count2,p1_poke,p2_poke,&which,koma);		
        //  手番交代
        Change_Player(&which);
        //  computer
        //Computer(koma);
        //  終了判定
        flag = CheckOfEnd(koma);
	}
    
	printf("GameEnd!!");
	system("PAUSE");
	return 0;
}
