#include <SFML/Graphics.hpp>
#include <optional>
#include "Bouton.h"
#include <iostream>

int main()
{

    Bouton rect(1920, 1080, 1920/2, 1080/2);


    /* sf::RectangleShape rectangle;*/
     // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML window");

    // Load a sprite to display
    //const sf::Texture texture("cute_image.jpg");
    //sf::Sprite sprite(texture);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
            //regarde lorsque la souris ou le clavier est cliquer
            const sf::Event::KeyPressed* currentInputKey = event->getIf<sf::Event::KeyPressed>();
            const sf::Event::MouseButtonPressed* currentInputMouse = event->getIf<sf::Event::MouseButtonPressed>();
            rect.DetectOnClick(currentInputMouse);
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        // 
        //window.draw(sprite);
       // window.draw(rectangle);
        rect.setColor(sf::Color::Red);
        rect.draw(window);
        // Update the window
        window.display();
    }
}