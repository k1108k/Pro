#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

void boardInit(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;
	for (i = 0;i < BOARD_SIZE;i++) {
		for (j = 0;j < BOARD_SIZE;j++) {
			board[i][j] = STONE_SPACE;
		}
	}
}