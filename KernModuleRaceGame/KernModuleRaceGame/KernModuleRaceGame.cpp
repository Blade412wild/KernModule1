// SFMLTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "PhysicsObject.h"
#include <string>



    //windowStats
int WidowWidth = 1920;
int WindowHeight = 1080;

sf::RectangleShape Background(sf::Vector2f(WidowWidth, WindowHeight));

sf::Keyboard::Key MenuButton;

//PlayerStats
sf::RectangleShape Player(sf::Vector2f(100.0f, 100.0f));
sf::RectangleShape ScoreHud(sf::Vector2f(200.0f, 150.0f));

//Positie
float PlayerBeginPosX = 960;
float PlayerBeginPosY;

float PlayerCurrentPosX;
float PlayerCurrentPosY;

float PlayerNewPosX;
float PlayerNewPosY;

float speed = 0.1;

//looks
float Playerheight = 100.0f;
float PlayerWidth = 100.0f;

// score
float hudPosX = WidowWidth - 200.0f;
float hudPosY = 0.0f;
sf::Font font;
sf::Text text;
std::string score;

int test = 1;

// Physics
float MotorForce;
float playerVelocity;
float playerDisplacement;
PhysicsObject PhysicsPlayer;

//input
bool GoingRight;




void setup() {
    MenuButton = sf::Keyboard::Key::Escape;
    PlayerCurrentPosX = PlayerBeginPosX;
    PlayerCurrentPosY = WindowHeight - Playerheight;
    Background.setFillColor(sf::Color(0, 0, 0));
    Player.setFillColor(sf::Color(255, 255, 255));
    ScoreHud.setFillColor(sf::Color(255, 0, 0));

    ScoreHud.setPosition(hudPosX, hudPosY);
    Player.setPosition(PlayerCurrentPosX, PlayerCurrentPosY);

    // Physics
    //playerVelocity = PhysicsPlayer.CalculateVelocity(74.0f);
    playerDisplacement = PhysicsPlayer.CalculatingDisplacement(1200.0f);
    PhysicsPlayer.ShowInformation();


    //Score
    if (!font.loadFromFile("C:/Users/Nathan/Documents/02_HKU/jaar 1/blok 4/kernmodule/SFMLTest/Assets/Playkiddo.ttf"))
    {
        std::cout << "error!\n";
    }

    score = std::to_string(test);
    text.setFont(font);
    text.setString(std::to_string(test));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(hudPosX + 50.0f, hudPosY + 50.0f);

}

void playerMovement() {
    playerDisplacement = PhysicsPlayer.CalculatingDisplacement(1200.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && PlayerCurrentPosX > 0) {
        GoingRight = false;
        PlayerNewPosX = PlayerCurrentPosX - playerDisplacement;
        PlayerCurrentPosX = PlayerNewPosX;
        Player.setPosition(PlayerNewPosX, PlayerCurrentPosY);
   
        MotorForce = PhysicsPlayer.CalculateFmotor();
        std::cout << MotorForce << std::endl;


    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && PlayerCurrentPosX < WidowWidth - 100.0f) {
        GoingRight = true;
        PlayerNewPosX = PlayerCurrentPosX + playerDisplacement;
        PlayerCurrentPosX = PlayerNewPosX;
        Player.setPosition(PlayerNewPosX, PlayerCurrentPosY);

        MotorForce = PhysicsPlayer.CalculateFmotor();
        std::cout << MotorForce << std::endl;
    }
    else {
        if (GoingRight == true) {
            PlayerNewPosX = PlayerCurrentPosX + playerDisplacement;
            PlayerCurrentPosX = PlayerNewPosX;
            Player.setPosition(PlayerNewPosX, PlayerCurrentPosY);
        }
        else {
            PlayerNewPosX = PlayerCurrentPosX - playerDisplacement;
            PlayerCurrentPosX = PlayerNewPosX;
            Player.setPosition(PlayerNewPosX, PlayerCurrentPosY);
        }
        MotorForce = PhysicsPlayer.CalculateFmotor();
        std::cout << MotorForce << std::endl;
    }




}
int main()
{

    sf::RenderWindow window(sf::VideoMode(WidowWidth, WindowHeight), "Test", sf::Style::None);
    sf::Event e;

    window.setFramerateLimit(60);

    setup();

    while (window.isOpen())
    {

        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Texture texure;


        playerMovement();

        if (sf::Keyboard::isKeyPressed(MenuButton)) {
            window.close();
        }


        test = test + 1;
        text.setString(std::to_string(test));

        window.clear();
        window.draw(Background);
        window.draw(ScoreHud);
        window.draw(text);
        window.draw(Player);
        window.display();
    }
    std::cout << "Hello World!\n";
    std::cout << test;
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
