#pragma once
#include <SFML/Graphics.hpp>

using namespace sf; 

class Ball {
private:
	Vector2f position;
	CircleShape ballShape;

	float radius = 10;
	float xVelocity = .1f;
	float yVelocity = .1f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	CircleShape getShape();

	float getXVelocity();

	float getRadius();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update();
};