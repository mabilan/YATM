// graphics.hpp

#ifndef FILE_GRAPHICS_HPP_INCLUDED
#define FILE_GRAPHICS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Axes : public sf::Drawable
{
public:
    Axes(sf::FloatRect bounds, float thickness, sf::Color color);

    ~Axes() = default;

    bool contains(float x, float y) const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::FloatRect _bounds;
    sf::RectangleShape _horizontalLine, _verticalLine;
};


#include <SFML/Graphics.hpp>
#include <vector>

class Graph : public sf::Drawable
{
public:
	Graph(Axes axes, sf::CircleShape circle);
	~Graph() = default;

	void addCircle(float x, float y);
	void removeCircle(float x, float y);

	void setTemplateCircle(sf::CircleShape circle);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Axes _axes;
	sf::CircleShape _templateCircle;
	std::vector<sf::Vector2f> _positions;
};

#endif // #ifndef FILE_GRAPHICS_HPP_INCLUDED
