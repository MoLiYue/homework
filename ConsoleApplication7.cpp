
// ConsoleApplication7.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "functions.h"
#include <Windows.h>
#include <time.h>

//extern int screen[screen_height][screen_length];
//extern int player[screen_height][screen_length];

extern int map[screen_height][map_length];
extern int timenow;
extern int timenow1;
extern int flag3;//退出标志
extern int bullet_exist = 0;
extern int bullet = 0;
extern int eflag1;
extern int eflag;
extern char boss0_move = '1';

int main()
{
	while (1)
	{
		menu_final();
		if (flag3)return 0;
		memset(map, 0, sizeof(map));
		system("cls");		//清屏
				//地图初始化
		player_creator(map);		//初始小人位置
//打印屏幕
		timenow1 = ((clock() / speed) + 1)*speed;
		eflag = 1;
		while (1)
		{
			main_process();
			if (eflag1)
			{
				eflag1 = 0;
				break;
			}
		}
	}
	//what a fuck
}
