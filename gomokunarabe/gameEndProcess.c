#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

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
				printf("%sの勝ちです\n", (board[i][j] == STONE_BLACK) ? "ものプロ１２月生" : "ウエッティ");
				(board[i][j] == STONE_BLACK) ? uetty(2) : uetty(1);
				return 1;
			}
		}
	}
	return 0;
}