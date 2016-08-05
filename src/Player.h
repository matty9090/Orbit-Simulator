#pragma once

#include "stdafx.h"

class Player {
public:
	Player(b2World *world, sf::Vector2f pos);
	~Player();

	void draw(sf::RenderWindow *app);
	void update();

private:
	sf::Sprite spr;
	sf::Texture tex;

	b2Body *body;
	b2BodyDef def;
	b2FixtureDef fix;
	b2CircleShape shape;
};

