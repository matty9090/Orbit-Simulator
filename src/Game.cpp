#include "stdafx.h"
#include "Game.h"


Game::Game(sf::RenderWindow *app) {
	this->app = app;

	player = new Player(level.getWorld(), sf::Vector2f(100, 200));
}

void Game::run() {
	while (app->isOpen()) {
		sf::Event e;

		while (app->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app->close();
			else
				events(e);
		}

		update();

		app->clear(sf::Color(5, 5, 5));

		draw();

		app->display();
	}
}

void Game::update() {
	level.update(player);
	level.getWorld()->Step(1 / 30.f, 8, 3);
}

void Game::draw() {
	level.draw(app);
	player->draw(app);
}

void Game::events(sf::Event &e) {
	switch (e.type) {
	case sf::Event::MouseMoved:
		sf::Vector2i pos = sf::Mouse::getPosition(*app);

		player->setPosition(sf::Vector2f(pos.x, pos.y));

		break;
	}
}

Game::~Game() {

}
