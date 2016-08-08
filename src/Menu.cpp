#include "stdafx.h"
#include "Menu.h"


Menu::Menu() {

}

void Menu::init(sf::RenderWindow *app) {
	this->app = app;
}

int Menu::run() {
	while (app->isOpen()) {
		sf::Event e;

		while (app->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app->close();
			else if (e.type == sf::Event::KeyReleased)
				return GAME;
		}

		app->clear(sf::Color(5, 5, 5));

		app->display();
	}

	return GAME;
}

Menu::~Menu() {

}
