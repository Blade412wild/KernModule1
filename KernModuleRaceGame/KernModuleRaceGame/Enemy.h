#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

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
	bool BenIkLaagGenoeg(float _playerPosY);

	bool IsThereCollission(float PlayerPosX, float PlayerPosY);
	void DrawEnemy(sf::RenderWindow* window);
private:
	int enemyID;

	//position
	float beginLocX;
	float BeginLocY;

	float currentPosX = 960.0f;
	float currentPosY = 1080;

	//transform
	float EnemyHeight = 100.0f;
	float EnemyWidth = 100.0f;
	float EnemyCollissionRadius = 50.0f;





};

