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

Planet::Planet(b2World *world, float radius) {
	def.type = b2_dynamicBody;
	def.position = b2Vec2(0, 0);
	body = world->CreateBody(&def);

	shape.m_radius = radius;
	fix.shape = &shape;
	body->CreateFixture(&fix);

	tex.loadFromFile("res/tex/earth.png");
	tex.setSmooth(true);
	spr.setRadius(radius);
	spr.setOrigin(radius, radius);
	spr.setTexture(&tex);
}

void Planet::draw(sf::RenderWindow *app) {
	app->draw(spr);
}

void Planet::setPosition(sf::Vector2f pos) {
	this->pos = pos;
	spr.setPosition(pos);
	def.position = b2Vec2(pos.x, pos.y);
}