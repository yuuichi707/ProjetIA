#pragma once
#include <SFML/Graphics.hpp>

class Batiment3
{
public:
	Batiment3(float width, float height, float x = 0.f, float y = 0.f);

	void setSize(float x, float y);
	void setPosition(float x, float y);
	void setColor(const sf::Color& color);

	void draw(sf::RenderWindow& window);

	sf::RectangleShape rectangle;
};
