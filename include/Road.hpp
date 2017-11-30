#ifndef ROAD_HPP
#define ROAD_HPP

#include "Game.hpp"

#include "core.hpp"
#include <vector>

constexpr float SEGMENT_LENGHT{ 0.1f };
constexpr int NUM_SEGMENTS{ 100 };

class Road {
public:
	float width{ 400.0f };
	float kerbWidth{ width + (width*0.1f) };

	std::vector<float> center;

	void generate();
	void draw(Game &game);

private:

};

#endif // !ROAD_HPP

