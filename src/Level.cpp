#include "stdafx.h"
#include "Level.h"

Level::Level() {
	world = new b2World(b2Vec2(0, 0));

	for (int i = 0; i < 10; i++) {
		Planet *body = new Planet(world, 30);
		body->setPosition(sf::Vector2f(Tools::random(0, 800), Tools::random(0, 800)));
		objects.push_back(body);
	}
}

void Level::draw(sf::RenderWindow *app) {
	for (auto &obj : objects)
		obj->draw(app);
}

b2World *Level::getWorld() {
	return world;
}

Level::~Level() {

}