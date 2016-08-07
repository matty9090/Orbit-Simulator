#include "stdafx.h"
#include "Player.h"


Player::Player(b2World *world, sf::Vector2f pos) {
	mass = 1000;

	def.type = b2_dynamicBody;
	def.position.Set(pos.x * SCALE, pos.y * SCALE);
	body = world->CreateBody(&def);

	shape.m_radius = 20 * SCALE;
	fix.shape = &shape;
	fix.density = 1;
	fix.friction = 0.3f;
	body->CreateFixture(&fix);

	tex.loadFromFile("res/tex/player.png");
	spr.setPosition(pos);
	spr.setOrigin(20, 20);
	spr.setTexture(tex);
}

b2Body *Player::getBody() {
	return body;
}

double Player::getMass() {
	return mass;
}

void Player::setPosition(sf::Vector2f pos) {
	body->SetTransform(b2Vec2(pos.x * SCALE, pos.y * SCALE), body->GetAngle());
}

void Player::boostTowards(sf::Vector2f p) {
	double x, y, force;

	sf::Vector2f t(body->GetPosition().x / SCALE, body->GetPosition().y / SCALE);
	sf::Vector2f d = p - t;

	force = 20;

	x = d.x;
	y = d.y;

	body->ApplyForceToCenter(b2Vec2(force * x, force * y), false);
}

sf::Vector2f Player::getPosition() {
	return spr.getPosition();
}

void Player::draw(sf::RenderWindow *app) {
	b2Vec2 pos = body->GetPosition();
	spr.setPosition(pos.x / SCALE, pos.y / SCALE);

	app->draw(spr);
}

void Player::update() {

}

Player::~Player() {

}
