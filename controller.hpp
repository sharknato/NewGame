#pragma once
#include <Windows.h>
#include <vector>
#include "entity.hpp"

void checkMove(Entity&character, std::vector<Entity> &blockers) {

	//check if speed counter has reset
	if (character.speedCount <= 0) {

		//reset speed counter
		character.speedCount = character.speed;
		if (GetKeyState('W') & 0x8000)
		{
			std::get<1>(character.position) -= 1;
			//check for collisions
			for (auto& object : blockers) {
				if (character.isColliding(object))
					std::get<1>(character.position) += 1;
			}

		}

		else if (GetKeyState('S') & 0x8000)
		{
			std::get<1>(character.position) += 1;
			for (auto& object : blockers) {
				if (character.isColliding(object))
					std::get<1>(character.position) -= 1;
			}
		}

		else if (GetKeyState('A') & 0x8000)
		{
			std::get<0>(character.position) -= 1;
			for (auto& object : blockers) {
				if (character.isColliding(object))
					std::get<0>(character.position) += 1;
			}
		}

		else if (GetKeyState('D') & 0x8000)
		{
			std::get<0>(character.position) += 1;
			for (auto& object : blockers) {
				if (character.isColliding(object))
					std::get<0>(character.position) -= 1;
			}
		}
	}
	else
		character.speedCount--;
}

