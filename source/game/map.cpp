#include "map.hpp"

/* mapデータにmap1を書き込む 0:床 1:黒 2:壁 3:出口 */
bool InitalizeMap1(int argument[640][480]){
	
	/* 全体を0で初期化 */
	for(short x = 0; x < 640; x++){
		
		for(short y = 0; y < 480; y++){
			
			argument[x][y] = 0;
			
		}
		
	}
	
	/* 黒枠で囲む */
	for(short x = 0; x < 32*5; x++){
		
		for(short y = 0; y < 480; y++){
			
			argument[x][y] = 1;
			
		}
		
	}
	for(short x = 480; x < 640; x++){
		
		for(short y = 0; y < 480; y++){
			
			argument[x][y] = 1;
			
		}
		
	}
	for(short y = 0; y < 32*5; y++){
		
		for(short x = 0; x < 640; x++){
			
			argument[x][y] = 1;
			
		}
		
	}
	for(short y = 320; y < 480; y++){
		
		for(short x = 0; x < 640; x++){
		
			argument[x][y] = 1;
		
		}
		
	}
	/* 壁(2) */
	for(short x = 32*5; x < 480; x++){
		
		for(short y = 32*3; y < 32*5; y++){
			
			argument[x][y] = 2;
			
		}
		
	}
	/* 出口 */
	argument[32*5][32*10] = 3;
	argument[32*6][32*10] = 3;
	
	/* 机 */
	for(int x = 32*12; x < 32*14; x++){
		
		for(int y = 32*4; y < 32*5; y++){
			
			argument[x][y] = 5;
			
		}
		
	}
	
	/* 本棚 */
	for(int x = 32*8; x < 32*10; x++){
		
		for(int y = 32*4; y < 32*5; y++){
			
			argument[x][y] = 6;
			
		}
		
	}

return 0;
}