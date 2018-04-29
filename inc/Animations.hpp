#ifndef Animations_hpp
#define Animations_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>

class Animations {
    public:
        Animations(const sf::Texture &texture, int numberOfRows, int numerOfImagesInARow, float durationBetweenTexChange);
        
        void updateTexture(sf::IntRect &rect, sf::RectangleShape &character);
        void updateCurrentTime(float currentTime);

    private:
        sf::Texture texture;

        const int numberOfImagesInARow;
        const int numberOfRows;

        int currentRow;
        int currentRowImage;
        int textureUnitHeight;
        int textureUnitWidth;
        
        float timeDurationBetweenTexChange;
        float currentTime;
};

#endif