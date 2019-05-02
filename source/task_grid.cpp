// task_grid.cpp

#include "task_grid.hpp"

TaskGrid::TaskGrid(sf::FloatRect bounds)
    : _bounds{bounds},
      _axes{_bounds, 2.0, sf::Color::White},
      _circle{}
{ }

void TaskGrid::setAxesThickness(float thickness)
{
    _axes.setThickness(thickness);
}

void TaskGrid::setAxesColor(sf::Color color)
{
    _axes.setColor(color);
}

bool TaskGrid::contains(int x, int y) const
{
    return _bounds.contains(x, y);
}

sf::Vector2f TaskGrid::getUrgVsImp(int x, int y) const
{
    const auto URG_DIFF = Task::MAX_URGENCY - Task::MIN_URGENCY;
    auto fx = URG_DIFF * (float(x) - _bounds.left) / _bounds.width;

    auto IMP_DIFF = Task::MAX_IMPORTANCE - Task::MIN_IMPORTANCE;
    auto fy = IMP_DIFF - (IMP_DIFF * float(y - _bounds.top)/ _bounds.height);
    return sf::Vector2f{fx, fy};
}

sf::Vector2f TaskGrid::getPosition(const Task & task) const
{
    auto urgency = task.getUrgency();
    auto importance = task.getImportance();

    float x = _bounds.width*urgency/(Task::MAX_URGENCY - Task::MIN_URGENCY) + _bounds.left;
 
    auto IMP_DIFF = Task::MAX_IMPORTANCE - Task::MIN_IMPORTANCE;
    float y = _bounds.height*(IMP_DIFF - importance)/(IMP_DIFF) + _bounds.top;

    return sf::Vector2f{x, y};
}

void TaskGrid::draw(sf::RenderWindow & window, const std::vector<Task> & tasklist, int idOfSelected)
{
    window.draw(_axes);

    for (auto iter = tasklist.begin(); iter != tasklist.end(); ++iter)
    {
        auto position = getPosition(*iter);

        if (iter->getId() == idOfSelected)
        {
            iter->drawFocused(window, position);
        }
        else
        {
            iter->drawUnfocused(window, position);
        }
    }
}
