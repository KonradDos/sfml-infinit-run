#include "InitialValues.hpp"

void InitialValues(sf::View &view, sf::Sprite &background, sf::RectangleShape &character, 
    sf::RectangleShape &wall1, sf::RectangleShape &wall2, sf::RectangleShape &wall3,
    Movement &movement) {

        //Set Background Default Position And Scale
        background.setPosition(-100, -270);
        // background.scale(2, 1);

        //Set Main Character Default Position
        character.setPosition(0, 420);

        //Set View Default Position
        view.setCenter(character.getPosition().x + 300, 300); 

        //Set Walls Default Positions
        wall1.setPosition(-90, 450);

        wall2.setPosition(-90, 470);

        wall3.setPosition(-90, 460);

        //Reset Movement Status
        movement.resetStatus();
}
