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

		app->clear(sf::Color(5, 5, 5));

		level.draw(app);

		app->display();
	}
}

Game::~Game() {

}
