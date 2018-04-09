#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

#include <stdio.h>
#include <string.h>
#include "lenCheck.h"
#include "uetty.h"

int gameEndProcess(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;

	for (i = 0;i < BOARD_SIZE;i++) {
		for (j = 0;j < BOARD_SIZE;j++) {
			if (board[i][j] == STONE_SPACE) { continue; }
			if (lenCheck(board, j, i)) {
				printf("%s�̏����ł�\n", (board[i][j] == STONE_BLACK) ? "���̃v���P�Q����" : "�E�G�b�e�B");
				(board[i][j] == STONE_BLACK) ? uetty(2) : uetty(1);
				return 1;
			}
		}
	}
	return 0;
}