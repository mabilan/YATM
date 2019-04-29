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

    const std::string & getName() const;
    void setName(std::string name);

    float getImportance() const;
    void setImportance(float value);

    float getUrgency() const;
    void setUrgency(float value);

    std::shared_ptr<Category> getCategory() const;
    void setCategory(std::shared_ptr<Category> ptrToCategory);

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


private:
    int _id;
    std::string _name{"New Task"};
    float _importance{0};
    float _urgency{0};
    std::shared_ptr<Category> _ptrToCategory {nullptr};
    status _status{status::NOT_YET_STARTED};
    // TODO: Change time based members to use the Date/Time class
    int _duration{0};
    std::string _duration_unit{"minute"};
    std::string _recurrence{""};
    float _amount_completed{0};

    // Denotes the total number of tasks ever created
    // (Increments each construction)
    static int _numberOfTasks;
};

#endif // #ifndef FILE_TASK_HPP_INCLUDED
