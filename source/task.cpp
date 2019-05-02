// task.cpp

#include "task.hpp"

// ********************************************************************
// Task Class Static Definitions
// ********************************************************************

const float Task::MAX_IMPORTANCE = 10.0;
const float Task::MIN_IMPORTANCE = 0.0;
const float Task::MAX_URGENCY = 10.0;
const float Task::MIN_URGENCY = 0.0;

int Task::_numberOfTasks {0};

// ********************************************************************
// Task Class Definition
// ********************************************************************

Task::Task()
:     name {"New Task"},
      importance {0},
      urgency {0},
      ptrToCategory {nullptr},
      _id {++_numberOfTasks}
{}
// add dummy date
int Task::getId() const
{
    return _id;
}

void Task::drawFocused(sf::RenderWindow & window, sf::Vector2f position) const
{
    if (ptrToCategory)
    {
        ptrToCategory->drawFocused(window, position);
    }
    else
    {
        Category::Default->drawFocused(window, position);
    }
}

void Task::drawUnfocused(sf::RenderWindow & window, sf::Vector2f position) const
{
    if (ptrToCategory)
    {
        ptrToCategory->drawUnfocused(window, position);
    }
    else
    {
        Category::Default->drawUnfocused(window, position);
    }
}
