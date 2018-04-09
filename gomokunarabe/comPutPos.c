#include <time.h>
#include <stdlib.h>
#include"comLen.h"

#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

int comPutPos(int board[BOARD_SIZE][BOARD_SIZE], int which_turn)
{
	srand((unsigned)time(NULL));
	//�L����T��
	int i, j;

	for (i = 0;i < BOARD_SIZE;i++) {
		for (j = 0;j < BOARD_SIZE;j++) {
			if (board[i][j] == STONE_SPACE) { continue; }
			if (comLen(board,j,i,which_turn)) { return 0; }
		}
	}
	
	//�����ł�
	while (1) {
		//�����ݒ�
		
		double value1, value2;
		int put1, put2;
		value1 = rand() / (double)(unsigned)(RAND_MAX + 1.0);
		value2 = rand() / (double)(unsigned)(RAND_MAX + 1.0);
		put1 = (int)(value1*10.0);
		put2 = (int)(value2*10.0);


		if (board[put1][put2] == STONE_SPACE)
		{
			board[put1][put2] = which_turn;
			break;
		}
		else
		{
			continue;
		}
	}
	return 0;
}