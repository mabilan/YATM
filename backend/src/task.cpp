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

std::string Task::get_name()
{
    return _name;
}

void Task::set_name(std::string name)
{
    _name = move(name);
}

int Task::get_importance()
{
    return _importance;
}

void Task::set_importance(int importance)
{
    _importance = importance;
}

int Task::get_urgency()
{
    return _urgency;
}

void Task::set_urgency(int urgency)
{
    _urgency = urgency;
}

std::string Task::get_category()
{
    return _category;
}

void Task::set_category(std::string category)
{
    _category = move(category);
}

std::string Task::get_duration()
{
    return std::to_string(_duration) + " " + _duration_unit;
}

void Task::set_duration(float duration, std::string unit)
{
    _duration = duration;
    _duration_unit = move(unit);
}

status Task::get_status()
{
    return _status;
}

void Task::set_status(status new_status)
{
    _status = new_status;
}

bool Task::is_recurring()
{
    return _recurrence.empty();
}

std::string Task::get_recurrence()
{
    return _recurrence;
}

void Task::set_recurrence(std::string recurrence)
{
    _recurrence = move(recurrence);
}

float Task::get_amount_completed()
{
    return _amount_completed;
}

void Task::set_amount_completed(float completed)
{
    _amount_completed = completed;
}

int Task::get_id()
{
    return _id;
}