#include<stdio.h>
#include<conio.h>
//#include <windows.h>
#include"Common.h"

//  �Ֆʏo�͊֐�
void BoardPrint(int *count1,int *count2,int p1_poke[20],int p2_poke[20],int koma[][N]) {
    int i, j, k;

    /*HANDLE h;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h, &csbi);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN);*/

	
    
	system("cls");

    //	player2�̎��\��	
    puts("");
    
    for (i = 0;i<40;i++) {
        printf("%5d[", i + 1);
        switch (p2_poke[i]) {
            //  ��Ȃ� 
        case KARA:
            printf("�@");
            break;
            //  computer��
        case GYOKU_C:
            printf("��");
            break;
        case HISYA_C:
            printf("�V");
            break;
        case KAKU_C:
            printf("��");
            break;
        case KIN_C:
            printf("�x");
            break;
        case GIN_C:
            printf("�s");
            break;
        case KEIMA_C:
            printf("�g");
            break;
        case KYOUSYA_C:
            printf("�N");
            break;
        case HU_C:
            printf("��");
            break;
        case TOKIN_C:
            printf("�T");
            break;
        case NARIGIN_C:
            printf("�i");
            break;
        case NARIKEI_C:
            printf("�i");
            break;
        case NARIKYOU_C:
            printf("�i");
            break;
        case RYU_C:
            printf("�u");
            break;
        case UMA_C:
            printf("�Z");
            break;
        default:
            break;
        }
        printf("] ");
    }
    printf("                                [ player2�̎�� ]");
    puts("");
    puts("");
    puts("");
    
    printf("           ");
    for (i = 0;i < 9;i++) {
        printf("%5d", i+1);
    }
    puts("");
    printf("            ");
    // �}�X�̏�[
    for (i = 0;i < N + 2;i++) {
        if (i == 0 || i == N + 1) {
            printf("+");
        }
        else if (i == N) {
            printf("�\�\");
        }
        else {
            printf("�\�\-");
        }
    }
    // ���ԃ}�X
    for (i = 0;i < N;i++) {
        // �}�X�̍��ӂ𔼊p�X�y�[�X��������
        puts("");
        printf("           ");
        printf("%d",i+1);
        printf("| ");
        // �R�}
        for (j = 0;j < N;j++) {
            switch (koma[i][j]) {
            //  ��Ȃ� 
            case KARA:
                printf("�@");
                break;
            //  player��
            case GYOKU_P:  
				//system("color,bat");
                printf("��");
                break;
            case HISYA_P:
                printf("��");
                break;
            case KAKU_P:
                printf("�p");
                break;
            case KIN_P:
                printf("��");
                break;
            case GIN_P:
                printf("��");
                break;
            case KEIMA_P:
                printf("�j");
                break;
            case KYOUSYA_P:
                printf("��");
                break;
            case HU_P:
                printf("��");
                break;
			case TOKIN_P:
				printf("��");
                break;
			case NARIGIN_P:
				printf("��");
                break;
			case NARIKEI_P:
				printf("��");
                break;
			case NARIKYOU_P:
				printf("��");
                break;
			case RYU_P:
				printf("��");
                break;
			case UMA_P:
				printf("�n");
                break;
            //  computer��
            case GYOKU_C:                  
                printf("��");
                break;
            case HISYA_C:
                printf("�V");
                break;
            case KAKU_C:
                printf("��");
                break;
            case KIN_C:
                printf("�x");
                break;
            case GIN_C:
                printf("�s");
                break;
            case KEIMA_C:
                printf("�g");
                break;
            case KYOUSYA_C:
                printf("�N");
                break;
            case HU_C:
                printf("��");
                break;
			case TOKIN_C:
				printf("�T");
                break;
			case NARIGIN_C:
				printf("�i");
                break;
			case NARIKEI_C:
				printf("�i");
                break;
			case NARIKYOU_C:
				printf("�i");
                break;
			case RYU_C:
				printf("�u");
                break;
			case UMA_C:
				printf("�Z");
                break;
            default:
                break;
            }
            printf(" | ");
        }
        //  ���Ԑ�
        if (i != N - 1) {
            puts("");
            printf("            ");
            for (k = 0; k < N; k++) {
                printf("|�\�\");
            }
            printf("|");
        }
    }

    puts("");
    printf("            ");
    // �}�X�̉��[
    for (i = 0;i < N + 2;i++) {
        if (i == 0 || i == N + 1) {
            printf("+");
        }
        else if (i == N) {
            printf("�\�\");
        }
        else {
            printf("�\�\-");
        }
    }

	
    puts("");
	puts("");
	//	player1�̎��\��
	puts("");
	printf("                                [ player1�̎�� ]\n");
	for(i=0;i<40;i++){
		printf("%5d[",i+1);
		switch (p1_poke[i]) {
            //  ��Ȃ� 
            case KARA:
                printf("�@");
                break;
            //  player��
            case GYOKU_P:				
                printf("��");
                break;
            case HISYA_P:
                printf("��");
                break;
            case KAKU_P:
                printf("�p");
                break;
            case KIN_P:
                printf("��");
                break;
            case GIN_P:
                printf("��");
                break;
            case KEIMA_P:
                printf("�j");
                break;
            case KYOUSYA_P:
                printf("��");
                break;
            case HU_P:
                printf("��");
                break;
			case TOKIN_P:
				printf("��");
                break;
			case NARIGIN_P:
				printf("��");
                break;
			case NARIKEI_P:
				printf("��");
                break;
			case NARIKYOU_P:
				printf("��");
                break;
			case RYU_P:
				printf("��");
                break;
			case UMA_P:
				printf("�n");
                break;
			default:
				break;
		}
		printf("] ");
	}

	puts("");
    puts("");
}