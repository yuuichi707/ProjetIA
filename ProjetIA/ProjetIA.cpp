#include <SFML/Graphics.hpp>
#include <optional>
#include "Bouton.h"
#include "Play.h"
#include "Quit.h"
#include <iostream>

int main()
{

    Bouton* rect1 = new Play(1920, 1080, 1920/2, 1080/2);
    Bouton* rect2 = new Quit(1920, 1080, 1920/2 + 200, 1080/2);


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
            bool Playclick = rect1->DetectOnClick(currentInputMouse);
            bool Quitclick = rect2->DetectOnClick(currentInputMouse);
            if (Playclick)
            {
                rect1->OnClick(nullptr);
            }
            if (Quitclick)
            {
                rect2->OnClick(new QuitParams(&window));

            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        // 
        //window.draw(sprite);
       // window.draw(rectangle);
        rect1->setColor(sf::Color::Red);
        rect2->setColor(sf::Color::Green);
        rect1->draw(window);
        rect2->draw(window);
        // Update the window
        window.display();
    }
}