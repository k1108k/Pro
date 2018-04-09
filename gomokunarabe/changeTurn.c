#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ
void changeTurn(int *which_turn)
{
	*which_turn = (*which_turn == STONE_BLACK) ? STONE_WHITE : STONE_BLACK;
}