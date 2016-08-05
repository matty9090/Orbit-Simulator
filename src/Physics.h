#pragma once

#include "stdafx.h"

namespace Physics {
	extern double G;

	sf::Vector2f force(sf::Vector2f p1, sf::Vector2f p2, double m1, double m2);
};

