#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Window {
private:
	SDL_Window* windowPtr_ = NULL;
	SDL_Renderer* rendererPtr_ = NULL;

	//Background colours for RenderClear
	//Deafaulted to black
	int rgba_[4] = { 0,0,0,255 };

public:

	//Creates window, gets window's screen surface and a renderer
	//Creates a window of specified size, name and with relevant flags
	Window(std::string name, int x, int y, int w, int h, Uint32 flags);


	//Returns screen size (using output variables)
	void getWindowSize(int& w, int& h);

	//To be called after every drawing function has been used (updates the screen)
	void renderPresent();

	//To be called before drawing next frame
	void renderClear();

	//Sets the background colour of the window
	void setWindowColour(int r, int g, int b, int a);

	//Draws a rectangle at the given coordinates (top left corner) and at the given size,
	//and in the given colour
	void drawRect(SDL_Rect rect, bool isFilled, int r, int g, int b, int a);


	//Renders text at given coordinates (as texture)
	void renderText(TTF_Font* font, std::string text, bool isHighQuality, SDL_Color colour, SDL_Rect destination);
};

#endif // !WINDOW_H