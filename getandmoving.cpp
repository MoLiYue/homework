#include "stdafx.h"
#include "functions.h"
#include<conio.h>
#include<windows.h>
#include<stdlib.h>


int map[screen_height][map_length];				//
//int screen[screen_height][screen_length];		//
//int player[screen_height][screen_length];		//����һ��С������,δ������Ļ�ƶ������С�뵱ǰ��Ļ����screen��ͬ

char prev_direction = 'i';						//-------------��:����ȫ�ֱ���pre_direction,��ǰһ�������ķ���
char direction = 'i';
char ch1 = '0';
char ch2 = '0';
extern int x = 0, y = 0;	//���ͷ������
int dist_jump = 0;
int mark_jump = 0;
int dist_down = 0;
int mark_down = 0;
//extern int bullet_exist;
extern int bullet;
extern int hp_boss0;

/*
���̵ķ������Ȼ��������ֵ������Ҫ��ȡ���Σ����������ҵĵ�һ����ֵ����һ���ģ�ֻ�еڶ���������
��ֵ�����£�

��   -32 0xffffffe0 72 ascii���ӦΪ H
��   -32 0xffffffe0 80               P
��   -32 0xffffffe0 75               K
��   -32 0xffffffe0 77               M

*/

void getch_part()
{

	for (int s = 0; s < screen_height; s++)
	{
		for (int k = 0; k < map_length; k++)	//ͨ��ͷ��������ֵ��λС��ͷ��λ��
		{
			if (map[s][k] == head_value)
			{
				y = s;			//��������Ӧ������
				x = k;			//��������Ӧ������
			}
		}
	}


	if (_kbhit())				//�ж��Ƿ����밴��
	{
		ch1 = _getch();

		if (ch1 == -32)			//�Ƿ�Ϊ�����
		{
			ch2 = _getch();


			switch (ch2)
			{
			case 'H': if (y - jump_height <= 1) { direction = 'p'; }
					  else direction = 'w'; break;	//��

			case 'K': if ((x - move_left <= 0) || (map[y][x - move_left] == block1) || (map[y][x - move_left] == block2)) { direction = 'o'; }
					  else direction = 'a'; break;		//��

			case 'M': if ((x + move_right >= 899) || (map[y][x + move_right] == block1) || (map[y][x + move_right] == block2)) { direction = 'o'; }
					  else direction = 'd'; break;		//��

														//case 'P': direction = 's'; break; //�����¼���ʱ��Ҫ

			default:  direction = 'o'; break;		//�������(Խ��)
			}
		}
		else
		{
			if (ch1 == 'e' && bullet > 0)
			{
				bullet--;
				attack_l();
				ch1 = 0;
			}
			else if (ch1 == 'q' && bullet > 0)
			{
				bullet--;
				attack_r();
				ch1 = 0;
			}
		}
	}
	else
	{

		if (prev_direction == 'w')
		{
			direction = 'x';
			prev_direction = direction;
		}

	}

}

void moving_part(int map[screen_height][map_length])
{

	if ((prev_direction == 'w' || prev_direction == 'x' || prev_direction == 'k' || prev_direction == 'p') && (y + 1 <= 21))
	{


		system("cls");							//��:��������Խ��(���'p') ��  ��ǰһ������Ϊ��Ծ(���'w')����Ծ�����밴��(���'x')
												//����Ծ�������ƶ�(���'k')������󲻻�Խ��ʱ,ִ�����仭��

		check_height_down();

		if (mark_down)
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y + dist_down][x] += head_value;
			map[y + dist_down + 1][x] += body_value;
			map[y + dist_down + 1][x - 1] += body_value;
			map[y + dist_down + 1][x + 1] += body_value;
			map[y + dist_down + 2][x] += body_value;
			map[y + dist_down + 3][x - 1] += body_value;
			map[y + dist_down + 3][x + 1] += body_value;
		}
		else
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y + drop_height][x] += head_value;
			map[y + drop_height + 1][x] += body_value;
			map[y + drop_height + 1][x - 1] += body_value;
			map[y + drop_height + 1][x + 1] += body_value;
			map[y + drop_height + 2][x] += body_value;
			map[y + drop_height + 3][x - 1] += body_value;
			map[y + drop_height + 3][x + 1] += body_value;
		}
		//screen_creator(screen, player);			//��ӡ���仭��


		for (int s = 0; s < screen_height; s++)
		{
			for (int k = 0; k < map_length; k++)	//ͨ��ͷ��������ֵ��λС��ͷ��λ��
			{
				if (map[s][k] == head_value)
				{
					y = s;			//��������Ӧ������
					x = k;			//��������Ӧ������-----------------------��:���¶�λ����һ֡��С��λ��
				}
			}
		}
	}

	switch (direction)
	{
	case 'w':						//������� �Ҳ�Խ��
		system("cls");

		check_height_up();

		if (mark_jump)
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y - dist_jump][x] += head_value;
			map[y - dist_jump + 1][x] += body_value;
			map[y - dist_jump + 1][x - 1] += body_value;
			map[y - dist_jump + 1][x + 1] += body_value;
			map[y - dist_jump + 2][x] += body_value;
			map[y - dist_jump + 3][x - 1] += body_value;
			map[y - dist_jump + 3][x + 1] += body_value;

		}
		else
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y - jump_height][x] += head_value;
			map[y - jump_height + 1][x] += body_value;
			map[y - jump_height + 1][x - 1] += body_value;
			map[y - jump_height + 1][x + 1] += body_value;
			map[y - jump_height + 2][x] += body_value;
			map[y - jump_height + 3][x - 1] += body_value;
			map[y - jump_height + 3][x + 1] += body_value;

		}
		prev_direction = direction;   //------��:��¼��ǰ��������
		//screen_creator(screen, player); break;

		break;


	case 'a':					//��������Ҳ�Խ��
		system("cls");

		if ((map[y + 1][x - 1 - move_left] == 500) || (map[y + 1][x - 1 - move_left] == 505) || (map[y + 3][x - 1 - move_left] == 500) || (map[y + 3][x - 1 - move_left] == 505))
		{
			//����λ�ò���
		}
		else
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y][x - move_left] += head_value;
			map[y + 1][x - move_left] += body_value;
			map[y + 1][x - move_left - 1] += body_value;
			map[y + 1][x - move_left + 1] += body_value;
			map[y + 2][x - move_left] += body_value;
			map[y + 3][x - move_left - 1] += body_value;
			map[y + 3][x - move_left + 1] += body_value;
		}


		if (prev_direction == 'w' || prev_direction == 'x' || prev_direction == 'k')//��:��ǰһ������Ϊ��Ծ(�������)����Ծ�����°�������,ʹpre_direction ��ֵ��Ϊk
		{							                       //��Ӧ��Ծ���������ƶ������
			prev_direction = 'k';
		}

		direction = 'p';//��:�������ж����ӡ���������ʱ���ж���������,�����ƶ���Ҫ��direction��ֵ����Ϊ�������i
						//�������޺�����������С�˻�һֱ������������˶�(���һᴩ��)����ʹ��Ծ�������ƶ�С���޷�����,�����޸ĸ�Ϊ'p'

		break;


	case 'd':
		system("cls");

		if ((map[y + 1][x + 1 + move_right] == 500) || (map[y + 1][x + 1 + move_right] == 505) || (map[y + 3][x + 1 + move_right] == 500) || (map[y + 3][x + 1 + move_right] == 505))
		{
			//����λ�ò���
		}
		else
		{
			map[y][x] -= head_value;
			map[y + 1][x] -= body_value;
			map[y + 1][x - 1] -= body_value;
			map[y + 1][x + 1] -= body_value;
			map[y + 2][x] -= body_value;
			map[y + 3][x - 1] -= body_value;
			map[y + 3][x + 1] -= body_value;

			map[y][x + move_right] += head_value;
			map[y + 1][x + move_right] += body_value;
			map[y + 1][x + move_right - 1] += body_value;
			map[y + 1][x + move_right + 1] += body_value;
			map[y + 2][x + move_right] += body_value;
			map[y + 3][x + move_right - 1] += body_value;
			map[y + 3][x + move_right + 1] += body_value;
		}


		if (prev_direction == 'w' || prev_direction == 'x' || prev_direction == 'k')   //��:��ǰһ������Ϊ��Ծ(�������)����Ծ�����°�������,ʹpre_direction ��ֵ��Ϊk
		{													  //��Ӧ��Ծ���������ƶ������
			prev_direction = 'k';
		}

		direction = 'p';

		break;



	case 'p': prev_direction = direction;

	default:
		system("cls");		//�������(Խ��)����С��λ�ò���

		prev_direction = direction;   //------��:��¼��ǰ��������

		break;
	}


}


void check_height_up(void)
{
	mark_jump = 0;
	dist_jump = 0;
	for (int i = 1; i <= jump_height; i++)
	{
		if ((map[y - i][x] == block1) || (map[y - i][x] == block2))
		{
			dist_jump = i - 1;
			mark_jump = 1;
			return;
		}
	}
	for (int i = 1; i <= jump_height; i++)
	{
		if ((map[y + 1 - i][x + 1] == block1) || (map[y + 1 - i][x + 1] == block2) || (map[y + 1 - i][x - 1] == block1) || (map[y + 1 - i][x - 1] == block2))
		{
			dist_jump = i - 1;
			mark_jump = 1;
			return;
		}
	}

}

void check_height_down()
{
	mark_down = 0;
	dist_down = 0;

	for (int i = 1; i <= drop_height; i++)
	{
		if ((map[y + 3 + i][x + 1] == block1) || (map[y + 3 + i][x + 1] == block2) || (map[y + 3 + i][x + 1] == EDGE) || (map[y + 3 + i][x - 1] == EDGE) || (map[y + 3 + i][x - 1] == block1) || (map[y + 3 + i][x - 1] == block2))
		{
			dist_down = i - 1;
			mark_down = 1;
			return;
		}
	}

}

void attack_l()
{
	for (int i = 0; i <= 24; i++)
	{
		if (x + 2 < map_length&&x + 2 > 0)
		{
			if (map[y + 1][x + 2 + i] == boss0_head_value)
			{
				hp_boss0 -= 5;

				break;
			}
			else if (map[y + 1][x + 2 + i] == boss0_body_value)
			{
				hp_boss0 -= 2;

				break;
			}
			else if (map[y + 1][x + 2 + i] == 0)
			{

			}
			else
			{

				break;
			}
		}
		else { break; }

	}
}
void attack_r()
{
	for (int i = 0; i <= 24; i++)
	{
		if (x + 2 < map_length&&x + 2 > 0)
		{
			if (map[y + 1][x - 2 - i] == boss0_head_value)
			{
				hp_boss0 -= 5;
				break;
			}
			else if (map[y + 1][x - 2 - i] == boss0_body_value)
			{
				hp_boss0 -= 2;
				break;
			}
			else if (map[y + 1][x - 2 - i] == 0)
			{

			}
			else
			{

				break;
			}
		}
		else { break; }

	}

}