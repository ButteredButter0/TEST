#include "Player.h"
#include <SDL.h>

#include <iostream>

Player::Player(int x, int y, int w, int h, Window* window) {
	xywh_[0] = x;
	xywh_[1] = y;
	xywh_[2] = w;
	xywh_[3] = h;
	window_ = window;
}

void Player::Input(bool wKeyPressed, bool aKeyPressed, bool sKeyPressed, bool dKeyPressed) {
	//std::cout << wasdMovement_[0];
	wasdMovement_[0] = wKeyPressed;
	wasdMovement_[1] = aKeyPressed;
	wasdMovement_[2] = sKeyPressed;
	wasdMovement_[3] = dKeyPressed;
}

void Player::Update() {
	if (wasdMovement_[0] == true)
	{
		xywh_[1]-= movementSpeed_;
	}
	if (wasdMovement_[1] == true)
	{
		xywh_[0]-= movementSpeed_;
	}
	if (wasdMovement_[2] == true)
	{
		xywh_[1]+= movementSpeed_;
	}
	if (wasdMovement_[3] == true)
	{
		xywh_[0]+= movementSpeed_;
	}
}

void Player::Render() {
	//Creates SDL rect to represernt current position
	SDL_Rect renderBox = { xywh_[0], xywh_[1], xywh_[2], xywh_[3] };
	window_->drawRect(renderBox, true, rgba_[0], rgba_[1], rgba_[2], rgba_[3]);
}

void Player::getPlayerPosition(int(&xywh)[4]) {
	xywh[0] = xywh_[0];
	xywh[1] = xywh_[1];
	xywh[2] = xywh_[2];
	xywh[3] = xywh_[3];
}

void Player::getPlayerMovement(int(&wasd)[4]) {
	wasd[0] = wasdMovement_[0];
	wasd[1] = wasdMovement_[1];
	wasd[2] = wasdMovement_[2];
	wasd[3] = wasdMovement_[3];
}



void Player::setPlayerMovement(int wasd[4]) {
	wasdMovement_[0] = wasd[0];
	wasdMovement_[1] = wasd[1];
	wasdMovement_[2] = wasd[2];
	wasdMovement_[3] = wasd[3];
}


void Player::setPlayerPosition(int x, int y) {
	xywh_[0] = x;
	xywh_[1] = y;
}

void Player::getPlayerSpeed(int& movementSpeed) {
	movementSpeed = movementSpeed_;
}