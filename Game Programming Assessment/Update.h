#ifndef UPDATE_H
#define UPDATE_H

#include "Input.h"
#include "Enemy.h"
#include "Player.h"

#include <SDL.h>
#include <vector>

//Update class stores objects, and passes to Input and Render classes via pointers when necessary

class Update {
private:
	int windowHeight_;
	int windowWidth_;

	Player* playerPtr_;

	//Helper function to perform checks for collisions between the player and the edge of the map
	void checkPlayerInMap();

public:
	//Requires input of screensize, so that all objects are kept within it
	//Needs pointer to the Input object used in the game loop (to change the state of objects based on input)
	//Sets starting points of enemies
	Update(int windowHeight, int windowWidth, Player* playerPtr);

	//Converts result of input to changes in game state, and applies remaining game logic
	//Update interface to be called once every frame
	void getUpdate();

};

#endif // !UPDATE_H