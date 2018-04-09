#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

int lenCheck(int board[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
	int i, j, len_flag;
	int dx[] = { 0 , 1 , 1 , 1 };
	int dy[] = { 1 , 0 , 1 ,-1 };

	for (i = 0;i < 4;i++) {
		for (j = 1;len_flag = 1,j <= 4;j++) {
			if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) {
				len_flag = 0;
				break;
			}
		}
		if (len_flag == 1) { return 1; }
	}
	return 0;
}