// main.cpp
//
// Simple SFML main.


#include <iostream>
#include <SFML/Graphics.hpp>


#include "graphics.hpp"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "YATM: Yet Another Task Manager");

    // sf::FloatRect(left, top, width, height)
    auto bounds = sf::FloatRect(0.0, 0.0, 600.0, 600.0);
    auto axes = Axes(bounds, 2.0, sf::Color::White);

    // Template Circle to be used within Graph
    const float CIRCLE_RADIUS = 5.0;
    const auto CIRCLE_COLOR = sf::Color::Red;
    auto circle = sf::CircleShape(CIRCLE_RADIUS);
    circle.setFillColor(CIRCLE_COLOR);
    circle.setPointCount(3); // <-- Makes it look like a triangle

    // Graph
    auto graph = Graph(axes, circle);

    // Sidebar - For Task Stack
    auto sidebar = sf::RectangleShape(sf::Vector2f{200.0, 600.0});
    sidebar.setPosition(600.0, 0.0);
    sidebar.setFillColor(sf::Color::White);

    // The following glob is all necessary for text.
    sf::Font font;
    if (!font.loadFromFile("../assets/Ubuntu-M.ttf"))
    {
        std::cout << "ERROR: Unable to load Ubuntu-M.ttf" << std::endl; 
        return 1;
    }
    sf::Text sidebarHeader;
    sidebarHeader.setFont(font);
    sidebarHeader.setString("Task Stack");
    sidebarHeader.setCharacterSize(24); // in pixels, not points!
    sidebarHeader.setColor(sf::Color::Black);

    // Center the text
    auto width = sidebarHeader.getLocalBounds().width;
    sidebarHeader.setPosition(600.0 + (200.0 - width)/2.0, 10.0);

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
            // Mouse Click
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto x = event.mouseButton.x;
                auto y = event.mouseButton.y;

                // Mouse Click - Left Button
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    graph.addCircle(x,y);
                }
                // Mouse Click - Right Button
                else if (event.mouseButton.button == sf::Mouse::Button::Right)
                {
                    graph.removeCircle(x, y);
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw Graph
        window.draw(graph);

        // Draw Sidebar
        window.draw(sidebar);
        window.draw(sidebarHeader);

        // Update the window
        window.display();
    }

    return 0;
}
