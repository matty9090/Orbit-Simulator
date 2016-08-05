#pragma once

#include "stdafx.h"

using namespace std;

class Level {
public:
	Level();
	~Level();

	void update(Player *player);
	void draw(sf::RenderWindow *app);
	void updatePlanet(sf::Vector2f pos);

	b2World *getWorld();

private:
	b2World *world;

	vector<Body*> objects;
};

