#include "../headers/bat_class.h"
#include "../headers/ball_class.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include <sstream>

using namespace sf;


int main(){
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 3);
    int ballRadius = ball.getRadius();

    int score = 0;

    Text hud;
    Font font;
    font.loadFromFile("assets/p5font.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);

    while (window.isOpen()){
        /*
        Handle the player input
        */

        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)){
            // move left...
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)){
            // move right...
            bat.moveRight();
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            // quit...
            // Someone closed the window- bye
            window.close();
        }

        /*
        Update the frame
        */

        FloatRect ballPosition = ball.getPosition();
        if (ballPosition.top > windowHeight) {
            ball.hitBottom();

            score = 0;
        }

        if (ballPosition.left < 0 || ballPosition.left + 2*ballRadius > windowWidth) {
            ball.reboundSides();
        }

        // Handle ball hitting top
        if (ballPosition.top < 0){
            ball.reboundBatOrTop();
        }

        if (ballPosition.intersects(bat.getPosition())) {
            ball.reboundBatOrTop();
            score++;
        }

        /*
        Draw the frame
        */

        bat.update();
        ball.update();

        std::stringstream scoreString;
        scoreString << "Score: " << score;
        hud.setString(scoreString.str());

        // Clear everything from the last frame
        window.clear(Color(26, 128, 182, 255));

        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(hud);


        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop

    return 0;
    }
