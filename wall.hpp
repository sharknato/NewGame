#pragma once

#include "entity.hpp"

class Wall : public Entity {

public:
	


	Wall(float x, float y)
	{
		 position = std::tuple<int, int>(x, y);
		 height = 1;
		 width = 1;
		
	}



};