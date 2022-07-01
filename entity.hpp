#pragma once
#include <SFML/System.hpp>
#include <tuple>
#include <iostream>

/* Serves as a base class for all the entities in the game, walls, characters, enemies etc.
*/
class Entity {

public:
	//define hitboxes and movement
	int width, height, speed;
	int speedCount;
	char direction;


	std::tuple<int, int> position;

	//any inheritor of object will need to be able to check for collisions.
	bool isColliding(Entity &blocker) {

		if (std::get<0>(blocker.position) == std::get<0>(this->position))
			if (std::get<1>(blocker.position) == std::get<1>(this->position))
				return true;

		return false;
	}

};