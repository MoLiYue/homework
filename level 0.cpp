#include "stdafx.h"
#include"functions.h"
#include<math.h>

extern int eflag = 1;

void Level_0_asset(int map[screen_height][map_length])
{
		int i, j;
		for (i = 20; i <= 30; i++)
			map[screen_height - 2][i] = cone1;
		for (i = 0; i < map_length; i++)
			map[4][i] = block1;
		for (i = 0; i < map_length; i++)
		{
			if (i <= 240 || i >= 275)
				map[5][i] = cone2;
		}
	
		for (j = 5; j < screen_height - 10; j++)
			for (i = 35; i < 37; i++)
				map[j][i] = block2;
		for (i = 50; i < 100; i++)
			map[screen_height - 2][i] = block1;
		for (i = 100; i < 107; i++)
			map[screen_height - 2][i] = cone1;
		for (j = 5; j < 12; j++)
			for (i = 105; i < 107; i++)
				map[j][i] = block2;
		for (i = 105; i < 107; i++)
			map[12][i] = cone2;
		for (i = 119; i < 150; i++)
		{
			if ((i + 1) % 5)
				map[screen_height - 2][i] = block1;
			else
				map[screen_height - 2][i] = cone1;
		}
		for (i = 154; i < 165; i++)
			map[screen_height - 2][i] = cone1;
		if (eflag)
			map[screen_height - 2][165] = item_player_health;
		else
			map[screen_height - 2][165] = 0;
		for (i = 168; i < 180; i++)
			map[screen_height - 2][i] = cone1;
		for (i = 168; i < 180; i++)
			map[screen_height - 8][i] = cone2;
		for (i = 168; i < 180; i++)
			map[screen_height - 9][i] = block1;
		int iNum = 0;
		for (i = 190; i <= 240; i++)
		{
			if (iNum % 10 == 0)
			{
				map[screen_height - 7][i] = cone1;
				for (j = screen_height - 2; j > screen_height - 7; j--)
					map[j][i] = block2;
				iNum++;
			}
			else
			{
				map[screen_height - 2][i] = cone1;
				iNum++;
			}
		}
		iNum = 0;
		map[screen_height - 3][245] = item_gun;

		for (i = 250; i < 270; i++)
			for (j = screen_height - 2; j >= screen_height - 2 - fabs(260 - i); j--)
			{
				map[j][i] = cone1;
				if (fabs(260 - i) != 0)
					map[j + 1][i] = block1;
			}

		for (i = 280; i < 300; i++)
			map[screen_height - 5][i] = block1;
		for (i = 310; i < 320; i++)
			map[screen_height - 15][i] = block1;
		for (j = screen_height - 2; j > 25; j--)
			map[j][330] = block1;
		for (i = 336; i < 346; i++)
			map[screen_height - 6][i] = block1;
		for (i = 326; i < 336; i++)
			map[screen_height - 2][i] = cone1;
}
