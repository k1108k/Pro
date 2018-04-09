#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

void boardPrint(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;

	printf("　");
	for (i = 0;i < BOARD_SIZE;i++) {
		printf("%d ", i);
	}
	puts("");
	for (i = 0;i < BOARD_SIZE;i++) {
		printf("%d ", i);
		for (j = 0;j < BOARD_SIZE;j++) {
			switch(board[i][j]) {
			case STONE_SPACE: printf("・");break;
			case STONE_BLACK: printf("●");break;
			case STONE_WHITE: printf("○");break;
			}
		}
		puts("");
	}
	puts("");
}