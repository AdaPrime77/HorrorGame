#include "game_draw.hpp"
#include "hero.hpp"

#include "DxLib.h"

/* 画像用データハンドル */
static int tile[40];
static int wall[104];
static int hero_animation[24];
static int funiture1[256];
static int funiture3[576];

/* 主人公の歩行モーション関数用の変数 */
static int animation_hero_x;
static int animation_hero_y;
static short animation_direction;
static bool animation_hero_stop;

/* このファイルの初期化関数 */
bool InitalizeGameDraw(void){
	
	LoadDivGraph("images/map1/tile.png", 40, 8, 5, 32, 32, tile);
	LoadDivGraph("images/map1/wall.png", 104, 8, 13, 32, 32, wall);
	LoadDivGraph("images/hero/hero.png", 24, 6, 4, 32, 48, hero_animation);
	LoadDivGraph("images/map1/funiture1.png", 256, 16, 16, 32, 32, funiture1);
	LoadDivGraph("images/map1/funiture3.png", 576, 24, 24, 32, 32, funiture3);
	
return 0;
}

/* マップ1描画関数 */
bool DrawMap1(int argument[640][480]){

	for(short x = 0; x < 640; x = x + 32){
		
		for(short y = 0; y < 480; y = y + 32){
			
			/* 床の描画 */
			if(argument[x][y] == 0 || argument[x][y] == 3){
				
				DrawGraph(x, y, tile[16], FALSE);
				
			}
			
			/* 壁の描画 */
			if(argument[x][y] == 2){
				
				if(y == 32*3){
					
					DrawGraph(x, y, wall[25], FALSE);	
					
				}else if(y == 32*4){
					
					DrawGraph(x, y, wall[41], FALSE);
					
				}
				/* 微調整 */
				DrawGraph(32*5, 32*3, wall[24], FALSE);
				DrawGraph(32*5, 32*4, wall[40], FALSE);
				DrawGraph(448, 32*3, wall[26], FALSE);
				DrawGraph(448, 32*4, wall[42], FALSE);
				DrawGraph(320, 32*3, wall[24], FALSE);
				DrawGraph(320, 32*4, wall[40], FALSE);
				DrawGraph(288, 32*3, wall[26], FALSE);
				DrawGraph(288, 32*4, wall[42], FALSE);
				
			}
			
			/* 机の描画 */
			DrawGraph(32*12, 32*3, funiture3[372], TRUE);
			DrawGraph(32*13, 32*3, funiture3[373], TRUE);
			DrawGraph(32*14, 32*3, funiture3[374], TRUE);
			DrawGraph(32*12, 32*4, funiture3[396], TRUE);
			DrawGraph(32*13, 32*4, funiture3[397], TRUE);
			DrawGraph(32*14, 32*4, funiture3[398], TRUE);
			DrawGraph(32*12, 32*5, funiture3[423], TRUE);
			DrawGraph(32*13, 32*5, funiture3[424], TRUE);
			DrawGraph(32*14, 32*5, funiture3[425], TRUE);
			
			/* 本棚の描画 */
			DrawGraph(32*8, 32*3, funiture3[360], TRUE);
			DrawGraph(32*9, 32*3, funiture3[361], TRUE);
			DrawGraph(32*10, 32*3, funiture3[362], TRUE);
			DrawGraph(32*8, 32*4, funiture3[384], TRUE);
			DrawGraph(32*9, 32*4, funiture3[385], TRUE);
			DrawGraph(32*10, 32*4, funiture3[386], TRUE);
			DrawGraph(32*8, 32*5, funiture3[408], TRUE);
			DrawGraph(32*9, 32*5, funiture3[409], TRUE);
			DrawGraph(32*10, 32*5, funiture3[410], TRUE);
			
			/* TVの描画 */
			DrawGraph(32*5, 32*4, funiture1[13], TRUE);
			DrawGraph(32*5, 32*5, funiture1[28], TRUE);
			
		}
		
	}

return 0;	
}

/* 主人公の歩行モーション関数 */
int HeroAnimation(void){
	
	/* 描画のために主人公のデータ取得 */
	animation_direction = SendHeroDataD();
	animation_hero_stop = SendHeroDataS();
	animation_hero_x = SendHeroDataX();
	animation_hero_y = SendHeroDataY();
	
	if(animation_direction == 1){
		if(animation_hero_stop == 1){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[19], TRUE);
		}else if(animation_hero_y % 32 >= 0 && animation_hero_y % 32 <= 7){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[19], TRUE);
		}else if(animation_hero_y % 32 >= 8 && animation_hero_y % 32 <= 15){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[20], TRUE);
		}else if(animation_hero_y % 32 >= 16 && animation_hero_y % 32 <= 23){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[19], TRUE);
		}else if(animation_hero_y % 32 >= 24 && animation_hero_y % 32 <= 31){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[18], TRUE);
		}
	}else if(animation_direction == 2){
		if(animation_hero_stop == 1){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[7], TRUE);
		}else if(animation_hero_x % 32 >= 0 && animation_hero_x % 32 <= 7){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[7], TRUE);
		}else if(animation_hero_x % 32 >= 8 && animation_hero_x % 32 <= 15){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[8], TRUE);
		}else if(animation_hero_x % 32 >= 16 && animation_hero_x % 32 <= 23){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[7], TRUE);
		}else if(animation_hero_x % 32 >= 24 && animation_hero_x % 32 <= 31){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[6], TRUE);
		}			
	}else if(animation_direction == 3){
		if(animation_hero_stop == 1){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[1], TRUE);
		}else if(animation_hero_y % 32 >= 0 && animation_hero_y % 32 <= 7){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[1], TRUE);
		}else if(animation_hero_y % 32 >= 8 && animation_hero_y % 32 <= 15){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[0], TRUE);
		}else if(animation_hero_y % 32 >= 16 && animation_hero_y % 32 <= 23){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[1], TRUE);
		}else if(animation_hero_y % 32 >= 24 && animation_hero_y % 32 <= 31){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[2], TRUE);
		}			
	}else if(animation_direction == 4){
		if(animation_hero_stop == 1){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[13], TRUE);
		}else if(animation_hero_x % 32 >= 0 && animation_hero_x % 32 <= 7){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[13], TRUE);
		}else if(animation_hero_x % 32 >= 8 && animation_hero_x % 32 <= 15){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[14], TRUE);
		}else if(animation_hero_x % 32 >= 16 && animation_hero_x % 32 <= 23){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[13], TRUE);
		}else if(animation_hero_x % 32 >= 24 && animation_hero_x % 32 <= 31){
			DrawGraph(animation_hero_x, animation_hero_y, hero_animation[12], TRUE);
		}		
	}
	
return 0;
}