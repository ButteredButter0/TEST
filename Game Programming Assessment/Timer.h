#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
	//Const var for frame rate;
	const float FRAME_TIME_;
	int timeStart_ = 0;
	int timeEnd_ = 0;
	int totalTime_ = 0;

public:
	//Set frame rate in constructor
	//converts "fps" frame rate to actual frame rate
	Timer (int frameRate);

	//Call at the start of game loop
	void startTimer();

	//Call at the end of game loop
	void endTimer();

	//Gets the game timer:needed for rendering/closing the game
	void getGameTimer(int& gameTimer);
};

#endif // !TIMER_H
