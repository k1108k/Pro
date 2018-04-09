#define _CRT_SECURE_NO_WARNINGS 

#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

#include <stdio.h>
#include <string.h>
#include "checkOutPos.h"


void inputPutPos(int board[BOARD_SIZE][BOARD_SIZE], int which)
{
	static int first = 0;
	if (first == 0)
	{
		printf("���̃v���P�Q�����̔Ԃł��B\n");
		printf("���͗�(���l�@���l) �����̐��l�͉����@�E�̐��l�͏c��\n");
		printf("�����l�Ɛ��l�̊Ԃɔ��p�X�y�[�X�����A�G���^�[�������Ă��������B\n");
		first++;
	}
	printf("�ǂ��ɒu���܂��� ? \n");
	
	int pos_x, pos_y;
	
	while (1) {
		scanf("%d %d", &pos_x, &pos_y);
		if (checkOutPos(pos_x, pos_y) && board[pos_y][pos_x] == STONE_SPACE) { break; }
		printf("�s���ȓ��͂ł�\n");
	}
	board[pos_y][pos_x] = which;
}