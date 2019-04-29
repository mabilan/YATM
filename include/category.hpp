// category.hpp

#ifndef FILE_CATEGORY_HPP_INCLUDED
#define FILE_CATEGORY_HPP_INCLUDED

#include <memory>
// For std::unique_ptr, std::shared_ptr, std::make_shared

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Task;

#include "task.hpp"

class Category
{
public:
    // "Default Category" for unassigned tasks - Undefined
    static std::shared_ptr<Category> Default;

public:
    Category();
    virtual ~Category() = default;

    void setName(std::string name);

    // @TODO - More?

    void setFocusedDrawable(std::unique_ptr<sf::CircleShape> && drawablePtr);
    void setUnfocusedDrawable(std::unique_ptr<sf::CircleShape> && drawablePtr);

    virtual void drawFocused(sf::RenderWindow & window, sf::Vector2f position);
    virtual void drawUnfocused(sf::RenderWindow & window, sf::Vector2f position);

private:
    int _id;
    std::string _name;
    std::unique_ptr<sf::CircleShape> _focusedDrawablePtr;
    std::unique_ptr<sf::CircleShape> _unfocusedDrawablePtr;

    // Denotes the total number of categories ever created
    // (Increments each construction)
    static int _numberOfCategories;
};

#endif // #ifndef FILE_CATEGORY_HPP_INCLUDED
