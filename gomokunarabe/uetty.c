#ifndef _INCLUDE_UETTY_
#define _INCLUDE_UETTY_
#include <stdio.h>

void uetty(int u)
{
	char ue0[15][11] = { { ' ',' ',' ','u','u','u','u',' ',' ',' ' },
						 { ' ',' ','u',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { ' ',' ',' ',' ',' ',' ',' ',' ','u',' ' },
						 { 'u',' ','u','u',' ',' ','u',' ','u',' ' },
						 { 'u','u',' ',' ','u','u',' ','u','u',' ' },
						 { 'u','u',' ',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u','u',' ',' ',' ','u','u',' ',' ' },
						 { ' ','u',' ',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ','u','u','u',' ','u',' ',' ' },
						 { ' ','u','u',' ',' ',' ','u','u',' ',' ' },
						 { ' ','u',' ',' ',' ',' ',' ','u',' ',' ' },
						 { ' ',' ','u',' ',' ',' ','u',' ',' ',' ' },
						 { ' ',' ',' ','u','u','u',' ',' ',' ',' ' }, };
	
	char ue1[15][11] = { { ' ',' ',' ','u','u','u','u',' ',' ',' ' },
						 { ' ',' ','u',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { ' ',' ',' ',' ',' ',' ',' ',' ','u',' ' },
						 { 'u',' ','u','u',' ',' ','u',' ','u',' ' },
						 { 'u','u',' ',' ','u','u',' ','u','u',' ' },
						 { 'u','u',' ',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ',' ',' ','u',' ','u',' ',' ' },
						 { ' ','u','u',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ',' ',' ',' ',' ','u',' ',' ' },
						 { ' ','u',' ',' ','u',' ',' ','u',' ',' ' },
						 { ' ','u','u','u',' ','u','u','u',' ',' ' },
						 { ' ',' ','u',' ',' ',' ','u',' ',' ',' ' },
						 { ' ',' ',' ','u','u','u','u',' ',' ',' ' }, };

	char ue2[15][11] = { { 'u',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { 'u',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { 'u','u',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { 'u',' ','u',' ',' ',' ',' ',' ',' ',' ' },
						 { 'u',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { 'u',' ',' ',' ',' ','u',' ',' ',' ',' ' },
						 { 'u',' ',' ',' ','u','u',' ',' ',' ',' ' },
						 { ' ','u',' ','u',' ','u',' ',' ',' ',' ' },
						 { ' ',' ','u',' ',' ',' ','u','u','u','u' },
						 { ' ','u',' ','u',' ',' ',' ',' ',' ','u' },
						 { ' ',' ',' ',' ','u',' ',' ','u','u',' ' },
						 { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
						 { ' ',' ',' ',' ',' ',' ',' ',' ','u',' ' },
						 { ' ',' ',' ',' ',' ',' ',' ',' ',' ','u' }, };

	int i,j;
	if (u == 0)
	{
		for (i = 0;i < 15;i++) {
			for (j = 0;j < 11;j++) {
				printf("%c ", ue0[i][j]);
			}
			printf("\n");
		}
		printf("ちゃんと勉強してるか？\n僕と五目並べで勝負だ！！\n");

	}
	else if (u == 1)
	{
		for (i = 0;i < 15;i++) {
			for (j = 0;j < 11;j++) {
				printf("%c ", ue1[i][j]);
			}
			printf("\n");
		}
		printf("何事だ！！僕は許しませんよ！！\n");
	}
	else
	{
		for (i = 0;i < 15;i++) {
			for (j = 0;j < 11;j++) {
				printf("%c ", ue2[i][j]);
			}
			printf("\n");
		}
		i = 0;
		while (i < 10)
		{
			printf("おめでとう！！\n富山県はふとさと納税をお待ちしていま〜〜す\n");
			i++;
		}
	}
}
#endif //_INCLUDE_UETTY_