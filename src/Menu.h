#pragma once

#include "stdafx.h"

struct MenuItem {
	int state, btnState;
	sf::Text text;

	static int i;

	MenuItem(sf::Text t, string str, int s) {
		i++;
		state = s;
		text = t;
		text.setString(str);
		btnState = NORMAL;

		sf::FloatRect bounds = text.getLocalBounds();
		text.setPosition(1024 / 2 - bounds.width / 2, i * 50 + 260);
	}

	bool isHover(sf::Vector2i m) {
		return text.getGlobalBounds().contains(m.x, m.y);
	}

	void setState(int s) {
		btnState = s;

		switch (btnState) {
		case NORMAL: text.setColor(sf::Color::White);  break;
		case HOVER:	text.setColor(sf::Color(150, 150, 150)); break;
		}
	}

	enum BtnState { NORMAL, HOVER, CLICKED };
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

