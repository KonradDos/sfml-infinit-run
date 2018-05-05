////////////////////////////////////////////////////
/// SFML 2.3.2 
/// C++ 11
////////////////////////////////////////////////////
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "CollisionDetection.hpp"
#include "WallsRepositioning.hpp"
#include "Movement.hpp"
#include "Animations.hpp"
#include "InitialValues.hpp"

int main() {

    //Render Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infinite Run", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    //Add textures
    sf::Texture runTexture;
    if(!runTexture.loadFromFile("/home/konrad/Documents/c++/githubupdate/sfml-infinit-run/images/run.png")){
        std::cout << "Cannot Load The Run Texture." << std::endl;
    }

    sf::Texture treeTexture;
    if(!treeTexture.loadFromFile("/home/konrad/Documents/c++/githubupdate/sfml-infinit-run/images/baum.png")){
        std::cout << "Cannot Load The Run Texture." << std::endl;
    }

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("/home/konrad/Documents/c++/githubupdate/sfml-infinit-run/images/cf.png")){
        std::cout << "Cannot Load The Run Texture." << std::endl;
    }

    //Load Font
    sf::Font font;
    if(!font.loadFromFile("/usr/share/vlc/skins2/fonts/FreeSansBold.ttf")) {
        std::cout << "Cannot Load The Font" << std::endl;
    }

    //Create text
    sf::Text gameOverText("P - Play again \nQ - Quit", font);
    gameOverText.setCharacterSize(40);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setColor(sf::Color::Blue);
    gameOverText.setPosition(300, 900);

    //Background
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    background.scale(2, 1);
    
    //Character Declaration
    sf::RectangleShape character(sf::Vector2f(50, 100));
    character.setFillColor(sf::Color(sf::Color::White));
    character.setTexture(&runTexture);

    //Walls Declaration
    sf::RectangleShape wall1(sf::Vector2f(25, 70));
    wall1.setFillColor(sf::Color::White);
    wall1.setTexture(&treeTexture);

    sf::RectangleShape wall2(sf::Vector2f(25, 50));
    wall2.setFillColor(sf::Color::White);
    wall2.setTexture(&treeTexture);

    sf::RectangleShape wall3(sf::Vector2f(45, 60));
    wall3.setFillColor(sf::Color::White);
    wall3.setTexture(&treeTexture);

    //Views configuartion
    sf::View baseView(sf::FloatRect(sf::Vector2f(character.getPosition().x-100, 0), sf::Vector2f(800, 600)));
    
    sf::View gameOver(sf::FloatRect(sf::Vector2f(300, 900), sf::Vector2f(800, 600)));
    
    //Movement
    Movement m1(1, 3, 420, 200);

    //Animations
    sf::IntRect rect(0,0,0,0);
    Animations runAnimation(runTexture, 2, 5, 0.1);
    
    //Clock
    sf::Clock animationClock;
    sf::Time animationTimeCoefficent;

    InitialValues(baseView, background, character, wall1, wall2, wall3, m1);

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
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {

            window.setView(baseView);
            InitialValues(baseView, background, character, wall1, wall2, wall3, m1);

        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            window.close();
        }

        //Collision Detection
        if( CollisionDetection(character, wall1) ||  CollisionDetection(character, wall2) ||
            CollisionDetection(character, wall3) ) {

            window.setView(gameOver);

        } else if(window.getView().getCenter().y != 1200) {
            window.setView(baseView);      
        }

        //Walls Repositioning
        wallsRepositioning(wall1, character, window.getSize().x);
        wallsRepositioning(wall2, character, window.getSize().x);
        wallsRepositioning(wall3, character, window.getSize().x);

        //Update Animations
        animationTimeCoefficent = animationClock.getElapsedTime();
        runAnimation.updateCurrentTime(animationTimeCoefficent.asSeconds());
        runAnimation.updateTexture(rect, character);
        character.setTextureRect(rect);
        
        if(animationTimeCoefficent.asSeconds() >= 0.1)
            animationClock.restart();

        //Move Background
        background.move(m1.updateXPosition(character.getPosition().x), 0);

        //Move Character
        character.move(m1.updateXPosition(character.getPosition().x), m1.updateYPosition());
        //Move View
        baseView.move(m1.updateXPosition(character.getPosition().x), 0);

        ///Section responsible for displaying every single frame
        //Clear front buffer and fill it white color
        window.clear(sf::Color::White);

        //Draw character and walls
        window.draw(background);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(character);
        window.draw(gameOverText);
        
        //Display rendered frame
        window.display();
    }

    return 0;
}   