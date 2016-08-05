#include "stdafx.h"
#include "Game.h"


Game::Game(sf::RenderWindow *app) {
	this->app = app;
}

void Game::run() {
	while (app->isOpen()) {
		sf::Event e;

		while (app->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app->close();
		}

		update();

		app->clear(sf::Color(5, 5, 5));

		draw();

		app->display();
	}
}

void Game::update() {
	level.getWorld()->Step(1 / 60.f, 8, 3);
}

void Game::draw() {
	level.draw(app);
}

Game::~Game() {

}
