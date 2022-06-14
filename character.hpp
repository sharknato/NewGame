#pragma once
//#ifndef character
//#define character

#include "entity.hpp"
#include <windows.h>

	class Player {

		//parameters
		float width = 25.f;
		float height = 50.f;
		//maybe move this to a config file in future
		float speed = .5;

	public:

		//in-game changing
		sf::Vector2f position;



		Player() = default;

		Player(float x, float y)
			: position(x, y)
		{
		}

		//to be moved 
		void checkMove() {

				if (GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
				{
					position.y - speed;
				}

				if (GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
				{
					position.y += speed;
				}

				if (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
				{
					position.x -= speed;
				}

				if (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
				{
					position.x += speed;
				}
		}


	};



/*
 * Defines the playable characters in the game
 *
 */

/*
namespace Entity
{
	class Player {
	public:

		sf::Vector2f position;

		Player();

		Player(float x, float y);

		void checkMove();


	};



}
*/

//#endif