#include "stdafx.h"
#include "Body.h"


Body::Body() {

}

void Body::setPosition(sf::Vector2f pos) {
	this->pos = pos;
}

void Body::setVelocity(sf::Vector2f vel) {
	this->vel = vel;
}

sf::Vector2f Body::getPosition() {
	return pos;
}

sf::Vector2f Body::getVelocity() {
	return vel;
}

Planet::Planet() : Body() {
	tex.loadFromFile("res/tex/earth.png");
	tex.setSmooth(true);
	spr.setTexture(tex);
}

void Planet::draw(sf::RenderWindow *app) {
	app->draw(spr);
}

void Planet::setPosition(sf::Vector2f pos) {
	this->pos = pos;
	spr.setPosition(pos);
}