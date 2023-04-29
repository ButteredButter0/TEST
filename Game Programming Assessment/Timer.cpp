#include "Timer.h"
#include <SDL.h>


Timer::Timer(int frameRate) : FRAME_TIME_(1000/(float)frameRate) {};

void Timer::startTimer() {
	timeStart_ = SDL_GetTicks();
}

void Timer::endTimer() {
	timeEnd_ = SDL_GetTicks() - timeStart_;
	if (timeEnd_ < FRAME_TIME_) {
		//Waits until end of frame timer so next frame is not called early
		SDL_Delay(FRAME_TIME_ - timeEnd_);
	}
	//Updates the overall game timer
	totalTime_ += SDL_GetTicks() - totalTime_;
}

void Timer::getGameTimer(int& gameTimer) {
	gameTimer = totalTime_;
}