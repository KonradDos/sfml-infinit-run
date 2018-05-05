#include <boost/test/unit_test.hpp>
#include "CollisionDetection.hpp"
#include <SFML/Graphics.hpp>

BOOST_AUTO_TEST_CASE( IS_COLLISION_DETECTED ) 
{
    sf::RectangleShape character(sf::Vector2f(50, 100));
    character.setPosition(0, 0);

    sf::RectangleShape wall(sf::Vector2f(50, 100));
    wall.setPosition(0, 0);

    BOOST_TEST(CollisionDetection(character, wall));
}

BOOST_AUTO_TEST_CASE( IS_COLLISION_NOT_DETECTED ) 
{
    sf::RectangleShape character(sf::Vector2f(50, 100));
    character.setPosition(0, 0);

    sf::RectangleShape wall(sf::Vector2f(50, 100));
    wall.setPosition(0, 101);

    BOOST_TEST(!CollisionDetection(character, wall));
}