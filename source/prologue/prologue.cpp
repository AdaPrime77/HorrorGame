#include "prologue.hpp"

#include "DxLib.h"

/* Prologue関数用の変数 */
static int prologue_counter;

/* このファイルのための初期化関数 */
bool InitializePrologue(void){
	prologue_counter = 0;
return 0;
}

/* プロローグ表示関数 プロローグが終了すると1を返す 終了していないと0を返す */
bool Prologue(bool push_key[256], int one_key[256]){

	if(one_key[KEY_INPUT_SPACE] == 1){
		prologue_counter++;
	}
	
	if(prologue_counter == 1){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
	}else if(prologue_counter == 2){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
	}else if(prologue_counter == 3){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
	}else if(prologue_counter == 4){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
		DrawString(50, 130, "ここ数日待ち合わせ場所に現れないのだ。", GetColor(255, 255, 255));
	}else if(prologue_counter == 5){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
		DrawString(50, 130, "ここ数日待ち合わせ場所に現れないのだ。", GetColor(255, 255, 255));
		DrawString(50, 170, "ミカがそれと知ったのはそれからすぐだった。", GetColor(255, 255, 255));
	}else if(prologue_counter == 6){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
		DrawString(50, 130, "ここ数日待ち合わせ場所に現れないのだ。", GetColor(255, 255, 255));
		DrawString(50, 170, "ミカがそれと知ったのはそれからすぐだった。", GetColor(255, 255, 255));
		DrawString(50, 210, "はじめは病気か何かかと思っていた。", GetColor(255, 255, 255));
	}else if(prologue_counter == 7){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
		DrawString(50, 130, "ここ数日待ち合わせ場所に現れないのだ。", GetColor(255, 255, 255));
		DrawString(50, 170, "ミカがそれと知ったのはそれからすぐだった。", GetColor(255, 255, 255));
		DrawString(50, 210, "はじめは病気か何かかと思っていた。", GetColor(255, 255, 255));
		DrawString(50, 250, "でも", GetColor(255, 255, 255));
	}else if(prologue_counter == 8){
		DrawString(10, 10, "20xx年 3月 7日", GetColor(255, 255, 255));
		DrawString(50, 50, "高校に通うミカは異変に気付いた。", GetColor(255, 255, 255));
		DrawString(50, 90, "いつも一緒に通学する友人リョーコが", GetColor(255, 255, 255));
		DrawString(50, 130, "ここ数日待ち合わせ場所に現れないのだ。", GetColor(255, 255, 255));
		DrawString(50, 170, "ミカがそれと知ったのはそれからすぐだった。", GetColor(255, 255, 255));
		DrawString(50, 210, "はじめは病気か何かかと思っていた。", GetColor(255, 255, 255));
		DrawString(50, 250, "でも", GetColor(255, 255, 255));
		DrawString(50, 290, "リョーコは行方不明になっていた。", GetColor(255, 255, 255));
	}else if(prologue_counter >= 9){
		return 1;
	}

return 0;	
}