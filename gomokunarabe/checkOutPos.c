#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

int checkOutPos(int x, int y)
{
	return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}