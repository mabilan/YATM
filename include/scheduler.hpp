//scheduler.hpp

#ifndef YATM2_SCHEDULER_HPP
#define YATM2_SCHEDULER_HPP

#include "task.hpp"
#include <algorithm>

float getPriority(Task const &task);

float getDueDateWeight(Task const &task);

float getTimeLeftWeight(Task const &task, const float &dueDateWeight);

bool leftTaskHasHigherPriority(const Task & lhs, const Task & rhs);

void sortByHighestPriority(std::vector<Task> & tasklist);

#endif //YATM2_SCHEDULER_HPP
