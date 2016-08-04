#include "stdafx.h"
#include "Level.h"

Level::Level() {
	world = new b2World(b2Vec2(0, 0));

	earth.setPosition(sf::Vector2f(0, 0));
}

void Level::draw(sf::RenderWindow *app) {
	earth.draw(app);
}

b2World *Level::getWorld() {
	return world;
}

Level::~Level() {

}
