#define BOARD_SIZE 10 //�ՖʃT�C�Y10*10
#define STONE_SPACE 0 //�Ֆʂɂ���΁@�Ȃ�
#define STONE_BLACK 1 //�Ֆʂɂ���΁@���̃v���P�Q����
#define STONE_WHITE 2 //�Ֆʂɂ���΁@�E�G�b�e�B

int checkOutPos(int x, int y)
{
	return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}