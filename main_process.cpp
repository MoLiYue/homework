#include "stdafx.h"
#include "functions.h"
#include<time.h>
#include<stdlib.h>

extern int map[screen_height][map_length];				
//extern int screen[screen_height][screen_length];		
//extern int player[screen_height][screen_length];

int timenow = 0;
int timenow1 = 0;


void main_process()
{
	timenow = clock();

	timenow = clock();


	getch_part();			//将按键输入部分分离至入口外

	if (timenow % speed == 0 && timenow1 == timenow)
	{
		timenow1 += speed;
		
		Level_0_asset(map);
        boss_asset();
		moving_part(map);
		Trigger();
		viewmove();
		
		

		//读取按键（叶）
		//移动屏幕（何）
		//判定状态（杨）
	}
}

void player_creator(int map[screen_height][map_length])
{

	map[head_x][head_y] = head_value;
	map[head_x + 1][head_y] = body_value;
	map[head_x + 1][head_y - 1] = body_value;
	map[head_x + 1][head_y + 1] = body_value;
	map[head_x + 2][head_y] = body_value;
	map[head_x + 3][head_y - 1] = body_value;
	map[head_x + 3][head_y + 1] = body_value;

	for (int j = 0; j < map_length; j++)
	{
		map[0][j] = EDGE;
	}


	for (int j = 0; j < map_length; j++)
	{
		map[screen_height - 1][j] = EDGE;
	}

}

void screen_creator(int map[screen_height][map_length])
{
	
	

	


}
