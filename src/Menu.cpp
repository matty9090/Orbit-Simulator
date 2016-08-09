#include "stdafx.h"
#include "Menu.h"

int MenuItem::i = 0;

Menu::Menu() {
	
}

void Menu::init(sf::RenderWindow *app) {
	this->app = app;

	font.loadFromFile("res/fonts/arial.ttf");

	sf::Text t;
	t.setFont(font);
	t.setCharacterSize(40);
	t.setColor(sf::Color::White);

	items.push_back(MenuItem(t, "New Game", GAME));
	items.push_back(MenuItem(t, "Load Game", EXIT));
	items.push_back(MenuItem(t, "Tutorial", EXIT));
	items.push_back(MenuItem(t, "Exit", EXIT));
}

int Menu::run() {
	while (app->isOpen()) {
		sf::Event e;

		while (app->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app->close();
			else if (e.type == sf::Event::KeyReleased)
				return GAME;
			else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left) {
				for (auto &i : items) {
					if (i.btnState == i.HOVER)
						return i.state;
				}
			}
		}

		sf::Vector2i m = sf::Mouse::getPosition(*app);

		for (auto &i : items) {
			if (i.isHover(m))
				i.setState(i.HOVER);
			else
				i.setState(i.NORMAL);
		}

		app->clear(sf::Color(5, 5, 5));

		for (auto &i : items)
			app->draw(i.text);

		app->display();
	}

	return GAME;
}

Menu::~Menu() {

}
