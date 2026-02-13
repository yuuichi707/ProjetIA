#include "Quit.h"
#include <iostream>

Quit::Quit() {

}

Quit::Quit(float width, float height, float x, float y)
    : Bouton(width, height, x, y) {
    _bouton = sf::RectangleShape({ 250.f, 100.f });
    texture = sf::Texture("asset/exit.png");
    _bouton.setTexture(&texture);
    setPosition(x, y);
}
void Quit::setTextureRect(float x, float y)
{
    _bouton.setTextureRect({ {10, 10}, {50, 30} });
}

void Quit::OnClick(Params* _params)
{
    QuitParams* CastedParams = static_cast<QuitParams*>(_params);
    CastedParams->InternWindow->close();
    std::cout << "Quit";

}