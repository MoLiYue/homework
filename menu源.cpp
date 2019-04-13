#include"stdafx.h"
#include<iostream>
#include"functions.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#define A 30
#define B 40
using namespace std;
//Adventure of QueDe Brother
//start the game
//choose the map
//quit the game

char menu_view[screen_height][screen_length] = { 0 };
char help_view[screen_height][screen_length] = { 0 };

int point();
void point_move(int b);
char pointer[5] = "--->";
void menu_getch_part();
char ch3 = '0';
char ch4 = '0';
int flag1 = 0;								//判断是否更改pointer
int flag2 = 1;								//判断是否退出getch模式
int flag3 = 0;								//判断是否推出游戏
int flag4 = 0;								//判断是否退出getch模式
int flag5 = 0;								//判断是否二次及以后输出menu


void menu0()										//首次输出menu
{
	int i, j;
	system("cls");
	for (j = 0; j < screen_height; j++)
	{
		for (i = 0; i < screen_length; i++)
		{
			printf("%c", menu_view[j][i]);
		}
	}
}
//void menu()											//二次及以后输出menu
//{
//	int i, j;
//	if (flag1)
//	{
//		system("cls");
//		for (j = 0; j < screen_height; j++)
//		{
//			for (i = 0; i < screen_length; i++)
//			{
//				printf("%c", menu_view[j][i]);
//			}
//		}
//		
//	}
//}
void help()											//二次及以后输出menu
{
	int i, j;
	system("cls");
		for (j = 0; j < screen_height; j++)
		{
			for (i = 0; i < screen_length; i++)
			{
				printf("%c", help_view[j][i]);
			}
		}
}
int point()											//判断指向位置
{
	int i;
	for (i = 13; ; i++)
	{
		if (menu_view[i][40] == '-')
			break;
	}
	return i;
}
void point_move(int b)								//a为当前所指位置,b为下一位置
{
	int i, k, a;

	a = point();
	for (k = 40, i = 0; k < 40 + 4; k++, i++)
	{
		menu_view[a][k] = ' ';
	}
	for (k = 40, i = 0; k < 40 + 4; k++, i++)
	{
		menu_view[b][k] = pointer[i];
	}
}
void menu_input()
{
	char a[27] = "Adventure of QueDe Brother";
	char b[15] = "start the game";
	char c[14] = "quit the game";
	char e[18] = "press -> to enter";
	char f[5] = "help";
	//char *pa, *pb, *pc;
	int i, j, k, l;
	for (j = 0; j < screen_height; j++)
	{
		for (i = 0; i < screen_length; i++)
		{
			menu_view[j][i] = ' ';
		}
	}
	for (k = 40, i = 0; k < 40 + 26; k++, i++)
	{
		menu_view[11][k] = a[i];								//"Adventure of QueDe Brother"
	}
	for (k = 44, i = 0; k < 44 + 14; k++, i++)
	{
		menu_view[13][k] = b[i];								//"start the game"
	}
	for (k = 49, i = 0; k < 49 + 5; k++, i++)
	{
		menu_view[14][k] = f[i];								//"help"
	}
	for (k = 45, i = 0; k < 45 + 13; k++, i++)
	{
		menu_view[15][k] = c[i];								//"quit the game"
	}
	for (k = 40, i = 0; k < 40 + 4; k++, i++)
	{
		menu_view[13][k] = pointer[i];								//"--->"
	}
	for (k = 43, i = 0; k < 43 + 18; k++, i++)
	{
		menu_view[20][k] = e[i];								//"press -> to enter"
	}
}
void help_input()
{
	char e[20] = "press <- to go back";
	char f[5] = "help";
	char instruction1[34] = "Kill the boss to finish the game.";
	char instruction2[55] = "Operation: Tap direction key to control the game role.";
	char instruction6[7] = "Item :";
	char instruction3[35] = "'*' Player health+1        '?' gun";
	char instruction5[51] = "Hit <q> to shoot left       hit <e> to shoot right";
	char instruction7[7] = "Terra:";
	char instruction4[37] = "'='&'|' Block           '^'&'v' cone";

	int i, j, k, l;
	for (j = 0; j < screen_height; j++)
	{
		for (i = 0; i < screen_length; i++)
		{
			help_view[j][i] = ' ';
		}
	}
	for (k = 49, i = 0; k < 49 + 5; k++, i++)
	{
		help_view[5][k] = f[i];											//"help"
	}

	for (k = A , i = 0; k < A + 34; k++, i++)
	{
		help_view[11][k] = instruction1[i];								//"Kill the boss to finish the game."
	}
	for (k = A , i = 0; k < A + 55; k++, i++)
	{
		help_view[12][k] = instruction2[i];								//"Operation: Tap direction key to control the game role."
	}
	for (k = A, i = 0; k < A + 7; k++, i++)
	{
		help_view[13][k] = instruction6[i];								//"Item :"
	}
	for (k = B, i = 0; k < B + 35; k++, i++)
	{
		help_view[14][k] = instruction3[i];								//"'*' Player health+1		'?' gun"
	}
	for (k = B, i = 0; k < B + 51; k++, i++)
	{
		help_view[15][k] = instruction5[i];								//"Hit<q> to shoot left		hit<e> to shoot right"
	}
	for (k = A, i = 0; k < A + 7; k++, i++)
	{
		help_view[16][k] = instruction7[i];								//"Terra:"
	}
	for (k = B, i = 0; k < B + 37; k++, i++)
	{
		help_view[17][k] = instruction4[i];								//"'='&'|' Block			'^'&'v' cone"
	}
	//for (k = 40, i = 0; k < 40 + 4; k++, i++)
	//{
	//	help_view[13][k] = pointer[i];								//"--->"
	//}
	for (k = 42, i = 0; k < 42 + 20; k++, i++)
	{
		help_view[20][k] = e[i];								//"press <- to go back"
	}
}
void menu_getch_part()
{
	
	if (_kbhit())				//判断是否输入按键
	{
		flag2 = 1;
		ch3 = _getch();

		if (ch3 == -32)			//是否为方向键
		{
			
			ch4 = _getch();
			
			switch (ch4)
			{
			case 'H': if (point() <= 15 && point() > 13)
			{
				point_move(point() - 1);
				flag1 = 1;
			}break;
						//上

			//ase 'K': if (x - move_left <= 0) { direction = 'o'; }
			//		  else direction = 'a'; break;		//左

			case 'M': flag2 = 0; 
				if (point() == 14)
					flag5 = 1;
					break;		//右

			case 'P': if (point() < 15 && point() >= 13)
			{
				point_move(point() + 1);
				flag1 = 1;
			}break;
					  				//下
			default:  break;							//其他情况(越界)
			}
		}
	}
}
void help_getch_part()
{

	if (_kbhit())				//判断是否输入按键
	{
		flag2 = 1;
		ch3 = _getch();

		if (ch3 == -32)			//是否为方向键
		{
			ch4 = _getch();
			switch (ch4)
			{
			case 'K':flag4 = 1;
				break;		//左
			/*default:  break;*/							//其他情况(越界)
			}
		}
	}
}
void menu_final()
{
	help_input();
	menu_input();
	part1:menu0();
	do {
		while (1)
		{
			menu_getch_part();
			if (flag1)
			{
				menu0();
				flag1 = 0;
			}
			if (flag2 == 0)
				break;
		}
	} while (flag2);
	flag2 = 1;
	if (point() == 15)
			flag3 = 1;
	if (point() == 14)
	{
		flag5 = 1;
		
			do {
				while (1)
				{
					help_getch_part();
					if (flag5)
					{
						help();
                        flag5 = 0;
					}
					if (flag4)
						break;
				}
			} while (flag4 == 0);
			flag4 = 0;
			goto part1;
	}
}
