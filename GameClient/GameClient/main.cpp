#include "pch.h"

int main()
{
   
    sf::RenderWindow window(sf::VideoMode(constants::window_width,constants::window_height), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::Resized);
        }
        window.clear();
        window.display();
    }
    return 0;
}
