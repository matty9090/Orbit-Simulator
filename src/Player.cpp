#include "stdafx.h"
#include "Player.h"


Player::Player(b2World *world, sf::Vector2f pos) {
	def.type = b2_dynamicBody;
	def.position.Set(pos.x, pos.y);
	body = world->CreateBody(&def);

	shape.m_radius = 20;
	fix.shape = &shape;
	fix.density = 1;
	fix.friction = 0.3f;
	body->CreateFixture(&fix);

	tex.loadFromFile("res/tex/player.png");
	spr.setPosition(pos);
	spr.setOrigin(20, 20);
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
