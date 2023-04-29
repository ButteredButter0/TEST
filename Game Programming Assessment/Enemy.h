#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
	//colour
	int rgba_[4] = { 255,0,0,255 };

	//dimensions of rectangle
	int x_;
	int y_;
	int w_;
	int h_;

	//movement state
	bool isMovingRight_ = true;

public:

	Enemy(int x, int y, int w, int h);

	//getters
	int getX();
	int getY();
	int getW();
	int getH();
	void getRgba(int& r, int& g, int& b, int& a);
	bool getIsMovingRight();

	//setter
	void setIsMovingRight(bool isMovingRight);

	//Moves enemy by given x and y values
	void move(int xMovement, int yMovement);
};


#endif // !ENEMY_H
