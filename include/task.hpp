// task.hpp

#ifndef FILE_TASK_HPP_INCLUDED
#define FILE_TASK_HPP_INCLUDED

#include <memory>
#include <SFML/Window.hpp>

class Category;

#include "category.hpp"


class Task {
public:
    // Public Constants
    static const float MAX_IMPORTANCE;
    static const float MIN_IMPORTANCE;
    static const float MAX_URGENCY;
    static const float MIN_URGENCY;
    std::string name;
    float importance;
    float urgency;
    std::shared_ptr<Category> ptrToCategory;

public:
    Task();
    ~Task() = default;

    int getId() const;

    void drawFocused(sf::RenderWindow & window, sf::Vector2f position) const;
    void drawUnfocused(sf::RenderWindow & window, sf::Vector2f position) const;

private:
    int _id;

    // Denotes the total number of tasks ever created
    // (Increments each construction)
    static int _numberOfTasks;
};

#endif // #ifndef FILE_TASK_HPP_INCLUDED
