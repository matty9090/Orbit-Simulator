#include "stdafx.h"

int main() {
	sf::RenderWindow app(sf::VideoMode(1024, 768), "Orbit Simulator");
	app.setVerticalSyncEnabled(true);

	int current_state = MENU;

	vector<GameState*> states;

	states.push_back(new Menu());
	states.push_back(new Game());

	while (current_state != EXIT) {
		states[current_state]->init(&app);
		current_state = states[current_state]->run();
	}

    return 0;
}

