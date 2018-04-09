#ifndef _INCLUDE_COMPUTPOS_
#define _INCLUDE_COMPUTPOS_

#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　黒
#define STONE_WHITE 2 //盤面にある石　白

int comPutPos(int board[BOARD_SIZE][BOARD_SIZE], int which_turn);

#endif//_INCLUDE_COMPUTPOS_

#pragma once
