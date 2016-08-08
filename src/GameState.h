#pragma once

#include <SFML/Graphics.hpp>

enum States {
	MENU, GAME, EXIT
};

class GameState {
public:
	GameState();
	~GameState();

	virtual void init(sf::RenderWindow *app) = 0;
	virtual int run() = 0;
};

