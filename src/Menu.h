#pragma once

#include "stdafx.h"

struct MenuItem {
	int state;
	sf::Text text;

	static int i;

	MenuItem(sf::Text t, string str, int s) {
		i++;
		state = s;
		text = t;
		text.setString(str);

		sf::FloatRect bounds = text.getLocalBounds();

		text.setPosition(1024 / 2 - bounds.width / 2, i * 50 + 260);
	}
};

class Menu : public GameState {
public:
	Menu();
	~Menu();

	void init(sf::RenderWindow *app);
	int run();

private:
	sf::Font font;
	sf::RenderWindow *app;
	vector<MenuItem> items;
};

