// task.cpp

#include "task.hpp"

// ********************************************************************
// Task Class Static Definitions
// ********************************************************************

const float Task::MAX_IMPORTANCE {10.0};
const float Task::MIN_IMPORTANCE {0.0};
const float Task::MAX_URGENCY {10.0};
const float Task::MIN_URGENCY {0.0};

int Task::_numberOfTasks {0};

// ********************************************************************
// Task Class Definition
// ********************************************************************

Task::Task()
    : _id {++_numberOfTasks}
{ }

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

std::string Task::getDuration() const
{
    return std::to_string(_duration) + " " + _duration_unit;
}

void Task::setDuration(int duration, std::string unit)
{
    _duration = duration;
    _duration_unit = move(unit);
}

status Task::getStatus() const
{
    return _status;
}

void Task::setStatus(status new_status)
{
    _status = new_status;
}

bool Task::isRecurring() const
{
    return _recurrence.empty();
}

std::string Task::getRecurrence() const
{
    return _recurrence;
}

void Task::setRecurrence(std::string recurrence)
{
    _recurrence = move(recurrence);
}

float Task::getAmountCompleted() const
{
    return _amount_completed;
}

void Task::setAmountCompleted(float completed)
{
    _amount_completed = completed;
}
