// main.cpp
//
// Simple SFML main.


#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "graphics.hpp"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "YATM: Yet Another Task Manager");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

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

    // Used by ImGui
    sf::Clock deltaClock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Let ImGui process events too
            ImGui::SFML::ProcessEvent(event);

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

        // *** ImGui Widget for Task Stack

        // Imgui Update() Required
        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGuiCond_Always forces these conditions
        ImGui::SetNextWindowSize(ImVec2(200, 600), ImGuiCond_Always);
        ImGui::SetNextWindowPos(ImVec2(600, 0), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
        ImGui::Begin("Task Stack", 0, ImGuiWindowFlags_NoResize);

        static int selected = 0;
        const auto & positions = graph.getPositions();
        for (int i = 0; i < int(positions.size()); ++i)
        {
            // This is temporary.
            // Ideally, get C style strings from Michael Bilan's scheduler

            char label[128];
            sprintf(label, "Circle at (%d, %d)", int(positions[i].x), int(positions[i].y));
            if (ImGui::Selectable(label, selected == i))
            {
                selected = i;
                graph.setFocus(selected);
            }
        }
        ImGui::End(); // End ImGui widget window


        // Clear screen
        window.clear();

        // Draw Graph
        window.draw(graph);

        // Render ImGui widgets on top of everything else
        ImGui::SFML::Render(window);

        // Update the window
        window.display();
    }

    // CJ: My understanding is ShutDown() does some clean up
    ImGui::SFML::Shutdown();

    return 0;
}
