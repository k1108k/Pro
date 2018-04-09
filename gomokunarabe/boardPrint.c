#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

void boardPrint(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;

	printf("�@");
	for (i = 0;i < BOARD_SIZE;i++) {
		printf("%d ", i);
	}
	puts("");
	for (i = 0;i < BOARD_SIZE;i++) {
		printf("%d ", i);
		for (j = 0;j < BOARD_SIZE;j++) {
			switch(board[i][j]) {
			case STONE_SPACE: printf("�E");break;
			case STONE_BLACK: printf("��");break;
			case STONE_WHITE: printf("��");break;
			}
		}
		puts("");
	}
	puts("");
}