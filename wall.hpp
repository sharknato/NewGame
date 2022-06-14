#pragma once

#include "entity.hpp"

class Wall : public Object {

public:
	

	Wall(float x, float y)
	{
		position = sf::Vector2f(x, y);
		

		
	}



};