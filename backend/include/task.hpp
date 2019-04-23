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

    std::string getName();

    void setName(std::string name);

    float getImportance();

    void setImportance(float);

    float getUrgency();

    void setUrgency(float);

    std::string getCategory();

    void setCategory(std::string category);

    std::string getDuration();

    void setDuration(int duration, std::string unit);

    status getStatus();

    void setStatus(status new_status);

    bool isRecurring();

    std::string getRecurrence();

    void setRecurrence(std::string recurrence);

    float getAmountCompleted();

    void setAmountCompleted(float);

    int getId();

private:
    int _id;
    std::string _name{"New Task"};
    float _importance{0};
    float _urgency{0};
    std::string _category;
    int _duration{0};
    std::string _duration_unit{"Minutes"};
    status _status{status::NOT_YET_STARTED};
    std::string _recurrence{""};
    float _amount_completed{0};

    // denotes total lifetime tasks (never automatically decrease)
    static int _number_of_tasks;
};

#endif //TASK_HPP_INCLUDED
