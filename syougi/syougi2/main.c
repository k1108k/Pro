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
    int which = 0;  //�@��ԕϐ�
	int flag = 2;
	//	���|�P�b�g
	int count1=0,count2=0;
    int p1_poke[40] = { 0 }, p2_poke[40] = { 0 };
    //  ���C�����[�v
	//�@�Ֆʏ�����
	GameInit(koma);
    while (flag != 1) {       
        //�@�Ֆʏo��
        BoardPrint(&count1,&count2,p1_poke,p2_poke,koma);
        //  player�@����            
        Input(&count1,&count2,p1_poke,p2_poke,&which,koma);		
        //  ��Ԍ��
        Change_Player(&which);
        //  computer
        //Computer(koma);
        //  �I������
        flag = CheckOfEnd(koma);
	}
    
	printf("GameEnd!!");
	system("PAUSE");
	return 0;
}
