#ifndef CORE_HPP
#define CORE_HPP

#include "SFML\Graphics.hpp"

constexpr int SCALE{ 1 };
constexpr int WINDOW_WIDTH{ SCALE * 800 },WINDOW_HEIGHT{ SCALE * 600 };
constexpr bool DEBUG{ true };

constexpr float DELTA_FOV{ 5.0f };
constexpr float DELTA_CHANGE{ 0.2f };

void drawQuad(sf::RenderWindow &window, sf::Vector2f p1, float w1, sf::Vector2f p2, float w2, sf::Color colour);

#endif

