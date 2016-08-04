#pragma once

#include "stdafx.h"

class Level {
public:
	Level();
	~Level();

	void draw(sf::RenderWindow *app);

	b2World *getWorld();

private:
	b2World *world;

	Planet earth;
};

