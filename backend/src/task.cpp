//
// Created by bryant on 4/16/19.
//

#include "../include/task.hpp"

int Task::_number_of_tasks = 0;

Task::Task()
{

    ++_number_of_tasks;
    _id = _number_of_tasks;
}

std::string Task::getName()
{
    return _name;
}

void Task::setName(std::string name)
{
    _name = move(name);
}

float Task::getImportance()
{
    return _importance;
}

void Task::setImportance(float importance)
{
    _importance = importance;
}

float Task::getUrgency()
{
    return _urgency;
}

void Task::setUrgency(float urgency)
{
    _urgency = urgency;
}

std::string Task::getCategory()
{
    return _category;
}

void Task::setCategory(std::string category)
{
    _category = move(category);
}

std::string Task::getDuration()
{
    return std::to_string(_duration) + " " + _duration_unit;
}

void Task::setDuration(int duration, std::string unit)
{
    _duration = duration;
    _duration_unit = move(unit);
}

status Task::getStatus()
{
    return _status;
}

void Task::setStatus(status new_status)
{
    _status = new_status;
}

bool Task::isRecurring()
{
    return _recurrence.empty();
}

std::string Task::getRecurrence()
{
    return _recurrence;
}

void Task::setRecurrence(std::string recurrence)
{
    _recurrence = move(recurrence);
}

float Task::getAmountCompleted()
{
    return _amount_completed;
}

void Task::setAmountCompleted(float completed)
{
    _amount_completed = completed;
}

int Task::getId()
{
    return _id;
}