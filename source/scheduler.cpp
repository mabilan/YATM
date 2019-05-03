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

float dueDateWeight(Task const &task)
{
    return 0;
}