#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

//constructor
Enemy::Enemy(int _enemyID) {

	enemyID = _enemyID;
	std::cout << "Enemy : " << enemyID << " Added to the list" <<  std::endl;

}

//CopyConstructor
Enemy::Enemy(const Enemy& source) {
	std::cout << "Copy Constructor called" << std::endl;

	enemyID = source.enemyID;

}

//overloaded Assignment operator
Enemy& Enemy::operator=(const Enemy& source) {
	std::cout << "overloaded Assignment called" << std::endl;

	//Check for self assignment
	if (this == &source) {
		return *this;
	}

	enemyID = source.enemyID;

	return *this;

}

//Destructor
Enemy::~Enemy() {
	std::cout << "destructor called for this vector  @ this memory location " << this << std::endl;
}

bool Enemy::BenIkLaagGenoeg(float _playerPosY) {

	if (currentPosY >= (_playerPosY - 100.0f)) {
		return true;
	}
	else {

		return true;
	}
}



bool Enemy::IsThereCollission(float PlayerPosX, float PlayerPosY) {
	float C1r = 50.0f;
	float C2r = 50.0f;


	float num = PlayerPosX - currentPosX;
	float num2 = PlayerPosY - currentPosY;


	float _sqrtDistance1 = (num * num + num2 * num2);
	float _distance = _sqrtDistance1 - ((C1r + C2r) * (C1r + C2r));
	float _inBetweenDistance = _distance - ((C1r + C2r) * (C1r + C2r));

	//std::cout << "_distance 1 : " << _distance << std::endl;
	//std::cout << "_inBetweenDistance 1 : " << _inBetweenDistance << std::endl;

	if (_inBetweenDistance < 0) {
		return true;
	}
	else if (_inBetweenDistance > 0) {
		return false;
	}
	else {
		return true;
	}

	return false;
}

void Enemy::DrawEnemy(sf::RenderWindow* window){

	sf::CircleShape EnemyCollission(EnemyCollissionRadius, 30.0f);
	sf::RectangleShape Enemy(sf::Vector2f(EnemyWidth, EnemyHeight));

	window->draw(Enemy);
	window->draw(EnemyCollission);


}


