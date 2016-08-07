#pragma once

#include "stdafx.h"

class Game {
public:
	Game(sf::RenderWindow *app);
	~Game();

	void run();

private:
	Level level;
	Player *player;

	sf::Texture bg_t;
	sf::Sprite bg;
	sf::RenderWindow *app;

	void update();
	void draw();
	void events(sf::Event &e);
	void loadTextures();
};

