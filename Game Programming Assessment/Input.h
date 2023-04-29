#ifndef INPUT_H
#define INPUT_H

#include "Player.h"

//Inspired by lecture slide code
class Input{
private:

	bool gKeys_[256];

	Player* playerPtr_;
public:

	//Constructor needed for references to game objects
	Input(Player* playerPtr);

	//Captures relevant input from user
	//Input interface be called every frame
	void getInput();


};

#endif // !INPUT_H