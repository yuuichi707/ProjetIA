#pragma once
#include <SFML/Graphics.hpp>

class Batiment1
{
public:
	Batiment1(float width, float height, float x, float y);

	void setSize(float x, float y);
    void setPosition(float x, float y);
	void setColor(const sf::Color& color);

	void draw(sf::RenderWindow& window);

	sf::RectangleShape rectangle;
};

