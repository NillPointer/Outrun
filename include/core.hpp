#ifndef CORE_HPP
#define CORE_HPP

#include "SFML\Graphics.hpp"

constexpr int SCALE{ 1 };
constexpr int WINDOW_WIDTH{ SCALE * 800 },WINDOW_HEIGHT{ SCALE * 600 };
constexpr bool DEBUG{ true };

constexpr float DELTA_FOV{ 5.0f };
constexpr float DELTA_H{ 0.2f };

//void drawQuad(sf::RenderWindow &window, sf::Color c, int x1, int y1, int w1, int x2, int y2, int w2);

#endif

