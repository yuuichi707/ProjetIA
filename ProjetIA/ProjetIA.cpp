#include <SFML/Graphics.hpp>
#include <optional>
#include "Scene.h"
#include "Bouton.h"
#include "Play.h"
#include "Quit.h"
#include "Batiment.h"
#include "Character.h"
#include "Character2.h"
#include "Clock.h"
#include "BehaviorTree.h"
#include "Node.h"
#include "Way.h"
#include "Waytwo.h"
#include "Background.h"

int main() {
    Batiment rect("asset/bar.png", -30, 470);
    Batiment rect2("asset/Boulangerie.png", -62, -25);
    Batiment rect3("asset/commerce.png", 795, -20);
    Batiment rect4("asset/BoulangerieTwo.png", 795, 490);
    Character rect5(1440, 900, 400, 300);
    Way rect7(1440, 900, -30, 100);
    Waytwo rect8(1440, 900, 450, 0);
    Bouton* Rect1 = new Play(1440, 900, 500, 900 / 2);
    Bouton* Rect2 = new Quit(1440, 900, 500 + 260, 900 / 2);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 1440, 900 }), "Anime World");
    
    Scene* TestScene = new Scene();

    Background rect9(1440, 900, 0, 0);

    NPCBlackBoard* MyBlackBoard = nullptr;
    BehaviorTree* MyBT = nullptr;
    
    /*float LastScene = TestScene->currentScene;*/

    

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const auto event = window.pollEvent())
        {
            const sf::Event::KeyPressed* currentInputKey = event->getIf<sf::Event::KeyPressed>();
            const sf::Event::MouseButtonPressed* currentInputMouse = event->getIf<sf::Event::MouseButtonPressed>();


            bool Playclick = Rect1->DetectOnClick(currentInputMouse);
            bool Quitclick = Rect2->DetectOnClick(currentInputMouse);
            if (Playclick) {
                Rect1->OnClick(new PlayParams(TestScene));
            }
            if (Quitclick) {
                Rect2->OnClick(new QuitParams(&window));
            }

            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }



       /* window.clear();
        if (TestScene->currentScene == Menu) {
            rect9.draw(window);
            Rect1->draw(window);
            Rect2->draw(window);
        }*/
        if (TestScene->currentScene == Menu) {
            rect8.draw(window);
            rect7.draw(window);
            rect.draw(window);
            rect2.draw(window);
            rect3.draw(window);
            rect4.draw(window);
            rect5.draw(window);

           /* if (LastScene != TestScene->currentScene) {*/
                if (MyBT == nullptr) {
                    MyBlackBoard = new NPCBlackBoard(&rect5);
                    MyBT = new NPCBehaviorTree(MyBlackBoard);
                    MyBT->BuildTree();
                }
                Clock BTClock = Clock(true);
                MyBT->BeginExecute();
                BTClock.Restart();
           /* }*/
            /*LastScene = TestScene->currentScene;*/
            float DeltaTime = BTClock.GetElapsedTime();
            if (MyBT != nullptr) {
                MyBT->Tick(DeltaTime);
            }
            
            
        }
        
        // Update the window
        window.display();
    }
}