#define _CRT_SECURE_NO_WARNINGS 

#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

#include <stdio.h>
#include <string.h>
#include "checkOutPos.h"


void inputPutPos(int board[BOARD_SIZE][BOARD_SIZE], int which)
{
	static int first = 0;
	if (first == 0)
	{
		printf("ものプロ１２月生の番です。\n");
		printf("入力例(数値　数値) ※左の数値は横軸　右の数値は縦軸\n");
		printf("※数値と数値の間に半角スペースを入れ、エンターを押してください。\n");
		first++;
	}
	printf("どこに置きますか ? \n");
	
	int pos_x, pos_y;
	
	while (1) {
		scanf("%d %d", &pos_x, &pos_y);
		if (checkOutPos(pos_x, pos_y) && board[pos_y][pos_x] == STONE_SPACE) { break; }
		printf("不正な入力です\n");
	}
	board[pos_y][pos_x] = which;
}