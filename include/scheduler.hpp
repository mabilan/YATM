//scheduler.hpp

#ifndef YATM2_SCHEDULER_HPP
#define YATM2_SCHEDULER_HPP

#include "task.hpp"
#include <algorithm>

std::vector<Task> adjustSchedule(std::vector<Task> const &tasklist);

float getPriority(Task const &task);

bool pairFirstCompare(const std::pair<float, Task> &x, const std::pair<float, Task> &y);

float getDueDateWeight(Task const &task);

float getTimeLeftWeight(Task const &task, const float &dueDateWeight);

#endif //YATM2_SCHEDULER_HPP
