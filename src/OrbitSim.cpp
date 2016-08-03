#include "stdafx.h"

int main() {
	sf::RenderWindow app(sf::VideoMode(1024, 768), "Orbit Simulator");
	app.setVerticalSyncEnabled(true);

	Game sim(&app);
	sim.run();

    return 0;
}

