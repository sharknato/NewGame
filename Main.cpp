#include "character.hpp"
#include "wall.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 900), "Title");

    Player player1(600.f, 600.f);

    Wall newWall(200.f, 200.f);

    sf::RectangleShape wallShape(sf::Vector2f(50.f, 50.f));

    wallShape.setPosition(newWall.position);
    
    sf::RectangleShape shape(sf::Vector2f(25.f, 50.f));

    wallShape.setFillColor(sf::Color::White);

    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player1.checkMove();



        shape.setPosition(player1.position);
        

        window.clear();
        window.draw(shape);
        window.draw(wallShape);
        window.display();
    }

    return 0;
}
