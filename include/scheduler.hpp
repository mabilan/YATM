// scheduler.hpp

#ifndef YATM_SCHEDULER_H
#define YATM_SCHEDULER_H

#include "task.hpp"

std::vector<Task> adjustSchedule(std::vector<Task> const &tasklist);

float getPriority(Task const &task);

bool pairFirstCompare(const std::pair<float, Task> &x, const std::pair<float, Task> &y);

float getDueDateWeight(Task const &task);

float getTimeLeftWeight(Task const &task);

#endif //YATM_SCHEDULER_H
