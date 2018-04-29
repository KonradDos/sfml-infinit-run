#include "WallsRepositioning.hpp"

void wallsRepositioning(sf::RectangleShape &wall, const sf::RectangleShape & character, double windowWidth) {
    
    if(wall.getPosition().x < character.getPosition().x - 10)
        wall.setPosition(character.getPosition().x + windowWidth + ((std::rand() % 1000 ) + 1), wall.getPosition().y);

}
