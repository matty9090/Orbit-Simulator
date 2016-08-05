#pragma once

#include "stdafx.h"

class Game {
public:
	Game(sf::RenderWindow *app);
	~Game();

	void run();
	void events(sf::Event &e);

private:
	sf::RenderWindow *app;
	Level level;
	Player *player;

	void update();
	void draw();
};

