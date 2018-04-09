#include"Common.h"

//	è”Ô‚ğ•ÏX‚·‚éŠÖ”
void Change_Player(int *which){
	*which = ((*which) + 1) % 2;
}