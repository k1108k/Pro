#include"Common.h"
#include<stdio.h>
#include"BoardPrint.h"
#include<stdlib.h>
#include"Input.h"


//  ����w���֐�
int CheckOfTegoma(int tegoma_num,int *count1, int *count2, int p1_poke[], int p2_poke[], int koma[][N], int *which) {
    char row_tc, col_tc;
    int row_ti, col_ti;
	int i,j;
    while (1) {
        rewind(stdin);
        printf("�ǂ��Ɏw���܂��ォ�H (�s�j�i��j : ");
        scanf("%c %c", &row_tc, &col_tc);
        if (row_tc < '1' || row_tc > '9' || col_tc < '1' || col_tc > '9') {
            system("cls");
            BoardPrint(count1, count2, p1_poke, p2_poke, koma);
            printf("\n�P�`�X�̐����l���Q���͂��Ă�\n");
            continue;
        }     
        row_ti = atoi(&row_tc) - 1;
        col_ti = atoi(&col_tc) - 1;
        if (koma[row_ti][col_ti] == KARA) {
            switch (*which) {
            case 0:
				if(p1_poke[tegoma_num-1] == HU_P){
					for(i=0;i<9;i++){
						if(koma[i][col_ti] == HU_P){
							system("cls");
							BoardPrint(count1, count2, p1_poke, p2_poke, koma);
							printf("\n����Ŕ��������ɂȂ�悤�E�E�E\n");
							Input(count1,count2,p1_poke,p2_poke,which,koma);
						}
					}					
				}
                koma[row_ti][col_ti] = p1_poke[tegoma_num - 1];
                p1_poke[tegoma_num - 1] = KARA;
                return 0;
            case 1:
				if(p1_poke[tegoma_num-1] == HU_C){
					for(i=0;i<9;i++){
						if(koma[i][col_ti] == HU_C){
							system("cls");
							BoardPrint(count1, count2, p1_poke, p2_poke, koma);
							printf("\n����Ŕ��������ɂȂ�悤�E�E�E\n");
							Input(count1,count2,p1_poke,p2_poke,which,koma);
						}
					}					
				}
                koma[row_ti][col_ti] = p2_poke[tegoma_num - 1];
                p2_poke[tegoma_num - 1] = KARA;
                return 0;
            }
        }
        else {
            system("cls");
            BoardPrint(count1, count2, p1_poke, p2_poke, koma);
            printf("\n�����ɂ͋������\n");
        }
    }                
}
