#include <SFML/Graphics.hpp>
#include <optional>
#include "Scene.h"
#include "Bouton.h"
#include "Play.h"
#include "Quit.h"
#include "Batiment1.h"
#include "Batiment2.h"
#include "Batiment3.h"
#include "Batiment4.h"
#include "Character.h"
#include "Character2.h"
#include "Clock.h"
#include "BehaviorTree.h"
#include "Node.h"

int main() {
    Batiment1 rect(1440, 400, 0, 500);
    Batiment2 rect2(1440, 1300, 0, 0);
    Batiment3 rect3(1440, 900, 800, 0);
    Batiment4 rect4(1440, 900, 800, 500);
    Character* rect5 = new Character(100,100,0,0);
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 1440, 900 }), "SFML window");
    

        Clock BTClock = Clock(true);
        const float Duration = 20.0f;

        NPCBlackBoard* MyBlackBoard = new NPCBlackBoard(rect5);
        BehaviorTree* MyBt = new NPCBehaviorTree(MyBlackBoard);
        MyBt->BuildTree();
        MyBt->BeginExecute();
    
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float DeltaTime = BTClock.GetElapsedTime();
        MyBt->Tick(DeltaTime);

        // Clear screen
        window.clear();
        rect.setColor(sf::Color::Red);
        rect2.setColor(sf::Color::Red);
        rect3.setColor(sf::Color::Red);
        rect4.setColor(sf::Color::Red);
        rect.draw(window);
        rect2.draw(window);
        rect3.draw(window);
        rect4.draw(window);
        rect5->draw(window);
        // Update the window
        window.display();
    }
}