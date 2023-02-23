#include "utility.hpp"

#include "DxLib.h"

/* Timer関数用の変数 */
static unsigned long start;
static bool reset_timer;

/* 第一引数:押されているか 第二引数:1回でも押されたか */
bool UpdateKey(bool argument1[256], int argument2[256]){
	
	char temporary[256];
	
	GetHitKeyStateAll(temporary);
	
	for(short i = 0; i < 256; i++){
		
		if(temporary[i] == 1){
			
			argument2[i]++;
			
		}else{
			
			argument2[i] = 0;
			
		}
	
		argument1[i] = temporary[i];
	
	}
	
return 0;
}

/* この関数が呼ばれてから引数ミリ秒たったら1を返すたっていなかったら0を返す ResetTimer関数と一緒に使う */
bool Timer(unsigned long time){
	
	if(reset_timer == 0){
	
		start = GetNowCount();

		reset_timer = 1;
	
	}
	
	if(GetNowCount() - start >= 5000){
		
		return 1;
		
	}
	
return 0;
}

/* Timer関数の時間リセット ループの前で一度呼ぶこと */
bool ResetTimer(void){
	
	reset_timer = 0;
	
return 0;
}