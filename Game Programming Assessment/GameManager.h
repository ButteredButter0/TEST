#pragma once

#include "Player.h"
#include "Window.h"

//Class to handle starting and stopping the game
//Allows all game object pointers to be owned by one class
class GameManager {
public:
	
	//Creates game objects
	//As Game objects need a window to render to, takes window as input too
	//Pointer of pointer needed so that game objects pointers themselves are passed by pointer, not value
	void gameSetup(int windowHeight, int windowWidth, Player** player, Window* window);
};