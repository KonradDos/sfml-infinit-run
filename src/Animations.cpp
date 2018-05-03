#include "Animations.hpp"

Animations::Animations(const sf::Texture &texture, int numberOfRows, int imagesInARow, float durationBetweenTexChange) :
    texture(texture), numberOfImagesInARow(imagesInARow), numberOfRows(numberOfRows), timeDurationBetweenTexChange(durationBetweenTexChange) {
        this->textureUnitHeight = texture.getSize().y/numberOfRows;
        this->textureUnitWidth = texture.getSize().x/numberOfImagesInARow;
        this->currentTime = 0.0; 
        this->currentRow = 0;
        this->currentRowImage = 0;
}

void Animations::updateTexture(sf::IntRect &rect, sf::RectangleShape &character) {
    if(character.getPosition().y == 420){
        if(this->currentTime >= this->timeDurationBetweenTexChange) {
            if(this->currentRowImage <= this->numberOfImagesInARow ) {
                
                if(this->currentRowImage == this->numberOfImagesInARow && this->currentRow == this->numberOfRows -1) {
                    this->currentRowImage = 0;
                    this->currentRow = 0;   
                }
                else if(this->currentRowImage == this->numberOfImagesInARow) {
                    this->currentRowImage = 0;
                    this->currentRow++;
                } 

                rect.left = (this->textureUnitWidth * this->currentRowImage);
                rect.top = (this->textureUnitHeight * this->currentRow);
                rect.width = this->textureUnitWidth;
                rect.height = this->textureUnitHeight;       

                this->currentRowImage++;
            } 
        }
    }
}

void Animations::updateCurrentTime(float currentTime) {
    this->currentTime = currentTime;
}