#ifndef INITIALVALUES_HPP
#define INITIALVALUES_HPP

#include <SFML/Graphics.hpp>
#include "Movement.hpp"

void InitialValues(sf::View &view, sf::Sprite &background, sf::RectangleShape &character, 
    sf::RectangleShape &wall1, sf::RectangleShape &wall2, sf::RectangleShape &wall3, 
    Movement &movement);

#endif