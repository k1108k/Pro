#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B
#include"checkOutPos.h"

int comLen(int board[][BOARD_SIZE], int x, int y, int which_turn)
{
	int dx[] = { 0 , 1 , 1 , 1 , 0 ,-1 ,-1 ,-1 };
	int dy[] = { 1 , 1 , 0 ,-1 ,-1 ,-1 , 0 , 1 };
	int i,j,len_flag;

		//5�A���ߎ�
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 3;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 3) {
					if (checkOutPos(y + 4 * dy[i], x + 4 * dx[i]) && board[y + 4 * dy[i]][x + 4 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y + 4 * dy[i]][x + 4 * dx[i]] = which_turn;
						return 1;
					}
					else if (checkOutPos(y - 1 * dy[i], x - 1 * dx[i]) && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y - 1 * dy[i]][x - 1 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//3�A��ѐ΂P���ߎ�
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 2;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 2 && board[y + 4 * dy[i]][x + 4 * dx[i]] == board[y][x] && board[y][x] == which_turn)
				{
					if (checkOutPos(y + 3 * dy[i], x + 3 * dx[i]) && board[y + 3 * dy[i]][x + 3 * dx[i]] == STONE_SPACE)
					{
						board[y + 3 * dy[i]][x + 3 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//2�A��тQ�A���ߎ�
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 1;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 1 && (board[y + 3 * dy[i]][x + 3 * dx[i]] == board[y][x] && board[y + 4 * dy[i]][x + 4 * dx[i]] == board[y][x] && board[y][x] == which_turn))
				{
					if (checkOutPos(y + 2 * dy[i], x + 2 * dx[i]) && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE)
					{
						board[y + 2 * dy[i]][x + 2 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//3�A��ѐ΂P�~��
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 2;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 2 && board[y + 4 * dy[i]][x + 4 * dx[i]] == board[y][x] && board[y][x] != which_turn)
				{
					if (checkOutPos(y + 3 * dy[i], x + 3 * dx[i]) && board[y + 3 * dy[i]][x + 3 * dx[i]] == STONE_SPACE)
					{
						board[y + 3 * dy[i]][x + 3 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//4�A�~�ߑł�
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 3;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 3) {
					if (checkOutPos(y + 4 * dy[i], x + 4 * dx[i]) && board[y + 4 * dy[i]][x + 4 * dx[i]] == STONE_SPACE && board[y][x] != which_turn) {
						board[y + 4 * dy[i]][x + 4 * dx[i]] = which_turn;
						return 1;
					}
					else if (checkOutPos(y - 1 * dy[i], x - 1 * dx[i]) && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] != which_turn) {
						board[y - 1 * dy[i]][x - 1 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//2�A��тQ�A�~��
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 1;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 1 && (board[y + 3 * dy[i]][x + 3 * dx[i]] == board[y][x] && board[y + 4 * dy[i]][x + 4 * dx[i]] == board[y][x] && board[y][x] != which_turn))
				{
					if (checkOutPos(y + 2 * dy[i], x + 2 * dx[i]) && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE)
					{
						board[y + 2 * dy[i]][x + 2 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//2�A���1�A�~��
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 1;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 1 && (board[y + 3 * dy[i]][x + 3 * dx[i]] == board[y][x] && board[y + 4 * dy[i]][x + 4 * dx[i]] == STONE_SPACE && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] != which_turn))
				{
					if (checkOutPos(y + 2 * dy[i], x + 2 * dx[i]) && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE)
					{
						board[y + 2 * dy[i]][x + 2 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//2�A���1�A4�A�L�΂���
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 1;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 1 && (board[y + 3 * dy[i]][x + 3 * dx[i]] == board[y][x] && board[y + 4 * dy[i]][x + 4 * dx[i]] == STONE_SPACE && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] == which_turn))
				{
					if (checkOutPos(y + 2 * dy[i], x + 2 * dx[i]) && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE)
					{
						board[y + 2 * dy[i]][x + 2 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//3�A�~�ߑł�
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 2;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 2 && board[y + 3 * dy[i]][x + 3 * dx[i]] == STONE_SPACE && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE)
				{
					if (checkOutPos(y + 3 * dy[i], x + 3 * dx[i]) && board[y + 3 * dy[i]][x + 3 * dx[i]] == STONE_SPACE && board[y][x] != which_turn)
					{
						board[y + 3 * dy[i]][x + 3 * dx[i]] = which_turn;
						return 1;
					}
					else if (checkOutPos(y - 1 * dy[i], x - 1 * dx[i]) && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] != which_turn) {
						board[y - 1 * dy[i]][x - 1 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//4�A�L�΂���
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 2;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 2) {
					if (checkOutPos(y + 3 * dy[i], x + 3 * dx[i]) && board[y + 3 * dy[i]][x + 3 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y + 3 * dy[i]][x + 3 * dx[i]] = which_turn;
						return 1;
					}
					else if (checkOutPos(y - 1 * dy[i], x - 1 * dx[i]) && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y - 1 * dy[i]][x - 1 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
		//3�A�L�΂���
		for (i = 0;i < 8;i++) {
			for (j = 1, len_flag = 1;j <= 1;j++, len_flag++) {
				if (board[y][x] != board[y + j * dy[i]][x + j * dx[i]]) { break; }
				if (len_flag == 1 && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE) {
					if (checkOutPos(y + 2 * dy[i], x + 2 * dx[i]) && board[y + 2 * dy[i]][x + 2 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y + 2 * dy[i]][x + 2 * dx[i]] = which_turn;
						return 1;
					}
					else if (checkOutPos(y - 1 * dy[i], x - 1 * dx[i]) && board[y - 1 * dy[i]][x - 1 * dx[i]] == STONE_SPACE && board[y][x] == which_turn) {
						board[y - 1 * dy[i]][x - 1 * dx[i]] = which_turn;
						return 1;
					}
				}
			}
		}
	return 0;
}