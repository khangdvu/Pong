#include "../headers/bat_class.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>

using namespace sf;


int main() 
{
	int windowWidth = 1024;
	int windowHeight = 768;

	Bat bat(windowWidth / 2, windowHeight - 20);

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

    while (window.isOpen())
    {
        /*
            Handle the player input
            *********************************************************************
            *********************************************************************
            *********************************************************************
        */

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            // move left...
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            // move right...
            bat.moveRight();
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit...
            // Someone closed the window- bye
            window.close();
        }
        /*
   Draw the frame
   *********************************************************************
   *********************************************************************
   *********************************************************************
*/
        bat.update();
// Clear everything from the last frame
        window.clear(Color(26, 128, 182, 255));

        window.draw(bat.getShape());



        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop

    return 0;
    }
