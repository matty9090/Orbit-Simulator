#pragma once

#include "stdafx.h"

class Body {
public:
	Body();

	void setPosition(sf::Vector2f pos);
	void setVelocity(sf::Vector2f vel);

	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();

protected:
	virtual void draw(sf::RenderWindow *app) = 0;

	sf::Vector2f pos;

private:
	sf::Vector2f vel;
};

class Planet : public Body {
public:
	Planet();

	void draw(sf::RenderWindow *app);

	void setPosition(sf::Vector2f pos);

private:
	sf::Sprite spr;
	sf::Texture tex;
};