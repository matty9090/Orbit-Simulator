#include "stdafx.h"
#include "Game.h"


Game::Game(sf::RenderWindow *app) {
	this->app = app;

	loadTextures();

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
	sf::Vector2i pos = sf::Mouse::getPosition(*app);
	player->boostTowards(sf::Vector2f(pos.x, pos.y));

	level.update(player);
	level.getWorld()->Step(1 / 60.f, 8, 3);
}

void Game::draw() {
	app->draw(bg);

	level.draw(app);
	player->draw(app);
}

void Game::events(sf::Event &e) {
	switch (e.type) {
	case sf::Event::MouseMoved:
		
		break;
	}
}

void Game::loadTextures() {
	bg_t.loadFromFile("res/tex/bg.jpg");
	bg.setTexture(bg_t);
}

Game::~Game() {

}
