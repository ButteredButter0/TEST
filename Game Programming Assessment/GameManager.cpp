#include "GameManager.h"


void GameManager::gameSetup(int windowHeight, int windowWidth, Player** player, Window* window) {
	int PLAYERHEIGHT = 40;
	int PLAYERWIDTH = 20;
	*player = new Player((windowWidth / 2) - PLAYERWIDTH/2, (windowHeight / 2) - PLAYERHEIGHT / 2, PLAYERWIDTH, PLAYERHEIGHT, window);

}