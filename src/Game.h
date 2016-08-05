#pragma once

#include "stdafx.h"

class Game {
public:
	Game(sf::RenderWindow *app);
	~Game();

	void run();

private:
	sf::RenderWindow *app;
	Level level;

	void update();
	void draw();
};

