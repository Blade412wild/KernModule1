#include "Player.h"
#include <iostream> 

Player::Player(int w, int h){
	width = w;
	height = h;
	std::cout << width << ", " << height << std::endl;
	

}

void Player::setAlpha(float a) {
	alpha = a;
}
float Player::area() {
	return width * height;
}
void Player::draw() {

}
