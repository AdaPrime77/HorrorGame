#include "utility/utility.hpp"
#include "title1/title1.hpp"
#include "prologue/prologue.hpp"
#include "game/game.hpp"
#include "initialize/initialize.hpp"

#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	/* Windowモードの設定 */
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);

	/* DxLibの初期化と裏画面設定 */
	if(DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0){
		return -1;
	}
	
	/* フォントサイズの変更 */
	SetFontSize(20);
	
	/* キー入力用の変数 */
	bool push[256];
	int one[256];
	
	/* main関数内で使う変数宣言 */
	short menu_select = 0;
	bool prologue_end = 0;
	
	/* 各cppファイルの初期化関数を呼ぶ */
	ResetTimer();
	InitializeAll();
	
	/* ゲームの骨格無限ループと()内で各種必要な関数呼び出し. */
	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && UpdateKey(push, one) == 0 && one[KEY_INPUT_ESCAPE] != 1){
		
		/* タイトル画面とセレクト画面 */
		if(menu_select == 0){
			menu_select = TitleMenu(push, one);
		}
		
		/* セレクト画面からの各処理 */
		if(menu_select == 1){
			/* プロローグ表示関数 */
			if(prologue_end == 0 && Prologue(push, one) == 1){
				prologue_end = 1;
			}
			if(prologue_end == 1){
				Game(push, one);
			}
		}else if(menu_select == 3){
			break;
		}
		
	}
	
	/* 終了の処理 */
	if(DxLib_End() == -1){
		return -1;
	}

return 0;
}
