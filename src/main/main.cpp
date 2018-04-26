////////////////////////////////////////////////////
/// SFML 2.3.2 
/// C++ 11
////////////////////////////////////////////////////

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ColisionDetection.hpp"
#include "WallsRepositioning.hpp"

int main() {

    //Render Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infiniter Run", sf::Style::Default);
    window.setFramerateLimit(150);

    //View configuartion
    sf::View baseView(sf::FloatRect(sf::Vector2f(-100, 0), sf::Vector2f(800, 600)));
    
    sf::Event event;

    //Character Declaration
    sf::RectangleShape character(sf::Vector2f(50, 100));
    character.setFillColor(sf::Color(sf::Color::Red));
    character.setPosition(0, 420);

    //Walls Declaration
    sf::RectangleShape wall1(sf::Vector2f(50, 100));
    wall1.setFillColor(sf::Color::Green);
    wall1.setPosition(0, 420);

    sf::RectangleShape wall2(sf::Vector2f(50, 100));
    wall2.setFillColor(sf::Color::Blue);
    wall2.setPosition(0, 420);

    sf::RectangleShape wall3(sf::Vector2f(50, 100));
    wall3.setFillColor(sf::Color::Black);
    wall3.setPosition(0, 420);

    //Main game loop
    while(window.isOpen()){

        //Events handle loop
        while(window.pollEvent(event)) {

            switch(event.type) {

                case sf::Event::Closed: window.close();
                    break;

                default:
                    break; 

            }

        }

        // Setting up view
        window.setView(baseView);

        ///Section responsible for displaying every single frame
        //Clear front buffer and fill it white color
        window.clear(sf::Color::White);

        //Colision Detection
        colisionDetection(character, wall1);  
        colisionDetection(character, wall2);       
        colisionDetection(character, wall3);       

        //Walls Repositioning
        wallsRepositioning(wall1, character, window.getSize().x);
        wallsRepositioning(wall2, character, window.getSize().x);
        wallsRepositioning(wall3, character, window.getSize().x);
        
        //Draw character and walls
        window.draw(character);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);

        //Move Character
        character.move(1, 0);

        //Move View
        baseView.move(1, 0);

        //Display rendered frame
        window.display();
    }

    return 0;
}
