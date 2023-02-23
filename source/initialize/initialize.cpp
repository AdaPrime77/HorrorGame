#include "initialize.hpp"

#include "../title1/title1.hpp"
#include "../prologue/prologue.hpp"
#include "../game/game_draw.hpp"
#include "../game/hero.hpp"
#include "../game/npc.hpp"

bool InitializeAll(void){
	
	/* title1.cpp */
	InitializeTitle1();
	/* prologue.cpp */
	InitializePrologue();
	/* game_draw.cpp */
	InitalizeGameDraw();
	/* hero.cpp */
	InitializeHero();
	/* npc.cpp */
	InitializeNPC();
	
return 0;
}