#include "../headers/ball_class.h"

using namespace sf;

Ball::Ball(float startX, float startY) {
	position.x = startX;
	position.y = startY;

    ballShape.setOutlineThickness(0.5f);
	ballShape.setRadius(radius);
    ballShape.setOutlineColor(Color::White);
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition(){
    return ballShape.getGlobalBounds();
}

CircleShape Ball::getShape(){
    return ballShape;
}

float Ball::getXVelocity(){
    return xVelocity;
}

float Ball::getRadius() {
    return radius;
}

void Ball::reboundSides(){
    xVelocity = -xVelocity;

}

void Ball::reboundBatOrTop(){
    position.y -= (yVelocity);
    yVelocity = -yVelocity;

}

void Ball::hitBottom(){
    position.y = 1;
    position.x = 500;
}

void Ball::update(){
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // Move the ball
    ballShape.setPosition(position);
}