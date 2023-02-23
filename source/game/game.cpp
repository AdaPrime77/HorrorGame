#include "game.hpp"

#include "game_draw.hpp"
#include "hero.hpp"
#include "map.hpp"
#include "npc.hpp"
#include "object.hpp"

#include "DxLib.h"

/* map用2次元配列 */
static int map[640][480];

int Game(bool push_key[256], int one_key[256]){
	
	static bool initialize_map_flag = 0;
	static bool first_event_flag = 0;
	
	static int hero_direction;

	/* マップの描画 */
	if(initialize_map_flag == 0){
		InitalizeMap1(map);
		initialize_map_flag = 1;
	}else{
		DrawMap1(map);
	}

	/* 主人公の描画 */
	HeroAnimation();
	
	/* リョーコ母の描画 */
	if(first_event_flag == 0 && DrawRyokoMother(one_key) == 1){
		first_event_flag = 1;
	}
	
	if(first_event_flag == 1 && GoRyokoMother() == 1){
		
		/* 主人公の操作 */
		HeroMove(push_key, map);
		hero_direction = SendHeroDataD();
		ObjectManagement(HeroSerch(one_key, map, hero_direction));

	}
	
return 0;
}