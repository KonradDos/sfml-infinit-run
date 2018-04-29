////////////////////////////////////////////////////
/// SFML 2.3.2 
/// C++ 11
////////////////////////////////////////////////////

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "ColisionDetection.hpp"
#include "WallsRepositioning.hpp"
#include "Movement.hpp"
#include "Animations.hpp"

int main() {

    //Render Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infiniter Run", sf::Style::Default);
    window.setFramerateLimit(150);
    window.setKeyRepeatEnabled(false);

    //View configuartion
    sf::View baseView(sf::FloatRect(sf::Vector2f(-100, 0), sf::Vector2f(800, 600)));
    
    //Add textures
    sf::Texture runTexture;
    if(!runTexture.loadFromFile("/home/konrad/Documents/c++/githubupdate/sfml-infinit-run/images/run.png")){
        std::cout << "Cannot Load The Run Texture." << std::endl;
    }

    //Character Declaration
    sf::RectangleShape character(sf::Vector2f(50, 100));
    character.setFillColor(sf::Color(sf::Color::White));
    character.setPosition(0, 420);
    character.setTexture(&runTexture);

    //Walls Declaration
    sf::RectangleShape wall1(sf::Vector2f(25, 70));
    wall1.setFillColor(sf::Color::Green);
    wall1.setPosition(0, 450);

    sf::RectangleShape wall2(sf::Vector2f(15, 50));
    wall2.setFillColor(sf::Color::Blue);
    wall2.setPosition(0, 470);

    sf::RectangleShape wall3(sf::Vector2f(45, 60));
    wall3.setFillColor(sf::Color::Black);
    wall3.setPosition(0, 460);

    //Movement
    Movement m1(1, 420, 200);

    //Animations
    sf::IntRect rect(0,0,0,0);
    Animations runAnimation(runTexture, 2, 5, 0.1);
    
    //Clock
    sf::Clock cloc;
    sf::Time t1;

    //Events handle
    sf::Event event;

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

        //Movment control
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(!m1.getGoesUpStatus() && !m1.getGoesDownStatus())        
                m1.Jump();

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // if(!m1.getGoesUpStatus() && m1.getGoesDownStatus())
            //     m1.updateYPosition();
        }

        // Setting up view
        window.setView(baseView);

        //Colision Detection
        colisionDetection(character, wall1);  
        colisionDetection(character, wall2);       
        colisionDetection(character, wall3);       

        //Walls Repositioning
        wallsRepositioning(wall1, character, window.getSize().x);
        wallsRepositioning(wall2, character, window.getSize().x);
        wallsRepositioning(wall3, character, window.getSize().x);

        //Move Character
        character.move(1, m1.updateYPosition());

        //Move View
        baseView.move(1, 0);

        //Update Animations
        t1 = cloc.getElapsedTime();
        runAnimation.updateCurrentTime(t1.asSeconds());
        runAnimation.updateTexture(rect, character);
        character.setTextureRect(rect);
        
        if(t1.asSeconds() >= 0.1)
            cloc.restart();

        ///Section responsible for displaying every single frame
        //Clear front buffer and fill it white color
        window.clear(sf::Color::White);

        //Draw character and walls
        window.draw(character);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);

        //Display rendered frame
        window.display();
    }

    return 0;
}