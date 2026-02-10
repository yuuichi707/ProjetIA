#pragma once
#include <SFML/Graphics.hpp>

class Batiment2
{
private:
	sf::Texture texture;
public:
	Batiment2(float width, float height, float x = 0.f, float y = 0.f);

	void setTextureRect(float x, float y);
	void setSize(float x, float y);
	void setPosition(float x, float y);

	void draw(sf::RenderWindow & window);

	sf::RectangleShape rectangle;
};

