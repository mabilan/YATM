// graphics.hpp

#include <SFML/Graphics.hpp>

class Axes : public sf::Drawable
{
public:
    Axes(sf::FloatRect bounds, float thickness, sf::Color color);

    ~Axes() = default;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::RectangleShape _horizontalLine, _verticalLine;
};