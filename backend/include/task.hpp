//
// Created by bryant on 4/16/19.
//

#ifndef YATM_BACKEND_TASK_HPP
#define YATM_BACKEND_TASK_HPP

#include <string>

enum class status {
    NOT_YET_STARTED,
    WORK_IN_PROGRESS,
    DONE,
    DEFERRED,
    NOT_GOING_TO_HAPPEN
};

class task {
public:

private:
    int _id;
    std::string _name{"New Task"};
    int _importance {0};
    int _urgency {0};
    std::string _category;
    float _duration{0};
    std::string _duration_unit{"Hours"};
    status _status {status::NOT_YET_STARTED};
    std::string _recurrence{""};
    float _amount_completed;

    static int _number_of_tasks;
};

#endif //YATM_BACKEND_TASK_HPP
