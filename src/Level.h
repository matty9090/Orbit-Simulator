#pragma once

#include "stdafx.h"

using namespace std;

class Level {
public:
	Level();
	~Level();

	void draw(sf::RenderWindow *app);

	b2World *getWorld();

private:
	b2World *world;

	vector<Body*> objects;
};

