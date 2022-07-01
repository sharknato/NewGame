#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "world.hpp"
#include "controller.hpp"


class Game {

    World world;
    std::vector<Entity> entities;
    sf::Vector2u screenSize;
    float squareSize;

public:

	Game() 
        : world()
    {

	}

    void start() {
        sf::RenderWindow window(sf::VideoMode(1800, 1300), "Title");

        //use screen size to determine size of grid
        float squareSize = 900.f / world.columns;

        for (auto &wall : world.walls) {
            entities.push_back(wall);

        }
        
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            updateWorld();

            //draws the window
            window.clear();

            screenSize = window.getSize();

            sf::RectangleShape gameBox(sf::Vector2f(1100.f, 1100.f));

            //create box for the game to happen in
            gameBox.setPosition(sf::Vector2f((screenSize.x / 2) - (gameBox.getSize().x / 2) ,
               (screenSize.y / 2) - (gameBox.getSize().y / 2)));

            //get origin for all in-game positions
            sf::Vector2f boxOrigin = gameBox.getPosition();

            gameBox.setFillColor(sf::Color(60, 60, 60));

            window.draw(gameBox);

            for (auto& wall : world.walls) {
                sf::RectangleShape shape(sf::Vector2f(wall.width * squareSize,
                    wall.height * squareSize));

                shape.setPosition(sf::Vector2f(((std::get<0>(wall.position) * squareSize) + boxOrigin.x),
                    ((std::get<1>(wall.position) * squareSize)) + boxOrigin.y));

                window.draw(shape);
            }

            sf::RectangleShape playerShape(sf::Vector2f((world.player.width * squareSize),
                (world.player.height * squareSize)));

            playerShape.setPosition(sf::Vector2f(((std::get<0>(world.player.position) * squareSize) + boxOrigin.x), 
                ((std::get<1>(world.player.position) * squareSize) + boxOrigin.y)));

            playerShape.setFillColor(sf::Color::Red);

            window.draw(playerShape);

            window.display();

        }

    }

	void updateWorld() {
		
        checkMove(world.player, entities);


	}
    
	void drawWorld(sf::RenderWindow &window) {
    
	}

};