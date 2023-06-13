#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "PhysicsObject.h"
#include <SFML/Graphics/Rect.hpp>


class Enemy
{

public:
	//Constructor
	Enemy(int enemyID);

	//copy Constructor
	Enemy(const Enemy& source);

	//Overloaded Assignment
	Enemy& operator=(const Enemy& source);

	//Destructor
	~Enemy();

	// checkt of de enemie al laag genoeg is voor Collission detection;
	bool CollissionDetection(float _playerPosX, float _playerPosY);

	bool InCollissionArea(float PlayerPosY);

	void DrawEnemy();

	void MoveEnemy();

	float NewPosCalulationX(float _currentpos);

	float NewPosCalulationY(float _currentpos);

	bool BeginMoveDirectionDecider();

	void PlayTimeMoveDirectionDecider();

	float InBetweenDistance(float PlayerPosX, float PlayerPosY);

	bool behondCollissionArea(float _playerPosY);

	sf::RectangleShape getEnemyRect();
	sf::CircleShape getEnemyCirlce();



private:
	int enemyID;
	bool goingRight;



	//position
	float beginPosX = std::rand()%1920;
	float beginPosY = +-300 + std::rand()% 200;

	float currentPosX = 960.0f;
	float currentPosY = 0;

	//transform
	float EnemyHeight = 100.0f;
	float EnemyWidth = 100.0f;
	float EnemyCollissionRadius = 50.0f;

	sf::RectangleShape enemyRect;
	sf::CircleShape enemyCircle;


	PhysicsObject physicsObject;




};

