#include "stdafx.h"
#include "Level.h"

Level::Level() {
	world = new b2World(b2Vec2(0, 0));

	//for (int i = 0; i < 10; i++) {
		//sf::Vector2f pos(Tools::random(0, 400), Tools::random(0, 400));
		sf::Vector2f pos(500, 400);
		Planet *body = new Planet(world, 32, pos);
		objects.push_back(body);
	//}
}

void Level::update(Player *player) {
	sf::Vector2f force;

	for (auto &obj : objects)
		force += Physics::force(obj->getPosition(), player->getPosition(), obj->getMass(), player->getMass());

	//std::cout << force.x << "\t" << force.y << std::endl;

	player->getBody()->ApplyForceToCenter(b2Vec2(-force.x, -force.y), true);
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
