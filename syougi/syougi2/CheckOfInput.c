#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Common.h"
#include"BoardPrint.h"

//  ���̓`�F�b�N�֐�
int CheckOfInput(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int *which,int koma[][N],char _row, char _col[100]) {
    int input,row,col;
    
            //  �����𐔒l�ɕϊ�        
            row = atoi(&_row);
            col = atoi(_col);
                    
            // �@�͈͈ȊO�Ȃ�œ���        
            if ((row <= 0 || row > 9) || (col <= 0 || col > 9)) {   //�͈̓`�F�b�N�֐��ɒu�������K�v
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                printf("\n�P�`�X�̐����l����͂��Ȃ���yo");
                return 1;
            }

           //   ��������̊m�F
            switch(*which){               
            case 0:
                switch (koma[row-1][col-1]) {
                    //  ��Ȃ� 
                case KARA:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n��Ȃ��`��");
                    return 1;
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
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n�G�̃R�}�����");
                    return 1;                    
                }
                break;
            case 1:
                switch (koma[row-1][col-1]) {
                    //  ��Ȃ� 
                case KARA:
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n��Ȃ��`��");
                    return 1;
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
                    system("cls");
                    BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                    printf("\n�G�̃R�}�����");
                    return 1;                    
                }
                break;
            }
            printf("�@�ł���? \n�����E�E�E1�@���߂ہE�E�E0 : ");
            scanf("%d", &input);
            if (input == 1) {
                system("cls");
                BoardPrint(count1,count2,p1_poke,p2_poke,koma);
                return 0;
            }
            
            system("cls");
            BoardPrint(count1,count2,p1_poke,p2_poke,koma);
            return 1;
}