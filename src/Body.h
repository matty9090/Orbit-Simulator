#pragma once

#include "stdafx.h"

class Body {
public:
	Body();

	void setPosition(sf::Vector2f pos);
	void setVelocity(sf::Vector2f vel);

	double getMass();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();

	virtual void draw(sf::RenderWindow *app) = 0;

	b2Body *body;

protected:
	double mass;
	sf::Vector2f pos;	

private:
	sf::Vector2f vel;
};

class Planet : public Body {
public:
	Planet(b2World *world, float radius, sf::Vector2f pos);

	void draw(sf::RenderWindow *app);
	void setPosition(sf::Vector2f pos);

private:
	sf::CircleShape spr;
	sf::Texture tex;

	b2CircleShape shape;
	b2BodyDef def;
	b2FixtureDef fix;
};