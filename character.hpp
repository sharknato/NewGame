#pragma once

#include "entity.hpp"
#include <vector>

/*
 * Defines the playable characters in the game
 *
 */
class Player : public Entity {

public:


	int width = 1;
	int height = 1; 
	int shootSpeed = 50;
	int shootCount = 50;
		

		Player() = default;

		Player(int x, int y)
		{
			position = std::tuple<int, int>(x, y);
			//speed tracks the max counter number, the counter counts down
			speed = 50;
			speedCount = speed;

		}

	};



