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

double Body::getMass() {
	return mass;
}

sf::Vector2f Body::getPosition() {
	return pos;
}

sf::Vector2f Body::getVelocity() {
	return vel;
}

Planet::Planet(b2World *world, float radius, sf::Vector2f pos) {
	mass = 1e18;
	
	def.type = b2_dynamicBody;
	def.position.Set(pos.x, pos.y);
	body = world->CreateBody(&def);

	shape.m_radius = radius;
	fix.shape = &shape;
	fix.density = mass / (3.141 * radius * radius);
	fix.friction = 0.3f;
	body->CreateFixture(&fix);

	tex.loadFromFile("res/tex/earth.png");
	tex.setSmooth(true);
	spr.setRadius(radius);
	spr.setOrigin(radius, radius);
	spr.setTexture(&tex);
	spr.setPosition(pos);
}

void Planet::draw(sf::RenderWindow *app) {
	b2Vec2 pos = body->GetPosition();
	setPosition(sf::Vector2f(pos.x, pos.y));

	app->draw(spr);
}

void Planet::setPosition(sf::Vector2f pos) {
	this->pos = pos;
	spr.setPosition(pos);
}