#pragma once

#include "stdafx.h"

class Player {
public:
	Player(b2World *world, sf::Vector2f pos);
	~Player();

	void draw(sf::RenderWindow *app);
	void update();
	void setPosition(sf::Vector2f pos);
	void boostTowards(sf::Vector2f pos);

	double getMass();
	b2Body *getBody();

	sf::Vector2f getPosition();

private:
	sf::Sprite spr;
	sf::Texture tex;

	double mass;

	b2Body *body;
	b2BodyDef def;
	b2FixtureDef fix;
	b2CircleShape shape;
};

