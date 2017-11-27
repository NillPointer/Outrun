#include "Game.hpp"

#include <iostream>
#include <cmath>

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Outrun") {
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
			case sf::Keyboard::Left: {camera.x -= DELTA_H; break; }
			case sf::Keyboard::Right: {camera.x += DELTA_H; break; }
			case sf::Keyboard::Up: {h += DELTA_H; break; }
			case sf::Keyboard::Down: {h -= DELTA_H; break; }
			case sf::Keyboard::Comma: {fov -= DELTA_FOV; break; }
			case sf::Keyboard::Period: {fov += DELTA_FOV; break; }
			case sf::Keyboard::R: { h = 1.0f; camera.x = 0.0f; fov = 30.0f; break; }
			case sf::Keyboard::Num1: {mode = 1; break; }
			case sf::Keyboard::Num2: {mode = 2; break; }
			case sf::Keyboard::Num3: {mode = 3; break; }
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

	float d{ 2 / atan((fov*(3.14f / 180))) / 2 };

	camera.z = -d;
	camera.y = h;

	switch (mode) {
	case 1:
		drawSquare(window, {
			{0,0,0},
			{0,1,0},
			{1,1,0},
			{1,0,0}
		}, sf::Color::Red, d);
		break;
	case 2:
		drawSquare(window, {
			{ 0,0,0 },
			{ 0,0,1 },
			{ 1,0,1 },
			{ 1,0,0 }
		}, sf::Color::Green, d);
		break;
	case 3:
		drawSquare(window, {
			{ 0,0,0 },
			{ 0,1,0 },
			{ 0,1,1 },
			{ 0,0,1 }
		}, sf::Color::Blue, d);
		break;
	default:
		break;
	}

	window.display();
}