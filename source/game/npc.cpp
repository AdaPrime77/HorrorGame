#include "npc.hpp"

#include "DxLib.h"

static int ryoko_mother_x;
static int ryoko_mother_y;
static short ryoko_mother_direction;

static int ryoko_mother_animation[24];
static int text_box;

bool InitializeNPC(void){

	ryoko_mother_x = 32*6;
	ryoko_mother_y = 32*7;
	ryoko_mother_direction = 1;

	LoadDivGraph("images/ryoko_mother/ryoko_mother.png", 24, 6, 4, 32, 48, ryoko_mother_animation);
	text_box = LoadGraph("images/text/text_box.png");
	
return 0;
}

bool DrawRyokoMother(int one_key[256]){
	
	static bool talk_flag = 0;
	static short talk_counter = 0;
	
	if(talk_flag == 0){
		
		switch(talk_counter){
			
			case 0:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
			break;
			
			case 1:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
				DrawGraph(0, 336, text_box, FALSE);
				DrawString(16, 352, "ごめんね。来てもらっちゃって。", GetColor(255, 255, 255));
			break;
			
			case 2:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
				DrawGraph(0, 336, text_box, FALSE);
				DrawString(16, 352, "ごめんね。来てもらっちゃって。", GetColor(255, 255, 255));
				DrawString(16, 382, "ミカちゃんはあの子と仲がよかったでしょう。", GetColor(255, 255, 255));				
			break;
			
			case 3:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
				DrawGraph(0, 336, text_box, FALSE);
				DrawString(16, 352, "ごめんね。来てもらっちゃって。", GetColor(255, 255, 255));
				DrawString(16, 382, "ミカちゃんはあの子と仲がよかったでしょう。", GetColor(255, 255, 255));
				DrawString(16, 412, "だから何か気になるところがないか調べてほしいの。", GetColor(255, 255, 255));
			break;
			
			case 4:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
				DrawGraph(0, 336, text_box, FALSE);	
				DrawString(16, 352, "なんでもいいわ。気になるところ、あの子への手がかりがあれば", GetColor(255, 255, 255));
				DrawString(16, 382, "教えてちょうだい。", GetColor(255, 255, 255));
			break;
			
			case 5:
				DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[13], TRUE);
				DrawGraph(0, 336, text_box, FALSE);	
				DrawString(16, 352, "私は下にいるから。", GetColor(255, 255, 255));
			break;
			
			default:
				return 1;
			break;

		}
		
	}
	
	if(one_key[KEY_INPUT_SPACE] == 1){
		talk_counter++;
	}
	
return 0;
}

bool GoRyokoMother(void){
	
	if(ryoko_mother_y < 32*9){

		ryoko_mother_y++;

		if(ryoko_mother_y % 32 >= 0 && ryoko_mother_y % 32 <= 7){
			DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[1], TRUE);
		}else if(ryoko_mother_y % 32 >= 8 && ryoko_mother_y % 32 <= 15){
			DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[0], TRUE);
		}else if(ryoko_mother_y % 32 >= 16 && ryoko_mother_y % 32 <= 23){
			DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[1], TRUE);
		}else if(ryoko_mother_y % 32 >= 24 && ryoko_mother_y % 32 <= 31){
			DrawGraph(ryoko_mother_x, ryoko_mother_y, ryoko_mother_animation[2], TRUE);
		}

	}else{
		return 1;
	}
	
return 0;
}