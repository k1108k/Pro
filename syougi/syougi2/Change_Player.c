#include"Common.h"

//	��Ԃ�ύX����֐�
void Change_Player(int *which){
	*which = ((*which) + 1) % 2;
}