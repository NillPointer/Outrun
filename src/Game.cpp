#include "Game.hpp"
#include "Road.hpp"

#include <iostream>
#include <cmath>

Road road;

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Outrun") {
	road.generate();
}

void Game::run() {
	sf::Clock clock;

	while (window.isOpen()) {
		if (!processEvents()) break;
		update(clock.restart());
		render();
	}
}

bool Game::processEvents() {

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
			case sf::Keyboard::Left: {camera.x -= DELTA_CHANGE; break; }
			case sf::Keyboard::Right: {camera.x += DELTA_CHANGE; break; }
			case sf::Keyboard::Up: {camera.y += DELTA_CHANGE; break; }
			case sf::Keyboard::Down: {camera.y -= DELTA_CHANGE; break; }
			case sf::Keyboard::Comma: {fov -= DELTA_FOV; break; }
			case sf::Keyboard::Period: {fov += DELTA_FOV; break; }
			case sf::Keyboard::R: { camera.y = 1.0f; camera.x = 0.0f; fov = 30.0f; break; }
			default: break;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;

	return true;
}

void Game::update(sf::Time deltaTime) {

}

sf::Vector2f Game::project(const sf::Vector3f &world, sf::Vector3f &camera, float d) {
	sf::Vector3f relative = world - camera;
	float scale = { d / relative.z };
	sf::Vector2f screenCoords = { scale*relative.x, scale*relative.y };
	return{ (screenCoords.x * WINDOW_WIDTH / 2) + WINDOW_WIDTH / 2, (screenCoords.y * WINDOW_HEIGHT / 2) + WINDOW_HEIGHT / 2 };
}

void Game::drawSquare(sf::RenderWindow &window, const std::vector<sf::Vector3f> &coords, const sf::Color &c, const float d) {
	sf::ConvexShape shape(4);
	shape.setFillColor(c);
	for(int i = 0; i < 4; ++i) shape.setPoint(i, project(coords[i], camera, d));

	window.draw(shape);
}


void Game::render() {
	window.clear(sf::Color::Black);

	float d{ 1.0f / tanf((fov*(3.14f / 180) )) / 2 };
	camera.z = -d;

	std::cout << "Camera Height  : " << camera.y << std::endl;

	road.draw(*this);

	window.display();
}