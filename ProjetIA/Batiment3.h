#pragma once
#include <SFML/Graphics.hpp>

class Batiment3
{
private:
	sf::Texture texture;
public:
	Batiment3(float width, float height, float x = 0.f, float y = 0.f);

	void setTextureRect(float x, float y);
	void setSize(float x, float y);
	void setPosition(float x, float y);

	void draw(sf::RenderWindow & window);

	sf::RectangleShape rectangle;
};



