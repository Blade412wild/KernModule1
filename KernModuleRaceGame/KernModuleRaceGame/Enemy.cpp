#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "PhysicsObject.h"



//constructor
Enemy::Enemy(int _enemyID) 
{

	enemyID = _enemyID;
	std::cout << "Enemy : " << enemyID << " Added to the list" << std::endl;

	enemyRect = sf::RectangleShape(sf::Vector2f(EnemyWidth, EnemyHeight));
	enemyCircle = sf::CircleShape(EnemyCollissionRadius, 30.0f);

	beginPosX = std::rand() % 1920;

	currentPosX = beginPosX;
	goingRight = BeginMoveDirectionDecider();
}

//CopyConstructor
Enemy::Enemy(const Enemy& source) {
	std::cout << "Copy Constructor called" << std::endl;

	enemyID = source.enemyID;

	goingRight = BeginMoveDirectionDecider();
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

void Enemy::MoveEnemy() {
	PlayTimeMoveDirectionDecider();
	DrawEnemy();
	currentPosX = NewPosCalulationX(currentPosX);
	currentPosY = NewPosCalulationY(currentPosY);

	//std::cout << "enemyID : " << enemyID << " CurrentPosY : " << currentPosY << " & CurrentPosX : " << currentPosX << std::endl;
}

float Enemy::NewPosCalulationY(float _currentpos) {

	float _newPos;
	_newPos = _currentpos + physicsObject.CalculatingDisplacement(1200.0f, 0);
	return _newPos;
}

float Enemy::NewPosCalulationX(float _currentpos) {
	float _newPos;
	if (goingRight == true) {
		_newPos = _currentpos + physicsObject.CalculatingDisplacement(1200.0f, 0);
	}
	else {
		_newPos = _currentpos - physicsObject.CalculatingDisplacement(1200.0f, 0);

	}
	return _newPos;
}

void Enemy::PlayTimeMoveDirectionDecider() {
	if (currentPosX <= 0) {
		goingRight = true;
	}
	else if (currentPosX >= 1920 - EnemyWidth) {
		goingRight = false;
	}
}

bool Enemy::BeginMoveDirectionDecider() {
	int _randomDecider = std::rand() % 2;

	if (_randomDecider == 1) {
		return true;
	}
	else {
		return false;
	}
}



bool Enemy::CollissionDetection(float _playerPosX, float _playerPosY) {

	float _inBetweenDistance = InBetweenDistance(_playerPosX, _playerPosY);
	if (_inBetweenDistance <= 0) {
		return true;
	}
	else {
		return false;
	}

}

bool Enemy::InCollissionArea(float PlayerPosY) {
	bool isAlive = true;

	if (currentPosY < PlayerPosY - 100.0f || currentPosY > PlayerPosY + 100.0f) {
		return false;
	}

	else {
		return true;
	}
}

bool Enemy::behondCollissionArea(float _playerPosY) {
	if (currentPosY > _playerPosY + 100.0f) {
		return true;
	}
	else {
		return false;
	}
}

float Enemy::InBetweenDistance(float PlayerPosX, float PlayerPosY) {
	float C1r = 50.0f;
	float C2r = 50.0f;


	float num = PlayerPosX - currentPosX;
	float num2 = PlayerPosY - currentPosY;


	float _sqrtDistance1 = (num * num + num2 * num2);
	float _distance = _sqrtDistance1 - ((C1r + C2r) * (C1r + C2r));
	float _inBetweenDistance = _distance - ((C1r + C2r) * (C1r + C2r));

	return _inBetweenDistance;
}

void Enemy::DrawEnemy() {
	enemyRect.setPosition(currentPosX, currentPosY);
	//enemyRect.setSize(sf::Vector2f(100, 100));
	////enemyRect.setScale(sf::Vector2f(10, 10));
	enemyRect.setFillColor(sf::Color(255, 255, 255));
	enemyCircle.setPosition(currentPosX, currentPosY);
	enemyCircle.setFillColor(sf::Color(255, 0, 255));

}

sf::RectangleShape Enemy::getEnemyRect() {
	return enemyRect;
}

sf::CircleShape Enemy::getEnemyCirlce() {
	return enemyCircle;

}


