#pragma once
#include <SFML/Graphics.hpp>

class Batiment
{
private:
    sf::Texture texture;
public:
    Batiment(const std::filesystem::path& texturePath, float x = 0.f, float y = 0.f);

    void setTextureRect(float x, float y);
    void setSize(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;
};