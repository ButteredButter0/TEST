#include "Window.h"
#include <iostream>

Window::Window(std::string name, int x, int y, int w, int h, Uint32 flags) {
	
	windowPtr_ = SDL_CreateWindow(name.c_str(), x, y, w, h, flags);
	if (windowPtr_ == NULL) {
		printf("Error: Window could not be created.\n");
	}

	rendererPtr_ = SDL_CreateRenderer(windowPtr_, -1, SDL_RENDERER_ACCELERATED);
	if (rendererPtr_ == NULL) {
		printf("Error: Renderer initialisation failed.\n");
	}
}

void Window::getWindowSize(int& w, int& h) {
	SDL_GetWindowSize(windowPtr_, &w, &h);
}

void Window::renderPresent() {

	//Switches in render surface
	SDL_RenderPresent(rendererPtr_);
}

void Window::renderClear() {
	//Clear render surface with selected colour
	SDL_SetRenderDrawColor(rendererPtr_, 0, 0, 0, 255);

	SDL_RenderClear(rendererPtr_);
}


void Window::setWindowColour(int r, int g, int b, int a) {
	rgba_[0] = r;
	rgba_[1] = g;
	rgba_[2] = b;
	rgba_[3] = a;
}


void Window::drawRect(SDL_Rect rect, bool isFilled, int r, int g, int b, int a) {


	//Sets rectangle colour
	SDL_SetRenderDrawColor(rendererPtr_, r,g,b,a);

	//Filled rectangle
	if (isFilled == true) {
		SDL_RenderFillRect(rendererPtr_, &rect);
	}

	//Rectangle outline
	else {
		SDL_RenderDrawRect(rendererPtr_, &rect);
	}

}


void Window::renderText(TTF_Font* font, std::string text, bool isHighQuality, SDL_Color colour, SDL_Rect destination) {
	
	SDL_Surface* tempText = nullptr;

	//This is to create lower quality, lower demanding texture
	if ((isHighQuality) == false) {
		tempText = TTF_RenderText_Solid(font, text.c_str(), colour);
	}

	//This creates higher quality, higher demanding texture
	else {
		tempText = TTF_RenderText_Blended(font, text.c_str(), colour);
	}
	

	//Converts from surface to texture (lecture code)
	SDL_Texture* textTexture= SDL_CreateTextureFromSurface(rendererPtr_, tempText);

	//Free up memory
	SDL_FreeSurface(tempText);

	//Whole texture is rendered: is assumed that all the text is wanted to be rendered
	SDL_RenderCopy(rendererPtr_, textTexture, NULL, &destination);

	//Free up memory
	SDL_DestroyTexture(textTexture);

}