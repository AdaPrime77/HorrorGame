#include "object.hpp"

#include "DxLib.h"

bool ObjectTV(void){
	
	DrawString(0, 0, "テレビだ。何も移っていない。", GetColor(255, 255, 255));
	
return 0;
}

int ObjectManagement(int object_id){
	
	switch(object_id){
		
		case 3:
		DrawString(0, 0, "出口", GetColor(255, 255, 255));
		break;
		
		case 4:
			ObjectTV();
		break;
		
		case 5:
			DrawString(0, 0, "TU KU E", GetColor(255, 255, 255));
		break;
		
		case 6:
			DrawString(0, 0, "HON DA NA", GetColor(255, 255, 255));
		break;
		
	}
	
return 0;
}