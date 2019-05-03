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

Task::Task(int id, std::string name, float importance, float urgency, std::string status, int day, int month, int year)
    : _id{id}, name{name}, importance{importance}, urgency{urgency}, _dueDate{day, month, year}
{
    if ( status == "NOT_YET_STARTED")
    {
        _status = status::NOT_YET_STARTED;
    }
    else if ( status == "WORK_IN_PROGRESS")
    {
        _status = status::WORK_IN_PROGRESS;
    }
    else if ( status == "DONE")
    {
        _status = status::DONE;
    }
    else if ( status == "DEFERRED")
    {
        _status = status::DEFERRED;
    }
    else if ( status == "NOT_GOING_TO_HAPPEN")
    {
        _status = status::NOT_GOING_TO_HAPPEN;
    }
}

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

std::string Task::printStatus() const
{
    if ( _status == status::NOT_YET_STARTED)
    {
        return "NOT_YET_STARTED";
    }
    else if ( _status == status::WORK_IN_PROGRESS)
    {
        return "WORK_IN_PROGRESS";
    }
    else if ( _status == status::DONE)
    {
        return "DONE";
    }
    else if ( _status == status::DEFERRED)
    {
        return "DEFERRED";
    }
    else if ( _status == status::NOT_GOING_TO_HAPPEN)
    {
        return "NOT_GOING_TO_HAPPEN";
    }
    else
    {
        return "No Status";
    }
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

Date Task::getDueDate() const
{
    return _dueDate;
}

void Task::setDueDate(Date date)
{
    _dueDate = date;
}

json Task::generateJSON() const
{
    json task_json = {
            {"id", _id},
            {"name", name},
            {"importance", importance},
            {"urgency",urgency},
            {"status", Task::printStatus()},
            {"due date day", _dueDate.getDate()[0]},
            {"due date month", _dueDate.getDate()[1]},
            {"due date year", _dueDate.getDate()[2]}

    };

    return task_json;
}
