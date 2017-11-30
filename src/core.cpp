#include "core.hpp"

void drawQuad(sf::RenderWindow &window, sf::Vector2f p1, float w1, sf::Vector2f p2, float w2) {
	sf::ConvexShape quad;
	quad.setPointCount(4);
	quad.setPoint(0, p1 - sf::Vector2f(w1, 0));
	quad.setPoint(1, p1 + sf::Vector2f(w1, 0));
	quad.setPoint(2, p2 + sf::Vector2f(w2, 0));
	quad.setPoint(3, p2 - sf::Vector2f(w2, 0));

	window.draw(quad);
}