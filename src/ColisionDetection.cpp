#include "ColisionDetection.hpp"

bool colisionDetection(sf::RectangleShape &character, sf::RectangleShape &wall) {
    
        if(character.getPosition().x >= wall.getPosition().x - (wall.getSize().x/2)
                && character.getPosition().x <= wall.getPosition().x + (wall.getSize().x/2)
                && character.getPosition().y + character.getSize().y > wall.getPosition().y){

                return true;
        } 
}