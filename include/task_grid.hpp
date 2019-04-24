// task_grid.hpp

#ifndef FILE_TASK_GRID_HPP_INCLUDED
#define FILE_TASK_GRID_HPP_INCLUDED

#include <vector>

#include <SFML/Graphics.hpp>

#include "graphics.hpp"
#include "task.hpp"

class TaskGrid
{
public:
    TaskGrid(sf::FloatRect bounds);
    ~TaskGrid() = default;

    // Setters
    void setAxesThickness(float thickness);
    void setAxesColor(sf::Color color);

    // Getters
    bool contains(int x, int y) const;
    sf::Vector2f getUrgVsImp(int x, int y) const;

    // Task interaction of Importance vs Urgency and drawing position
    sf::Vector2f getPosition(const Task & task) const;

    void draw(sf::RenderWindow & window, const std::vector<Task> & tasklist, std::vector<Task>::iterator selected);

private:
    sf::FloatRect _bounds;
    Axes _axes;
    sf::CircleShape _circle;
};

#endif // #ifndef FILE_TASK_GRID_HPP_INCLUDED