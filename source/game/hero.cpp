#include "hero.hpp"

#include "DxLib.h"

/* heroの座標データ */
static int hero_x;
static int hero_y;
static short direction;
static bool can_move_flag; /* 1:動ける 0:動けない */
static bool hero_stop_flag; /* 1:止まっている 0:動いている */

bool InitializeHero(void){

	hero_x = 32*12;
	hero_y = 32*7;
	direction = 2;
	can_move_flag = 1;
	hero_stop_flag = 1;

return 0;
}

/* 歩行アニメーション用に戻り値を返す 1:前 2:左 3:後ろ 4:右 5:止まる */
int HeroMove(bool push_key[256], int map_data[640][480]){
	
	can_move_flag = 1;
	
	if(push_key[KEY_INPUT_W] == 1 && can_move_flag == 1){
		direction = 1;
		if(map_data[hero_x + 1][hero_y + 32 - 2] == 0 && map_data[hero_x + 31][hero_y + 32 - 2] == 0){
			hero_stop_flag = 0;
			hero_y--;
		}
	}else if(push_key[KEY_INPUT_A] == 1 && can_move_flag == 1){
		direction = 2;
		if(map_data[hero_x + 1 - 2][hero_y + 47] == 0 && map_data[hero_x + 1 - 2][hero_y + 47] == 0){
			hero_stop_flag = 0;
			hero_x--;
		}
	}else if(push_key[KEY_INPUT_S] == 1 && can_move_flag == 1){
		direction = 3;
		if(map_data[hero_x + 1][hero_y + 47 + 2] == 0 && map_data[hero_x + 31][hero_y + 47] == 0){
			hero_stop_flag = 0;
			hero_y++;
		}
	}else if(push_key[KEY_INPUT_D] == 1 && can_move_flag == 1){
		direction = 4;
		if(map_data[hero_x + 31 + 2][hero_y + 32] == 0 && map_data[hero_x + 31 + 2][hero_y + 47] == 0){
			hero_stop_flag = 0;
			hero_x++;
		}
	}else if(push_key[KEY_INPUT_W] == 0 && push_key[KEY_INPUT_A] == 0 && push_key[KEY_INPUT_S] == 0 && push_key[KEY_INPUT_D] == 0){
		hero_stop_flag = 1;
	}
	
return 0;
}

/* 何もオブジェクトを調べていなければ0を返す 何かオブジェクトを調べたらそれに対応する整数値を返す */
int HeroSerch(int one_key[256], int map[640][480], int direction){
	
	int object_id = 0;
	
	if(direction == 3 && one_key[KEY_INPUT_SPACE] == 1){
		
		switch(map[hero_x + 1][hero_y + 47 + 2]){
			
			/* 出口 */
			case 3:
				object_id = 3;
			break;
			
			/* TV */
			case 4:
				object_id = 4;
			break;
			
			/* 机 */
			case 5:
				object_id = 5;
			break;
			
			/* 本棚 */
			case 6:
				object_id = 6;
			break;
			
			default:
			break;
			
		}
		
	}
	
return object_id;
}

int SendHeroDataX(void){
	return hero_x;
}

int SendHeroDataY(void){
	return hero_y;
}

short SendHeroDataD(void){
	return direction;
}

bool SendHeroDataS(void){
	return hero_stop_flag;
}