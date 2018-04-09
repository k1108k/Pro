#ifndef _INCLUDE_COMLEN_
#define _INCLUDE_COMLEN_

#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　黒
#define STONE_WHITE 2 //盤面にある石　白

int comLen(int board[][BOARD_SIZE], int x, int y, int which_turn);

#endif//_INCLUDE_COMLEN_


#pragma once
