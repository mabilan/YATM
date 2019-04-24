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

private:
    int _id;
    std::string _name;
    float _importance;
    float _urgency;
    std::shared_ptr<Category> _ptrToCategory;

    // Denotes the total number of tasks ever created
    // (Increments each construction)
    static int _numberOfTasks;
};

#endif // #ifndef FILE_TASK_HPP_INCLUDED
