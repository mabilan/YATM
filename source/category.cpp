// category.cpp

#include "category.hpp"


// ********************************************************************
// Static Category Definitions
// ********************************************************************


// "Default Category" for unassigned tasks - Undefined
std::shared_ptr<Category> Category::Default{};

int Category::_numberOfCategories {0};


// ********************************************************************
// Category Class Definition
// ********************************************************************

Category::Category()
    : _id{++ _numberOfCategories},
      _name{"New Category"},
      _focusedDrawablePtr{nullptr},
      _unfocusedDrawablePtr{nullptr}
{ }

void Category::setName(std::string name)
{
    _name = std::move(name);
}

void Category::setFocusedDrawable(std::unique_ptr<sf::CircleShape> && drawablePtr)
{
    _focusedDrawablePtr = std::move(drawablePtr);
}

void Category::setUnfocusedDrawable(std::unique_ptr<sf::CircleShape> && drawablePtr)
{
    _unfocusedDrawablePtr = std::move(drawablePtr);
}

void Category::drawFocused(sf::RenderWindow & window, sf::Vector2f position)
{
    (void) task; // @POTENTIAL - Inherited class which draws blased on this

    if (_focusedDrawablePtr)
    {
        const auto RADIUS = _focusedDrawablePtr->getRadius();
        position.x -= RADIUS;
        position.y -= RADIUS;
        _focusedDrawablePtr->setPosition(position);
        window.draw(*_focusedDrawablePtr);
    }
}

void Category::drawUnfocused(sf::RenderWindow & window, sf::Vector2f position)
{
    (void) task; // @POTENTIAL - Inherited class which draws blased on this

    if (_unfocusedDrawablePtr)
    {
        const auto RADIUS = _unfocusedDrawablePtr->getRadius();
        position.x -= RADIUS;
        position.y -= RADIUS;
        _unfocusedDrawablePtr->setPosition(position);
        window.draw(*_unfocusedDrawablePtr);
    }
}
