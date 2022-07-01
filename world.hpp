#pragma once
#include <vector>
#include "wall.hpp"
#include "character.hpp"


class World {
public:
	std::vector<Wall> walls;

	std::vector<std::vector<int>> places;

	int rows;

	int columns;

	Player player;

	World()
		: rows(30),
		columns(30),
		player(10, 10)
	{
		/*
		//create grid
		for (int i = 0; i < rows; i++) {
			std::vector<int> row(columns, 0);
			places.push_back(row);
		}
		*/		
		//set player starting position
		//std::get<0>(player.position) = 10;
		//std::get<1>(player.position) = 10;
		
		Wall testWall(20, 20);

		walls.push_back(testWall);

	}

	
};