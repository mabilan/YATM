// graphics.cpp


#include "graphics.hpp"


Axes::Axes(sf::FloatRect bounds, float thickness, sf::Color color)
    : _horizontalLine{}, _verticalLine{}
{
    auto x = bounds.left;
    auto y = bounds.top;
    auto width = bounds.width;
    auto height = bounds.height;

    // Axes are centered within the bounds with the specified thickness

    // Horizontal Axis
    _horizontalLine.setSize(sf::Vector2f(width, thickness));
    _horizontalLine.setPosition(x, height/2 - thickness/2);
    _horizontalLine.setFillColor(color);

    // Vertical Axis
    _verticalLine.setSize(sf::Vector2f(thickness, height));
    _verticalLine.setPosition(width/2 - thickness/2, y);
    _verticalLine.setFillColor(color);
}


void Axes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_horizontalLine, states);
    target.draw(_verticalLine, states);
}
