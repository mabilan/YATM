// main.cpp
//
// Simple SFML main.


#include <vector>
#include <SFML/Graphics.hpp>


#include "graphics.hpp"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "YATM: Yet Another Task Manager");

    // sf::FloatRect(left, top, width, height)
    auto bounds = sf::FloatRect(0.0, 0.0, 800.0, 600.0);
    auto axes = Axes(bounds, 2.0, sf::Color::White);

    // Circles drawn when user clicks
    const float CIRCLE_RADIUS = 5.0; 
    const auto CIRCLE_COLOR = sf::Color::Red;
    auto circles = std::vector<sf::CircleShape>{};

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    auto x = event.mouseButton.x;
                    auto y = event.mouseButton.y;

                    auto circle = sf::CircleShape(CIRCLE_RADIUS);
                    circle.setPosition(float(x) - CIRCLE_RADIUS, float(y) - CIRCLE_RADIUS);
                    circle.setFillColor(CIRCLE_COLOR);
                    circles.push_back(circle);
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw Axes
        window.draw(axes);

        // Draw Circles
        for (const auto & circle : circles)
        {
            window.draw(circle);
        }

        // Update the window
        window.display();
    }

    return 0;
}
