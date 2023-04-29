#pragma once

#include "Window.h"

//Inspired by lecture code
class Player {
private:
	//colour
	int rgba_[4] = { 255,0,0,255 };

	//Tracks which keys have been pressed
	bool wasdMovement_[4] = { false, false, false, false };

	//Stores position - x and y are top left
	int xywh_[4];

	//Stores the window for rendering
	Window* window_;

	//Determines how quickly player moves
	int movementSpeed_ = 3;

public:

	//Needs to recieve starting position and dimensions, as well as the window object for rendering
	Player(int x, int y, int w, int h, Window* window);

	//Recieves input of which direction to go
	void Input(bool wKeyPressed, bool aKeyPressed, bool sKeyPressed, bool dKeyPressed);

	//Moves x and y position based on movement
	void Update();

	void Render();


	//Needed for collision detection and to check if the player would go off screen
	void getPlayerPosition(int (&xywh) [4]);
	//Needed for collision detection and to check if the player would go off screen
	void getPlayerMovement(int(&wasd)[4]);

	//Needed to change player movement if player would travel off screen
	void setPlayerMovement(int xywh[4]);
	//Needed to change player position if player would travel off screen
	void setPlayerPosition(int x, int y);

	void getPlayerSpeed(int& movementSpeed);

};