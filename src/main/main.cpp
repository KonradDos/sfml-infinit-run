////////////////////////////////////////////////////
/// SFML 2.3.2 
/// C++ 11
////////////////////////////////////////////////////

#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    //Render Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Infiniter Run", sf::Style::Default);

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

        ///Section responsible for displaying every single frame
        //Clear front buffer and fill it white color
        window.clear(sf::Color::White);

        //Display rendered frame
        window.display();
    }

    return 0;
}
