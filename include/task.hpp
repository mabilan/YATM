// task.hpp

#ifndef FILE_TASK_HPP_INCLUDED
#define FILE_TASK_HPP_INCLUDED

#include <memory>
#include <SFML/Window.hpp>
#include <string>

class Category;

#include "category.hpp"

enum class status
{
    NOT_YET_STARTED,
    WORK_IN_PROGRESS,
    DONE,
    DEFERRED,
    NOT_GOING_TO_HAPPEN
};

class Task {
public:
    // Public Constants
    static const float MAX_IMPORTANCE;
    static const float MIN_IMPORTANCE;
    static const float MAX_URGENCY;
    static const float MIN_URGENCY;

public:
    Task();
    ~Task() = default;

    int getId() const;

    void drawFocused(sf::RenderWindow & window, sf::Vector2f position) const;
    void drawUnfocused(sf::RenderWindow & window, sf::Vector2f position) const;

    status getStatus() const;
    void setStatus(status new_status);

    // TODO: Change time based parameters and return values to the Date/Time class
    std::string getDuration() const;
    void setDuration(int duration, std::string unit);

    bool isRecurring() const;
    std::string getRecurrence() const;
    void setRecurrence(std::string recurrence);

    float getAmountCompleted() const;
    void setAmountCompleted(float);

public:
    // Public Attributes
    std::string name{"New Task"};
    float importance{0};
    float urgency{0};
    std::shared_ptr<Category> ptrToCategory {nullptr};

private:
    int _id;
    status _status{status::NOT_YET_STARTED};
    // @TODO: Change time based members to use the Date/Time class
    int _duration{0};
    std::string _duration_unit{"minute"};
    std::string _recurrence{""};
    float _amount_completed{0};

    // Denotes the total number of tasks ever created
    // (Increments each construction)
    static int _numberOfTasks;
};

#endif // #ifndef FILE_TASK_HPP_INCLUDED
