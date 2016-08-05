#include "stdafx.h"
#include "Physics.h"

namespace Physics {
	double G = 6.674e-11;

	sf::Vector2f force(sf::Vector2f p1, sf::Vector2f p2, double m1, double m2) {
		double dx = p2.x - p1.x;
		double dy = p2.y - p1.y;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		double force = (G * m1 * m2) / pow(distance, 2);

		return sf::Vector2f(force * dx / distance, force * dy / distance);
	}
}