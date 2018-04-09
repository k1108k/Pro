#include "boardInit.h"
#include "boardPrint.h"
#include "changeTurn.h"
#include "checkOutPos.h"
#include "gameEndProcess.h"
#include "gameInit.h"
#include "inputPutPos.h"
#include "lenCheck.h"
#include "comPutPos.h"
#include "comLen.h"
#include "uetty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 10 //盤面サイズ10*10
#define STONE_SPACE 0 //盤面にある石　なし
#define STONE_BLACK 1 //盤面にある石　ものプロ１２月生
#define STONE_WHITE 2 //盤面にある石　ウエッティ

int main() {
	//変数宣言
	int board[BOARD_SIZE][BOARD_SIZE];
	int which_turn;

	//導入
	uetty(0);

	//初期処理
	gameInit(board, &which_turn);
	boardPrint(board);

	//メインループ
	while (1) {
		//人間様の手番
		inputPutPos(board, which_turn);

		//手番変更
		changeTurn(&which_turn);

		//ウエッティの手番
		comPutPos(board, which_turn);

		//手番変更
		changeTurn(&which_turn);

		//出力処理
		boardPrint(board);

		//終了判定
		if (gameEndProcess(board)) { break; }
	}
	system("PAUSE");
	return 0;
}