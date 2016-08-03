#include "stdafx.h"


int main() {
	sf::RenderWindow app(sf::VideoMode(640, 480), "Orbit Simulator");
	app.setVerticalSyncEnabled(true);

	while (app.isOpen()) {
		sf::Event e;

		while (app.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				app.close();
		}

		app.clear(sf::Color::Black);
		app.display();
	}

    return 0;
}

