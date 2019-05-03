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

Time Task::getDuration() const
{
    return _duration;
}

void Task::setDuration(Time duration)
{
    _duration = duration;
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
    auto time = _recurrence.getTime();
    if(time[0] == 0 && time[1] == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Time Task::getRecurrence() const
{
    return _recurrence;
}

void Task::setRecurrence(Time recurrence)
{
    _recurrence = std::move(recurrence);
}

Time Task::getAmountCompleted() const
{
    return _amountCompleted;
}

void Task::setAmountCompleted(Time completed)
{
    _amountCompleted = completed;
}
