#include "stdafx.h"
#include "Player.h"


Player::Player(b2World *world, sf::Vector2f pos) {
	mass = 1000;

	def.type = b2_dynamicBody;
	def.position.Set(pos.x, pos.y);
	body = world->CreateBody(&def);

	shape.m_radius = 32;
	fix.shape = &shape;
	fix.density = 1;
	fix.friction = 0.3f;
	body->CreateFixture(&fix);

	tex.loadFromFile("res/tex/player.png");
	spr.setPosition(pos);
	spr.setOrigin(32, 32);
	spr.setTexture(tex);
}

b2Body *Player::getBody() {
	return body;
}

double Player::getMass() {
	return mass;
}

sf::Vector2f Player::getPosition() {
	return spr.getPosition();
}

void Player::draw(sf::RenderWindow *app) {
	b2Vec2 pos = body->GetPosition();
	spr.setPosition(pos.x, pos.y);

	app->draw(spr);
}

void Player::update() {

}

Player::~Player() {

}
