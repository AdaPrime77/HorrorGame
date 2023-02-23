#include "title1.hpp"

#include "DxLib.h"

/* TitleMenu関数用の変数 */
static short select_menu;

/* 描画用のデータハンドル */
static int title;

bool InitializeTitle1(void){
	select_menu = 1;

	title = LoadGraph("images/title1/title1.png");
return 0;
}

short TitleMenu(bool push_key[256], int one_key[256]){

	DrawGraph(0, 0, title, FALSE);
	DrawString(278, 228, "はじめる", GetColor(255, 255, 255));
	DrawString(288, 330, "おわる", GetColor(255, 255, 255));
	
	if(select_menu == 1 && one_key[KEY_INPUT_S] == 1){
		select_menu = 3;
	}else if(select_menu == 3 && one_key[KEY_INPUT_W] == 1){
		select_menu = 1;
	}
	
	switch(select_menu){
		
		case 1:
			DrawBox(236, 228, 236+19, 228+19, GetColor(255, 255, 255), TRUE);
			if(one_key[KEY_INPUT_SPACE] == 1){
				return 1;
			}
		break;
		
		case 3:
			DrawBox(236, 330, 236+19, 330+19, GetColor(255, 255, 255), TRUE);
			if(one_key[KEY_INPUT_SPACE] == 1){
				return 3;
			}
		break;
		
	}
	
return 0;
}