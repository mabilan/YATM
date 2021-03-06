// graphics.cpp


#include "graphics.hpp"


Axes::Axes(sf::FloatRect bounds, float thickness, sf::Color color)
    : _bounds{bounds}, _horizontalLine{}, _verticalLine{}
{
    setColor(color);
    setThickness(thickness);
}

void Axes::setThickness(float thickness)
{
    auto x = _bounds.left;
    auto y = _bounds.top;
    auto width = _bounds.width;
    auto height = _bounds.height;

    // Axes are centered within the bounds with the specified thickness

    // Horizontal Axis
    _horizontalLine.setSize(sf::Vector2f(width, thickness));
    _horizontalLine.setPosition(x, height/2 - thickness/2);

    // Vertical Axis
    _verticalLine.setSize(sf::Vector2f(thickness, height));
    _verticalLine.setPosition(width/2 - thickness/2, y);
}

void Axes::setColor(sf::Color color)
{
    _horizontalLine.setFillColor(color);
    _verticalLine.setFillColor(color);
}

bool Axes::contains(float x, float y) const
{
    return _bounds.contains(x, y);
}

void Axes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_horizontalLine, states);
    target.draw(_verticalLine, states);
}


Graph::Graph(Axes axes, sf::CircleShape circle)
    : _axes{axes},
      _templateCircle{circle},
      _positions{},
      _focus{-1}
{ }

void Graph::addCircle(float x, float y)
{
    if (_axes.contains(x,y))
    {
        // Set focus to newly created item
        _focus = _positions.size();

        const auto CIRCLE_RADIUS = _templateCircle.getRadius();

        _positions.emplace_back( sf::Vector2f{x - CIRCLE_RADIUS, y - CIRCLE_RADIUS} );
    }
}

void Graph::removeCircle(float x, float y)
{
    if ( !_axes.contains(x, y) )
    {
        return;
    }

    // Focus nothing
    _focus = -1;

    const auto CIRCLE_RADIUS = _templateCircle.getRadius();

    // Erase the first (from back to front) circle which the
    // coordinates are in
    for (auto iter = _positions.rbegin(); iter != _positions.rend(); ++iter)
    {
        auto position = (*iter);
        auto circX = position.x + CIRCLE_RADIUS;
        auto circY = position.y + CIRCLE_RADIUS;

        // If within circle, erase it
        if ((x-circX)*(x-circX) + (y-circY)*(y-circY) <= CIRCLE_RADIUS*CIRCLE_RADIUS)
        {
            // Reverse iterators have an offset by one
            // error and need to be converted into a 
            // regular iterator to erase
            std::advance(iter, 1);
            _positions.erase( iter.base() );
            break;
        }
    }
}


void Graph::setTemplateCircle(sf::CircleShape circle)
{
    _templateCircle = circle;
}

const std::vector<sf::Vector2f> & Graph::getPositions() const
{
    return _positions;
}

void Graph::setFocus(int focus)
{
    _focus = focus;
}

void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_axes, states);

    auto temp = _templateCircle;

    for (int i = 0; i < int(_positions.size()); ++i)
    {
        auto position = _positions[i];
        if (_focus == i)
        {
            auto focusedCircle = _templateCircle;
            focusedCircle.setOutlineColor(sf::Color::Yellow);
            focusedCircle.setOutlineThickness(2.0);

            focusedCircle.setPosition(position);
            target.draw(focusedCircle, states);
        }
        else
        {
            temp.setPosition(position);
            target.draw(temp, states);
        }
    }
}
