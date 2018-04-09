#include "boardInit.h"
#include "boardPrint.h"
#include "changeTurn.h"
#include "checkOutPos.h"
#include "gameEndProcess.h"
#include "gameInit.h"
#include "inputPutPos.h"
#include "lenCheck.h"
#include "comPutPos.h"
#include "comLen.h"
#include "uetty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

int main() {
	//�ϐ��錾
	int board[BOARD_SIZE][BOARD_SIZE];
	int which_turn;

	//����
	uetty(0);

	//��������
	gameInit(board, &which_turn);
	boardPrint(board);

	//���C�����[�v
	while (1) {
		//�l�ԗl�̎��
		inputPutPos(board, which_turn);

		//��ԕύX
		changeTurn(&which_turn);

		//�E�G�b�e�B�̎��
		comPutPos(board, which_turn);

		//��ԕύX
		changeTurn(&which_turn);

		//�o�͏���
		boardPrint(board);

		//�I������
		if (gameEndProcess(board)) { break; }
	}
	system("PAUSE");
	return 0;
}