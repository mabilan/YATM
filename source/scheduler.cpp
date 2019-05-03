// scheduler.cpp

#include "scheduler.hpp"

float getPriority(Task const &task)
{
    float dueDateWeight = getDueDateWeight(task);
    float weightedImportance;
    if (dueDateWeight >= 0)
    {
        weightedImportance = task.importance * dueDateWeight;
    }
    else
    {
        weightedImportance = (task.importance)*(task.importance);
    }

    return weightedImportance + (task.urgency)*(task.urgency);
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
        return -1;
    }

    return taskDurationMinutes/minutesUntilDue;
}

bool leftTaskHasHigherPriority(const Task & lhs, const Task & rhs)
{
    return getPriority(lhs) >= getPriority(rhs); 
}

void sortByHighestPriority(std::vector<Task> & tasklist)
{
    std::sort(tasklist.begin(), tasklist.end(), leftTaskHasHigherPriority);
}
