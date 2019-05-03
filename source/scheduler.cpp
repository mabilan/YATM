// scheduler.cpp

#include "scheduler.hpp"

std::vector<Task> adjustSchedule(std::vector<Task> const &tasklist)
{
std::vector<std::pair<float, Task>> taskSchedule;
std::vector<Task> finalSchedule;

for(auto task : tasklist)
{
taskSchedule.push_back(std::make_pair(getPriority(task), task));
}

std::sort(taskSchedule.begin(), taskSchedule.end());

for(auto task : taskSchedule)
{
finalSchedule.push_back(task.second);
}

return finalSchedule;
}

float getPriority(Task const &task)
{
    return 0;
}

bool pairFirstCompare(const std::pair<float, Task> &x, const std::pair<float, Task> &y)
{
    return x.first < y.first;
}

float getDueDateWeight(Task const &task)
{
    Date defaultDueDate = {1, 1, 2019};

    if (task.getDueDate().getDate() == defaultDueDate.getDate())
    {
        return 0;
    }
    else if (task.getDueDate().getDate()[0] == 0 &&
             task.getDueDate().getDate()[1] == 0 &&
             task.getDueDate().getDate()[2] == 0)
    {
        return 0;
    }

    const int yearMinutes = 525600;
    const int monthMinutes = 43200;
    const int dayMinutes = 1440;

    Date rightNow;
    rightNow.currentDate();

    int taskDurationMinutes = (task.getDuration().getTime()[0]*60) + (task.getDuration().getTime()[1]);
    int minutesUntilDue = (task.getDueDate().getDate()[0] - rightNow.getDate()[0])*yearMinutes +
                          (task.getDueDate().getDate()[1] - rightNow.getDate()[1])*monthMinutes +
                          (task.getDueDate().getDate()[2] - rightNow.getDate()[2])*dayMinutes;
    if (minutesUntilDue <= 0)
    {
        return 99999999999;
    }
    return taskDurationMinutes/minutesUntilDue;
}