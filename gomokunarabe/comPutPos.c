#include <time.h>
#include <stdlib.h>
#include"comLen.h"

#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

int comPutPos(int board[BOARD_SIZE][BOARD_SIZE], int which_turn)
{
	srand((unsigned)time(NULL));
	//有効手探索
	int i, j;

	for (i = 0;i < BOARD_SIZE;i++) {
		for (j = 0;j < BOARD_SIZE;j++) {
			if (board[i][j] == STONE_SPACE) { continue; }
			if (comLen(board,j,i,which_turn)) { return 0; }
		}
	}
	
	//乱数打ち
	while (1) {
		//乱数設定
		
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