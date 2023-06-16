// SFMLTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>
#include "PhysicsObject.h"
#include "KernModuleRaceGame.h"
#include "Vector2.h"
#include "Enemy.h"



//windowStats
int windowWidth = 1920;
int windowHeight = 1080;


sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Test", sf::Style::None);


sf::Keyboard::Key menuButton;

//looks
float playerHeight = 100.0f;
float playerWidth = 100.0f;

//PlayerStats
float PlayerCollissionRadius = playerWidth / 2;
sf::CircleShape PlayerCollission(PlayerCollissionRadius, 30.0f);
sf::RectangleShape Player(sf::Vector2f(playerWidth, playerHeight));
sf::RectangleShape ScoreHud(sf::Vector2f(200.0f, 150.0f));


bool playerIsAlive;


//Positie
float PlayerBeginPosX = 960;
float PlayerBeginPosY;

float PlayerCurrentPosX;
float PlayerCurrentPosY;

float PlayerNewPosX;
float PlayerNewPosY;

float speed = 0.1;

//endscreens
sf::Texture gameoverTexture;
sf::Sprite gameoverSprite;

// score
float hudPosX = windowWidth - 200.0f;
float hudPosY = 0.0f;
sf::Font font;
sf::Text showPoints;
std::string score;

int points = 0;

//physics
float playerDisplacement;
PhysicsObject PhysicsPlayer;

//input
bool GoingRight;

//collission
float PlayerCollissionPosX;
float PlayerCollissionPosY;

// Enemies
std::vector<Enemy*> lijstMetEnemies;
std::vector<int> lijstMetEnemiesGemist;
int EnemyAddCounter;
bool inCollissionArea;
bool Collission;
bool behondCollissionArea;

int CloseWindowTimer = 0;

void setup() {
	menuButton = sf::Keyboard::Key::Escape;
	PlayerCurrentPosX = PlayerBeginPosX;
	PlayerCurrentPosY = windowHeight - playerHeight;
	playerIsAlive = true;

	PlayerCollission.setFillColor(sf::Color(0, 255, 255));

	background.setFillColor(sf::Color(0, 0, 0));
	Player.setFillColor(sf::Color(255, 255, 255));
	ScoreHud.setFillColor(sf::Color(255, 0, 0));

	ScoreHud.setPosition(hudPosX, hudPosY);
	Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);

	
	//Score
	if (!font.loadFromFile("assets/Playkiddo.ttf"))
	{
		std::cout << "error scorefont!\n";
	}
	showPoints.setFont(font);
	showPoints.setString(std::to_string(points));
	showPoints.setCharacterSize(24);
	showPoints.setFillColor(sf::Color::Yellow);
	showPoints.setPosition(hudPosX + 50.0f, hudPosY + 50.0f);

	//end screens 
	if (!gameoverTexture.loadFromFile("assets/Gameover1.PNG"))
	{
		std::cout << "error gameoverscreen!\n";
	}
	gameoverSprite.setPosition(0.0f, 15.0f);
	gameoverSprite.setTexture(gameoverTexture);
	gameoverSprite.scale(sf::Vector2f(2.0f, 2.0f));

}

void EnemySetup() {

	// Monster Pointers toevoegen aan de de ArrayList lijstMetEnemys
	for (int i = 0; i <= 1; i = i + 1) {
		lijstMetEnemies.push_back(new Enemy(i));

		for (auto i = lijstMetEnemiesGemist.begin(); i != lijstMetEnemiesGemist.end(); ++i)
			std::cout << *i << " ";
	}
}

void EnemyUpdating() {
	EnemyAddCounter = EnemyAddCounter + 1;

	if (EnemyAddCounter >= 30) {
		lijstMetEnemies.push_back(new Enemy(1));
		EnemyAddCounter = 0;
	}
}


void playerMovement() {
	playerDisplacement = PhysicsPlayer.CalculatingDisplacement(1200.0f, 1);

	if (PlayerCurrentPosX > windowWidth - 100.0f) {
		PlayerCurrentPosX = windowWidth - 100.0f;
	}
	if (PlayerCurrentPosX < 0) {
		PlayerCurrentPosX = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && PlayerCurrentPosX > 0) {
		GoingRight = false;
		PlayerNewPosX = PlayerCurrentPosX - playerDisplacement;
		PlayerCurrentPosX = PlayerNewPosX;
		Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && PlayerCurrentPosX < windowWidth - 100.0f) {
		GoingRight = true;
		PlayerNewPosX = PlayerCurrentPosX + playerDisplacement;
		PlayerCurrentPosX = PlayerNewPosX;
		Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);

	}
	else {
		if (GoingRight == true && PlayerCurrentPosX > 0) {
			PlayerNewPosX = PlayerCurrentPosX + playerDisplacement;
			PlayerCurrentPosX = PlayerNewPosX;
			Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);
		}

		if (GoingRight == false && PlayerCurrentPosX < windowWidth - 100.0f) {
			PlayerNewPosX = PlayerCurrentPosX - playerDisplacement;
			PlayerCurrentPosX = PlayerNewPosX;
			Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);
		}

	}
}

void CollissionCheck() {
	PlayerCollissionPosX = PlayerCurrentPosX;
	PlayerCollissionPosY = PlayerCurrentPosY;
	PlayerCollission.setPosition(PlayerCollissionPosX, PlayerCollissionPosY);
}

void EnemyManagment() {
	for (auto it = lijstMetEnemies.begin(); it != lijstMetEnemies.end(); it++) {
		//enemy;
		auto enemy = *it;
		// hier wordt de enemy zijn behavoir opgeroepen;
		enemy->MoveEnemy();

		//hier wordt om het lichaam van de enemy gevraagd om hem te tekenen op de window
		window.draw(enemy->getEnemyRect());
		window.draw(enemy->getEnemyCirlce());

		//collission detection
		inCollissionArea = enemy->InCollissionArea(PlayerCollissionPosY);
		behondCollissionArea = enemy->behondCollissionArea(PlayerCollissionPosY);

		if (inCollissionArea == true) {
			Collission = enemy->CollissionDetection(PlayerCollissionPosX, PlayerCollissionPosY);
			if (Collission == true) {
				// game over screen
				playerIsAlive = false;
				std::cout << "Game over" << std::endl;
			}
		}

		if (behondCollissionArea == true) {
			// + 1 score en delete enemy
			auto tempEnemy = *it;
			it = lijstMetEnemies.erase(std::find(lijstMetEnemies.begin(), lijstMetEnemies.end(), enemy));
			delete tempEnemy;
			points++;
		}
	}
}

void DrawElements() {
	if (playerIsAlive == true) {
		showPoints.setString(std::to_string(points));
		window.draw(ScoreHud);
		window.draw(showPoints);
		window.draw(Player);
		window.draw(PlayerCollission);
	}
	else {
		window.draw(background);
		window.draw(gameoverSprite);
	}

	if (playerIsAlive == false) {
		CloseWindowTimer++;

		if (CloseWindowTimer == 150) {
			window.close();
		}
	}
}

int main()
{
	sf::Event e;
	window.setFramerateLimit(60);
	window.draw(background);

	setup();
	EnemySetup();

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(menuButton)) {
			window.close();
		}

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		EnemyUpdating();
		playerMovement();
		CollissionCheck();
		EnemyManagment();
		DrawElements();

		window.display();
		window.clear();
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
