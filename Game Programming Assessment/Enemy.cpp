#include "Enemy.h"

Enemy::Enemy(int x, int y, int w, int h) {
	x_ = x;
	y_ = y;
	w_ = w;
	h_ = h;
}

int Enemy::getX() {
	return x_;
}

int Enemy::getY() {
	return y_;
}

int Enemy::getW() {
	return w_;
}

int Enemy::getH() {
	return h_;
}

void Enemy::getRgba(int& r, int& g, int& b, int& a) {
	r = rgba_[0];
	g = rgba_[1];
	b = rgba_[2];
	a = rgba_[3];
}

bool Enemy::getIsMovingRight() {
	return isMovingRight_;
}

void Enemy::setIsMovingRight(bool isMovingRight) {
	isMovingRight_ = isMovingRight;
}

void Enemy::move(int xMovement, int yMovement) {
	x_ += xMovement;
	y_ += yMovement;
}