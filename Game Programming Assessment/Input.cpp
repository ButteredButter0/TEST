#include "Input.h"
#include <SDL.h>
#include <iostream>

Input::Input(Player* playerPtr) {
	playerPtr_ = playerPtr;

	//Sets all keyboard inputs to false
	for (int i = 0; i < sizeof(gKeys_); i++) {
		gKeys_[i] = false;
	}
}

//Inspired by lecture slide code
void Input::getInput() {

	//SDL event handler
	SDL_Event event;

	//Loops to deal with every input
	while (SDL_PollEvent(&event)) {

		 

			//Handles keyboard input
		    //Check for repeat key presses allows diagonal movement
			if (event.type == SDL_KEYDOWN && event.key.repeat == NULL) {
				switch (event.key.keysym.sym) {

				case SDLK_w:
					gKeys_[SDLK_w] = true;
					break;

				case SDLK_a:
					gKeys_[SDLK_a] = true;
					break;

				case SDLK_s:					
					gKeys_[SDLK_s] = true;				
					break;

				case SDLK_d:
					gKeys_[SDLK_d] = true;					
					break;
				}

			}

		    //Handles keyboard input(key released)
			if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {

				case SDLK_w:
					gKeys_[SDLK_w] = false;
					break;

				case SDLK_a:
					gKeys_[SDLK_a] = false;
					break;

				case SDLK_s:
					gKeys_[SDLK_s] = false;
					break;

				case SDLK_d:
					gKeys_[SDLK_d] = false;
					break;
				}
			}
		
	}

	
	//Provides objects with input
	//std::cout << gKeys_[SDLK_w] << " " << gKeys_[SDLK_a] << " " << gKeys_[SDLK_s] << " " << gKeys_[SDLK_d] << std::endl;
	playerPtr_->Input(gKeys_[SDLK_w], gKeys_[SDLK_a], gKeys_[SDLK_s], gKeys_[SDLK_d]);
}
