#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

void gameInit(int board[BOARD_SIZE][BOARD_SIZE], int *which_turn)
{
	boardInit(board);
	*which_turn = STONE_BLACK;
}