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
int WidowWidth = 1920;
int WindowHeight = 1080;


sf::RectangleShape Background(sf::Vector2f(WidowWidth, WindowHeight));
sf::RenderWindow window(sf::VideoMode(WidowWidth, WindowHeight), "Test", sf::Style::None);


sf::Keyboard::Key MenuButton;

//looks
float PlayerHeight = 100.0f;
float PlayerWidth = 100.0f;

//PlayerStats
float PlayerCollissionRadius = PlayerWidth / 2;
sf::CircleShape PlayerCollission(PlayerCollissionRadius, 30.0f);
sf::RectangleShape Player(sf::Vector2f(PlayerWidth, PlayerHeight));
sf::RectangleShape ScoreHud(sf::Vector2f(200.0f, 150.0f));

sf::CircleShape enemyCollission(PlayerCollissionRadius, 30.0f);
sf::RectangleShape enemyTest(sf::Vector2f(100.0f, 100.0f));


//Positie
float PlayerBeginPosX = 960;
float PlayerBeginPosY;

float PlayerCurrentPosX;
float PlayerCurrentPosY;

float PlayerNewPosX;
float PlayerNewPosY;

float speed = 0.1;


// score
float hudPosX = WidowWidth - 200.0f;
float hudPosY = 0.0f;
sf::Font font;
sf::Text showPoints;
std::string score;

int points = 0;

// Physics
float MotorForce;
float playerVelocity;
float playerDisplacement;
PhysicsObject PhysicsPlayer;

//input
bool GoingRight;

//collission
float PlayerCollissionPosX;
float PlayerCollissionPosY;

// Vector2
//Vector2 vector2;
Vector2* PuntA = new Vector2(2.0f, 5.0f);;
Vector2* PuntB = new Vector2(4.0f, 3.0f);;

// Enemies
std::vector<Enemy*> lijstMetEnemies;
std::vector<int> lijstMetEnemiesGemist;
int EnemyAddCounter;
bool inCollissionArea;
bool Collission;
bool behondCollissionArea;


void setup() {
	MenuButton = sf::Keyboard::Key::Escape;
	PlayerCurrentPosX = PlayerBeginPosX;
	PlayerCurrentPosY = WindowHeight - PlayerHeight;

	PlayerCollission.setFillColor(sf::Color(0, 255, 255));

	Background.setFillColor(sf::Color(0, 0, 0));
	Player.setFillColor(sf::Color(255, 255, 255));
	ScoreHud.setFillColor(sf::Color(255, 0, 0));

	ScoreHud.setPosition(hudPosX, hudPosY);
	Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);

	enemyCollission.setPosition(0.0f, 0.0f);
	enemyCollission.setFillColor(sf::Color(255, 0, 255));
	//enemyTest.setPosition(PlayerBeginPosX, WindowHeight - PlayerHeight);
	//enemyTest.setFillColor(sf::Color(255, 255, 255));


	//Score
	if (!font.loadFromFile("C:/Users/Nathan/Documents/02_HKU/jaar 1/blok 4/kernmodule/SFMLTest/Assets/Playkiddo.ttf"))
	{
		std::cout << "error!\n";
	}

	//score = std::to_string(test);

	showPoints.setFont(font);
	showPoints.setString(std::to_string(points));
	showPoints.setCharacterSize(24);
	showPoints.setFillColor(sf::Color::Yellow);
	showPoints.setPosition(hudPosX + 50.0f, hudPosY + 50.0f);
}

void EnemySetup() {

	//Enemies
	//lijstMetEnemies = new std::vector<Enemy>();
	//lijstMetEnemiesGemist = new std::vector<int>();

	// Monster Pointers toevoegen aan de de ArrayList lijstMetEnemys
	for (int i = 0; i <= 2; i = i + 1) {
		lijstMetEnemies.push_back(new Enemy(i));

		for (auto i = lijstMetEnemiesGemist.begin(); i != lijstMetEnemiesGemist.end(); ++i)
			std::cout << *i << " ";
	}

}

void EnemyUpdating() {
	EnemyAddCounter = EnemyAddCounter + 1;

	if (EnemyAddCounter >= 40) {
		lijstMetEnemies.push_back(new Enemy(1));
		EnemyAddCounter = 0;
	}
}

void Vector2Testing() {
	//float _distance = vector2.Distance(PuntA, PuntB);
	//float _distance = Vector2.Distance(PuntA, PuntB);
	//float _distance = Vector2::Distance(PuntA, PuntB);


	//float _test = vector2.Test(3.0f, 5.0f);

}

void playerMovement() {
	playerDisplacement = PhysicsPlayer.CalculatingDisplacement(1200.0f, 1);

	if (PlayerCurrentPosX > WidowWidth - 100.0f) {
		PlayerCurrentPosX = WidowWidth - 100.0f;
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && PlayerCurrentPosX < WidowWidth - 100.0f) {
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

		if (GoingRight == false && PlayerCurrentPosX < WidowWidth - 100.0f) {
			PlayerNewPosX = PlayerCurrentPosX - playerDisplacement;
			PlayerCurrentPosX = PlayerNewPosX;
			Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);
		}

	}

	//std::cout << "PlayerCurrentPosX : " << PlayerCurrentPosX << std::endl;
}

void CollissionCheck() {
	PlayerCollissionPosX = PlayerCurrentPosX;
	PlayerCollissionPosY = PlayerCurrentPosY;
	PlayerCollission.setPosition(PlayerCollissionPosX, PlayerCollissionPosY);

	//std::cout << "PlayerCollissionPosX : " << PlayerCollissionPosX << std::endl;

}



void EnemyManagment() {
	for (int i = 0; i < lijstMetEnemies.size(); i = i + 1) {
		//lijstMetEnemies[i];

		// hier wordt de enemy zijn behavoir opgeroepen;
		lijstMetEnemies[i]->MoveEnemy();

		//hier wordt om het lichaam van de enemy gevraagd om hem te tekenen op de window
		window.draw(lijstMetEnemies[i]->getEnemyRect());
		window.draw(lijstMetEnemies[i]->getEnemyCirlce());

		//collission detection
		inCollissionArea = lijstMetEnemies[i]->InCollissionArea(PlayerCollissionPosY);
		behondCollissionArea = lijstMetEnemies[i]->behondCollissionArea(PlayerCollissionPosY);

		if (inCollissionArea == true) {
			Collission = lijstMetEnemies[i]->CollissionDetection(PlayerCollissionPosX, PlayerCollissionPosY);
			if (Collission == true) {
				// game over screen
				std::cout << "Game over" << std::endl;
			}
		}

		if (behondCollissionArea == true) {
			// + 1 score en delete enemy
			points++;
			//delete lijstMetEnemies[i];
		}


		//if (laagGenoeg) {
		//	lijstMetEnemies[i]->IsAlive(PlayerCollissionPosX, PlayerCollissionPosY);
		//}

	}
}

int main()
{

	//sf::RenderWindow window(sf::VideoMode(WidowWidth, WindowHeight), "Test", sf::Style::None);
	sf::Event e;
	window.setFramerateLimit(60);
		window.draw(Background);

	setup();
	EnemySetup();
	//Vector2Testing();

	while (window.isOpen())
	{

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

		if (sf::Keyboard::isKeyPressed(MenuButton)) {
			window.close();
		}




		//test = test + 1;
		showPoints.setString(std::to_string(points));
		window.draw(ScoreHud);
		window.draw(showPoints);
		//window.draw(enemyTest);
		window.draw(enemyCollission);

		window.draw(Player);
		window.draw(PlayerCollission);
		window.display();
		window.clear();
	}
	//std::cout << test;
}

// wat heb ik nodig?
// calculations
//    friction calculation
//    netto forces calculations
//    acceleratie
//    tijd naar seconden overbrengen







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
