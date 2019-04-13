#pragma once

#define speed 300
#define screen_length 120			
#define screen_height 26
#define map_length 360							 
#define head_x  21           //按照26*58的screen(如果没有地板实际为0~25,0~57)player占4行3列
#define head_y  1	         //将头的初始位置定为(1,21)
#define head_value 100	     //小人头的特定值,用来定位小人位置
#define body_value 50
#define jump_height 6		 //跳跃高度----------------------------------------新:跳跃高度改为6,跳跃后每帧会下落2
#define drop_height 2		 //每帧回落高度
#define move_right 1         //右移格数
#define move_left 1          //左移格数
#define boss0_x 19          
#define boss0_y (map_length-6)
#define boss0_hp 20
//#define check_move_l ((map[x_boss0][y_boss0+1]==0||map[x_boss0][y_boss0+1]==body_value||map[x_boss0][y_boss0+1]==head_value)&&(map[x_boss0+1][y_boss0+2]==0||map[x_boss0+1][y_boss0+2]==body_value||map[x_boss0+1][y_boss0+2]==head_value)&&(map[x_boss0+2][y_boss0+3]==0||map[x_boss0+2][y_boss0+3]==body_value||map[x_boss0+2][y_boss0+3]==head_value)&&(map[x_boss0+3][y_boss0+4]==0||map[x_boss0+3][y_boss0+4]==body_value||map[x_boss0+3][y_boss0+4]==head_value)&&(map[x_boss0+4][y_boss0+5]==0||map[x_boss0+4][y_boss0+5]==body_value||map[x_boss0+4][y_boss0+5]==head_value)&&(map[x_boss0+5][y_boss0+6]==0||map[x_boss0+5][y_boss0+6]==body_value||map[x_boss0+5][y_boss0+6]==head_value))
//#define check_move_r ((map[x_boss0][y_boss0-1]==0||map[x_boss0][y_boss0-1]==body_value||map[x_boss0][y_boss0-1]==head_value)&&(map[x_boss0+1][y_boss0-2]==0||map[x_boss0+1][y_boss0-2]==body_value||map[x_boss0+1][y_boss0-2]==head_value)&&(map[x_boss0+2][y_boss0-3]==0||map[x_boss0+2][y_boss0-3]==body_value||map[x_boss0+2][y_boss0-3]==head_value)&&(map[x_boss0+3][y_boss0-4]==0||map[x_boss0+3][y_boss0-4]==body_value||map[x_boss0+3][y_boss0-4]==head_value)&&(map[x_boss0+4][y_boss0-5]==0||map[x_boss0+4][y_boss0-5]==body_value||map[x_boss0+4][y_boss0-5]==head_value)&&(map[x_boss0+5][y_boss0-6]==0||map[x_boss0+5][y_boss0-6]==body_value||map[x_boss0+5][y_boss0-6]==head_value))
int check_jump();
int check_drop();

                             //boss0:   @          
                             //        @@@      
                             //       @@@@@     
                             //      @@@@@@@      
                             //     @@@@@@@@@      
                             //    @    @    @     



#define EDGE 9             //地图上下边界的特殊值

//地形
#define block1 500           //=
#define block2 505           //|
#define cone1 700            //^（陷阱，触碰即死）
#define cone2 710            //v (陷阱，触碰即死）

//道具
#define item_gun 2000        //?
#define item_player_health 2010    //*
//boss
#define boss0_head_value 5000
#define boss0_body_value 5010
extern int map[screen_height][map_length];

void player_creator(int map[screen_height][map_length]);

void screen_creator(int map[screen_height][map_length]);

void check_height_up();
void check_height_down();
void moving_part(int map[screen_height][map_length]);
void getch_part();

void main_process();
void viewmove();
void Level_0_asset(int map[screen_height][map_length]);
void Trigger();
void boss_asset();
void attack_l();
void attack_r();
void menu();
void menu_getch_part();
void menu_input();
void menu0();
void menu_final();

