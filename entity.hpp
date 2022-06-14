#pragma once
#include <SFML/System.hpp>

/* Serves as a base class for all te entities in the game, walls, characters, enemies etc.
*/
class Object {

public:
	//define hitboxes
	float width;
	float height;
	//some objects can move
	float speed;

	sf::Vector2f position;

	//any inheritor of object will need to be able to check for collisions.
	bool isColliding(Object blocker) {
		if (position.x < (blocker.position.x + blocker.width) && position.x > blocker.position.x)
			if (position.y < (blocker.position.y + blocker.height) && position.y > blocker.position.y)
				return true;

			else if (blocker.position.x < (position.x + blocker.width) && blocker.position.x > position.x)
				if (blocker.position.y < (position.y + blocker.height) && blocker.position.y > position.y)
					return true;
			else
				return false;
	}

};