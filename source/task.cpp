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
    : _id {++_numberOfTasks},
      _name {"New Task"},
      _importance {0},
      _urgency {0},
      _ptrToCategory {nullptr}
{ }

const std::string & Task::getName() const
{
    return _name;
}

int Task::getId() const
{
    return _id;
}

void Task::setName(std::string name)
{
    _name = std::move(name);
};


float Task::getImportance() const
{
    return _importance;
}

void Task::setImportance(float value)
{
    _importance = value;
}


float Task::getUrgency() const
{
    return _urgency;
}

void Task::setUrgency(float value)
{
    _urgency = value;
}

std::shared_ptr<Category> Task::getCategory() const
{
    return _ptrToCategory;
}

void Task::setCategory(std::shared_ptr<Category> ptrToCategory)
{
    _ptrToCategory = std::move(ptrToCategory);
}

void Task::drawFocused(sf::RenderWindow & window, sf::Vector2f position) const
{
    if (_ptrToCategory)
    {
        _ptrToCategory->drawFocused(window, *this, position);
    }
    else
    {
        Category::Default->drawFocused(window, *this, position);
    }
}

void Task::drawUnfocused(sf::RenderWindow & window, sf::Vector2f position) const
{
    if (_ptrToCategory)
    {
        _ptrToCategory->drawUnfocused(window, *this, position);
    }
    else
    {
        Category::Default->drawUnfocused(window, *this, position);
    }
}