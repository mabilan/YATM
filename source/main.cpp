// main.cpp
//
// Simple SFML main.


#include <SFML/Graphics.hpp>


#include "graphics.hpp"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "YATM: Yet Another Task Manager");

    // sf::FloatRect(left, top, width, height)
    auto bounds = sf::FloatRect(0.0, 0.0, 800.0, 600.0);
    auto axes = Axes(bounds, 2.0, sf::Color::White);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw Axes
        window.draw(axes);

        // Update the window
        window.display();
    }

    return 0;
}
