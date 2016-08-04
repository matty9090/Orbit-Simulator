#include "stdafx.h"
#include "Game.h"


Game::Game(sf::RenderWindow *app) {
	this->app = app;

	earth.setPosition(sf::Vector2f(0, 0));
}

void Game::run() {
	while (app->isOpen()) {
		sf::Event e;

		while (app->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app->close();
		}

		app->clear(sf::Color(5, 5, 5));

		earth.draw(app);

		app->display();
	}
}

Game::~Game() {

}
