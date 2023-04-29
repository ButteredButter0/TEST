#ifndef RENDER_H
#define RENDER_H
#include "Window.h"
#include "Update.h"
#include "Timer.h"

#include <SDL_ttf.h>
#include <string>

class Render {
private:
	Window window_;

	Player* playerPtr_;

	//Variables needed for rendering timer
	int gameTimer = 0;
	Timer* timerPtr_;
	TTF_Font* fontPtr_;
	std::string FONT_FILE_ = "Fonts/monogram.ttf";

	

public:
	//Needs a window to render to, and a pointer to the update object used in the game loop (to get the state of objects to render)
	//Also needs game objects to render, and the timer object to get the timer for rendering
	Render(Window windowr, Player* playerPtr, Timer* timerPtr);

	//Gets state of objects from update, and renders them to the screen
	//Interface of render to be called every frame
	void getRender();
};

#endif // !RENDER_H