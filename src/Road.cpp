#include "Road.hpp"

void Road::generate() {
	center.clear();

	// straight line
	for (auto k = 0; k < NUM_SEGMENTS; ++k) center.push_back(0.0f);
}

void Road::draw(Game &game) {

	auto d{ 1.0f / tanf((game.fov*(3.14f / 180))) / 2 };
	auto colourPattern = true;

	for (auto k = NUM_SEGMENTS -1; k >= 0; k-=2) {

		sf::Vector3f point1 = { center[k], 0.0f, k*SEGMENT_LENGHT };
		sf::Vector3f point2 = { center[k - 1], 0.0f, k - 1 * SEGMENT_LENGHT };

		sf::Vector2f p1 = game.project(point1, game.camera, d);
		sf::Vector2f p2 = game.project(point2, game.camera, d);
		sf::Color pattern = colourPattern ? sf::Color::Red : sf::Color::White;
		colourPattern = !colourPattern;

		//Grass
		drawQuad(game.window, p1, 10000 * (d / (point1 - game.camera).z), p2, 10000 * (d / (point2 - game.camera).z), sf::Color::Green);

		//Kerb
		drawQuad(game.window, p1, kerbWidth * (d / (point1 - game.camera).z), p2, kerbWidth * (d / (point2 - game.camera).z), pattern);
		
		//Road
		drawQuad(game.window, p1, width * (d/(point1-game.camera).z), p2, width * (d / (point2 - game.camera).z), sf::Color(150,150,150,255));

	}
}
