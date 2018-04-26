#include "ColisionDetection.hpp"

void colisionDetection(sf::RectangleShape &character, sf::RectangleShape &wall) {
    
    if(character.getPosition().x >= wall.getPosition().x - (wall.getSize().x/2) &&
        character.getPosition().x <= wall.getPosition().x - (wall.getSize().x/2) &&
        character.getPosition().y >= wall.getPosition().y - (wall.getSize().y)) {
                
                std::cout << "Character X: " << character.getPosition().x << ", Wall Position X: " << wall.getPosition().x 
                        << ", Character Y: " << character.getPosition().y << ", Wall Position Y: " << wall.getPosition().y << std::endl;
        }

}