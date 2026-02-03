#include <SFML/Graphics.hpp>
#include <optional>

#include "Bouton.h"
#include "Play.h"
#include "Quit.h"
#include "Batiment1.h"
#include "Batiment2.h"
#include "Batiment3.h"
#include "Batiment4.h"
#include "Scene.h"

int main()
{

    Bouton* Rect1 = new Play(1920, 1080, 1920 / 2, 1080 / 2);
    Bouton* Rect2 = new Quit(1920, 1080, 1920 / 2 + 200, 1080 / 2);

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

     Scene TestScene;
    
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

            bool Playclick = Rect1->DetectOnClick(currentInputMouse);
            bool Quitclick = Rect2->DetectOnClick(currentInputMouse);
            if (Playclick)
            {
                Rect1->OnClick(nullptr);
            }
            if (Quitclick)
            {
                Rect2->OnClick(new QuitParams(&window));

            }
        }

        // Clear screen
        window.clear();

        if (TestScene.CurrentState == Menu)
        {
            Rect1->setColor(sf::Color::Red);
            Rect2->setColor(sf::Color::Green);
            Rect1->draw(window);
            Rect2->draw(window);
        }
        if (TestScene.currentScene == PLAY)
        {
            rect.setColor(sf::Color::Red);
            rect2.setColor(sf::Color::Red);
            rect3.setColor(sf::Color::Red);
            rect4.setColor(sf::Color::Red);
            rect.draw(window);
            rect2.draw(window);
            rect3.draw(window);
            rect4.draw(window);
        }
        
        // Update the window
        window.display();
    }
}