#include<stdio.h>
#include<iostream>
#include "stdafx.h"
#include"functions.h"
using namespace std;
extern int players;
extern int hp_boss0;
extern int boss0_exist;
extern int bullet;
extern char boss0_move;
extern int x; 
extern int y_boss0;
extern int y;
extern int x_boss0;
/*   定义上边界为  9  
         下边界为  9
		 空白为  0
		 判定点为  5
 */
#define VISABLE_WIDE 120
//#define EDGE 9

int temp1 = 0;
extern int map[screen_height][map_length];
extern int x;
extern int y;
void printview(int height,int wide,int temp1)
{
	int i, j;
	for (j = 0; j < height; j++)
	{
		for (i = temp1; i < wide; i++)
		{
			if (map[j][i] == 0)
				printf(" ");
			if (map[j][i] == EDGE)
				printf("-");
			if (map[j][i] == head_value || map[j][i] == body_value)
				printf("*");
			if (map[j][i] == cone1)
				printf("^");
			if (map[j][i] == cone2)
				printf("v");
			if (map[j][i] == block1)
				printf("=");
			if (map[j][i] == block2)
				printf("|");
			if (map[j][i] == item_player_health)
				printf("*");
			if (((map[j][i] == boss0_body_value) || (map[j][i] == boss0_head_value)) && boss0_exist != 0)
				printf("@");
			if (map[j][i] == item_gun)
				printf("?");
		}
	}
	printf("剩余生命：");
	if(players==1){
		printf("*");
	}
	else if (players == 2){
		printf("* *");
	}
	else if (players == 3){
		printf("* * *");
	}
	else if (players == 4){
		printf("* * * *");
	}
	printf("   剩余子弹数");
	for (i = 0; i < bullet; i++){
		printf(">");
	}
	if (boss0_exist != 0)
	{
		printf("\nboss剩余生命：");
		for (int l = 0; l < hp_boss0; l++){
			printf("#");
		}
		
		printf("     ");
		
	}
}

void viewmove()                                // x为小人在地图中数组中的index
{

	/* for (j = 0; j < map_length; j++)		给地图边界赋特殊值不需要在无限循环里重复做
											我放到初始化小人位置函数里了,之后可以把初始小人函数改为初始整个地图的函数(人\地形\道具)
	{
		map[0][j] = EDGE;
	}


	for (j = 0; j < map_length; j++)
	{
		map[screen_height - 1][j] = EDGE;
	}				*/
	
	for (int s = 0; s < screen_height; s++)
	{
		for (int k = 0; k < map_length; k++)	//通过头部的特殊值定位小人头部位置
		{
			if (map[s][k] == head_value)
			{
				y = s;			//行序数对应纵坐标
				x = k;			//列序数对应横坐标  map[y][x]
			}
		}
	}


	if (x < 60){
		temp1 = 0;
	    printview(screen_height, VISABLE_WIDE, temp1);
	}
	 else if (x <= map_length - 61){
		temp1 = x - 60;
		printview(screen_height, VISABLE_WIDE + temp1, temp1);
	}
	else{
		temp1 = map_length - 120;
		printview(screen_height, VISABLE_WIDE + temp1, temp1);

	}         
	temp1 = 0;//屏幕移动及显示
}
