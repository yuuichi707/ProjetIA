#include <SFML/Graphics.hpp>
// #include <optional>
// #include "Scene.h"
#include "Batiment1.h"
#include "Batiment2.h"
#include "Batiment3.h"
#include "Batiment4.h"
#include "Bouton.h"
#include "Character.h"
#include "Character2.h"
#include "Play.h"
#include "Quit.h"
#include "Way.h"



int main() {
 Batiment1 rect(1440, 900, -30, 370);
 Batiment2 rect2(1440, 900, -62, -25);
 Batiment3 rect3(1440, 900, 795, -20);
 Batiment4 rect4(1440, 900, 755, 420);
 Character rect5(1440, 900, 400, 300);
 //Character2 rect6(500, 450, 300, 0);
 //Way rect(1440, 900, -30, 200);
     // Bouton* Rect1 = new Play(1440, 900, 1440 / 2, 900 / 2);
     // Bouton* Rect2= new Quit(1440, 900, 1440 / 2 + 200, 900 / 2);


    // Create the main window
 sf::RenderWindow window(sf::VideoMode({ 1440, 900 }), "ANIME_WORLD");


     // Scene* TestScene = new Scene();
    // Start the game loop
    while (window.isOpen()) {
         // Process events
        while (const auto event = window.pollEvent()) {
         //      Close window: exit
         if (event->is<sf::Event::Closed>())
          window.close();
        }
         //     //regarde lorsque la souris ou le clavier est cliquer
         //     const sf::Event::KeyPressed* currentInputKey = event->getIf<sf::Event::KeyPressed>();
         //     const sf::Event::MouseButtonPressed* currentInputMouse = event->getIf<sf::Event::MouseButtonPressed>();
         //
         //      bool Playclick = Rect1->DetectOnClick(currentInputMouse);
         //      bool Quitclick = Rect2->DetectOnClick(currentInputMouse);
         //       if (Playclick){
         //          Rect1->OnClick(new PlayParams(TestScene));
         //       }
         //      if (Quitclick){
         //          Rect2->OnClick(new QuitParams(&window));
         //      }

             // Clear screen
     window.clear();

              //   if (TestScene->currentScene == Menu) {
              //     Rect1->setColor(sf::Color::Red);
              //     Rect2->setColor(sf::Color::Green);
              //     Rect1->draw(window);
              // /   Rect2->draw(window);
              // }
                  // if (TestScene->currentScene == PLAY) {


     rect.draw(window);
     rect2.draw(window);
     rect3.draw(window);
     rect4.draw(window);
     rect5.draw(window);
     //rect6.draw(window);
     //rect.draw(window);

             // }


            // Update the window
     window.display();

    }
}