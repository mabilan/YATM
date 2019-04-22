//
// Created by bryant on 4/16/19.
//

#ifndef TASK_HPP_INCLUDED
#define TASK_HPP_INCLUDED

#include <string>

enum class status
{
    NOT_YET_STARTED,
    WORK_IN_PROGRESS,
    DONE,
    DEFERRED,
    NOT_GOING_TO_HAPPEN
};

class Task
{
public:
    Task();

    std::string get_name();

    void set_name(std::string);

    int get_importance();

    void set_importance(int);

    int get_urgency();

    void set_urgency(int);

    std::string get_category();

    void set_category(std::string);

    std::string get_duration();

    void set_duration(float, std::string);

    status get_status();

    void set_status(status);

    bool is_recurring();

    std::string get_recurrence();

    void set_recurrence(std::string);

    float get_amount_completed();

    void set_amount_completed(float);

    int get_id();

private:
    int _id;
    std::string _name{"New Task"};
    int _importance{0};
    int _urgency{0};
    std::string _category;
    float _duration{0};
    std::string _duration_unit{"Hours"};
    status _status{status::NOT_YET_STARTED};
    std::string _recurrence{""};
    float _amount_completed{0};

    // denotes total lifetime tasks (never automatically decrease)
    static int _number_of_tasks;
};

#endif //TASK_HPP_INCLUDED
