#pragma once

#include "stdafx.h"

class Menu : public GameState {
public:
	Menu();
	~Menu();

	void init(sf::RenderWindow *app);
	int run();

private:
	sf::RenderWindow *app;
};

