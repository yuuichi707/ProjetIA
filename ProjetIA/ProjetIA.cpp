#include <SFML/Graphics.hpp>
#include <optional>
#include "Batiment1.h"
#include "Batiment2.h"
#include "Batiment3.h"
#include "Batiment4.h"

int main()
{

    Batiment1 rect(1920, 1080, 0, 0);
    Batiment2 rect2(1920, 1080, 1920-900, 0);
    Batiment3 rect3(1920, 1080, 0, 900-300);
    Batiment4 rect4(1920, 1080, 1920-900, 900-300);
   

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
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        // 
        //window.draw(sprite);
       // window.draw(rectangle);
        rect.setColor(sf::Color::Red);
        rect2.setColor(sf::Color::Red);
        rect3.setColor(sf::Color::Red);
        rect4.setColor(sf::Color::Red);
        rect.draw(window);
        rect2.draw(window);
        rect3.draw(window);
        rect4.draw(window);
        // Update the window
        window.display();
    }
}