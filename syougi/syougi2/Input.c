#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"Common.h"
#include"CheckOfKoma.h"
#include<stdlib.h>
#include"CheckOfInput.h"
#include"CheckOfArea.h"
#include"BoardPrint.h"
#include"CheckOfKoma_scope.h"
#include"CheckOfJump_over.h"
#include"Position_koma.h"
#include"CheckOfTegoma.h"

//  player���͊֐�
int Input(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int *which,int koma[][N]) {
    char row_c, col_c[100];
    char row_y, col_x[100];
    int row_i, col_i;           //  ����}�X�ϐ�
    int row_dy=0, col_dx=0;     //  �ړ���}�X�ϐ�
    int i,flag = 1;
	int tegoma,num;
    int zerohan, hikaku;
    int tegoma_num,input;   //  ���w��p�̊֐�
    
    
    while (flag) {		
        puts("");        
        rewind(stdin);
        //scanf("%*[^\n]%*c"); //�Ȃ��������ł͓��͑҂��ɂȂ�?
        printf("�s player %d �̎�� �t\n", (*which) + 1);
        printf("�ړ������     �i�s�j�i��j\n");
        printf("�����g���ꍇ �i�O�j�i���ԍ��j: ");
        scanf("%c %s", &row_c,col_c);        
        //scanf("%*[^\n]%*c");
        rewind(stdin);
        //  �����g���I�������ꂽ�ꍇ   �P������0�����
        zerohan = atoi(&row_c);
        if (zerohan == 0) {      // 0.1���P�߂ɓ��͂���Ƃǂ��Ȃ邩�H                  
            if (row_c != '0') {
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                printf("\n�����l���Q���͂��Ă҂��");
                continue;
            }                      
            //  �Q�ڂ̓��͂��Q���܂ł̐����l���`�F�b�N         
            
            //  �C���I�I
			if (col_c[1] == '\0') {
                if(col_c[0] < '1' || col_c[0] > '9'){
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n���ԍ��͂P�`�S�O�̊Ԃœ��͂��Ă�");
                    continue;
				}
			}
			if(col_c[1] != '\0') {
                if(!(col_c[0] < '1' && col_c[0] > '9')){
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n���ԍ��͂P�`�S�O�̊Ԃœ��͂��Ă�");
                    continue;
				}
			}
            if (strlen(col_c) > 2 || (!((col_c[1] >= '0' && col_c[1] <= '9') || col_c[1] == '\0'))) {
					system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n���ԍ��͂P�`�S�O�̊Ԃœ��͂��Ă�");
                    continue;           
            }    
            tegoma_num = atoi(col_c);
            switch (*which) {
            case 0:
                switch (p1_poke[tegoma_num-1]) {
                    //  ��Ȃ� 
                case KARA:
                    system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n�����Ɏ��͓����ĂȂ���`��");
                    continue;
                    //  player��
                case GYOKU_P:
                    printf("[ �� ]");
                    break;
                case HISYA_P:
                    printf("[ ��� ]");
                    break;
                case KAKU_P:
                    printf("[ �p ]");
                    break;
                case KIN_P:
                    printf("[ �� ]");
                    break;
                case GIN_P:
                    printf("[ �� ]");
                    break;
                case KEIMA_P:
                    printf("[ �j�n ]");
                    break;
                case KYOUSYA_P:
                    printf("[ ���� ]");
                    break;
                case HU_P:
                    printf("[ �� ]");
                    break;
                case TOKIN_P:
                    printf("[ �Ƌ� ]");
                    break;
                case NARIGIN_P:
                    printf("[ ���� ]");
                    break;
                case NARIKEI_P:
                    printf("[ ���j ]");
                    break;
                case NARIKYOU_P:
                    printf("[ ���� ]");
                    break;
                case RYU_P:
                    printf("[ �� ]");
                    break;
                case UMA_P:
                    printf("[ �n ]");
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch (p2_poke[tegoma_num - 1]) {
                    //  ��Ȃ� 
                case KARA:
                    system("cls");
                    BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                    printf("\n�����ɋ�͂Ȃ��`��");
                    continue;
                case GYOKU_C:
                    printf("[ �J�J���b�g ]");
                    break;
                case HISYA_C:
                    printf("[ ��V ]");
                    break;
                case KAKU_C:
                    printf("[ ��� ]");
                    break;
                case KIN_C:
                    printf("[ �x�W�[�^ ]");
                    break;
                case GIN_C:
                    printf("[ �s�b�R�� ]");
                    break;
                case KEIMA_C:
                    printf("[ �g�����N�X�i�����j ]");
                    break;
                case KYOUSYA_C:
                    printf("[ �N������with18�� ]");
                    break;
                case HU_C:
                    printf("[ �����`�� ]");
                    break;
                case TOKIN_C:
                    printf("[ �~�X�^�[�T�^�� ]");
                    break;
                case NARIGIN_C:
                    printf("[ �i���b�N���l ]");
                    break;
                case NARIKEI_C:
                    printf("[ �i���b�N���l ]");
                    break;
                case NARIKYOU_C:
                    printf("[ �i���b�N���l ]");
                    break;
                case RYU_C:
                    printf("[ ���l�u�[ ]");
                    break;
                case UMA_C:
                    printf("[ �Z�� ]");
                    break;
                default:
                    break;
                }
                break;
            }
            printf("�@�ł���? \n�����E�E�E1�@���߂ہE�E�E0 : ");
            scanf("%d", &input);
            if (input == 1) {
                CheckOfTegoma(tegoma_num, count1, count2, p1_poke, p2_poke, koma, which);
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                return 0;
            }
            else {
                system("cls");
                BoardPrint(count1, count2, p1_poke, p2_poke, koma);
                continue;
            }                       
        }
        //  �����g��Ȃ��I�������ꂽ�ꍇ
        if (strlen(col_c) != 1) {
            system("cls");
            BoardPrint(count1,count2,p1_poke,p2_poke,koma);
            printf("\n�����l�ŃC���e�s����");            
            continue;
        }        
        flag = CheckOfInput(count1,count2,p1_poke,p2_poke,which,koma,row_c,col_c);  //  ����m�F
        if (flag == 1) {
            continue;
        }
        row_i = atoi(&row_c) - 1;       //���͒l�́{�P�̂��߁[�P���Ĕz��̗v�f�ԍ��ɂ��킹��
        col_i = atoi(&col_c[0]) - 1;    //

        
        //  �ǂ��Ɉړ����邩���m�F����
        flag = 1;
        while (flag) {
            while (flag) {  //  ���̓`�F�b�N        
                puts("");
                rewind(stdin);
                printf("�ǂ��Ɉړ������? �i�s�j�i��j :  ");
                scanf("%c %s", &row_y, col_x);
                //scanf("%*^[\n]%*c");
                rewind(stdin);
                if (strlen(col_x) != 1) {   //�@�����܂��͕��������͂��ꂽ�̂Ń_��
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n�����l����͂��Ă҂��");
                    continue;
                }
                flag = CheckOfArea(count1,count2,p1_poke,p2_poke,koma, row_y, col_x, &row_dy, &col_dx);   //  �߂�l�O�Ȃ���̓`�F�b�N����           
            }

            row_dy--;    //���͒l�́{�P�̂��߁[�P���Ĕz��̗v�f�ԍ��ɂ��킹��
            col_dx--;     //

            //  ��\�͈͓͂̔��̈ړ���           
            flag = CheckOfKoma_scope(koma, row_i, col_i, row_dy, col_dx);    //�@�߂�l0�Ȃ炨��
            if (flag == 1) {     //  �P�Ȃ�ړ�����ē���
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n���̋�̈ړ��͈͂𒴂��Ă�����");
                continue;
            }

            
            //  �ړ���Ɏ���Ȃ����`�F�b�N            
            flag = CheckOfKoma(which, koma,  row_dy, col_dx);   //�@�ړ��ł��邩�m�F
            if (flag == 1) {     //  �P�Ȃ�ړ�����ē���
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n�����ɂ͎����̋������");  
                continue;
            }

            // �ړ������̋���щz���Ă��Ȃ����`�F�b�N
            flag = CheckOfJump_over(koma, row_i, col_i, row_dy, col_dx);
            if (flag == 1) {     //  �P�Ȃ�ړ�����ē���
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n����щz���Ă�����");
                
            }
                  
        }

		//	���u��������
        Position_koma(count1,count2,p1_poke,p2_poke,which,koma,row_i,col_i,row_dy,col_dx);
		system("cls");
		BoardPrint(count1,count2,p1_poke,p2_poke,koma); 
	}
}
