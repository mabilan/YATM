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

