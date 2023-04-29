#include "Render.h"
#include <iostream>

void Render::getRender() {
	window_.renderClear();


	//Carries out game object rendering
	playerPtr_->Render();

	//Gets timer for rendering
	timerPtr_->getGameTimer(gameTimer);
	//Converts timer from seconds to milliseconds
	gameTimer = gameTimer / 1000;

	//Renders timer in top left corner
	window_.renderText(fontPtr_, std::to_string(gameTimer), false, SDL_Color{ 17,220,246,200 }, SDL_Rect{ 0,0,50,50 });
	

	window_.renderPresent();
}

Render::Render(Window window, Player* playerPtr, Timer* timerPtr) : window_ { window } {
	playerPtr_ = playerPtr;
	timerPtr_ = timerPtr;

	//Need to load the font for the timer
	
	fontPtr_ = TTF_OpenFont(FONT_FILE_.c_str(), 16);
	if (fontPtr_ == nullptr) {
		std::cout << "Error: Font failed to load (Render file). Error code: " << TTF_GetError() << "\n";
	}

}