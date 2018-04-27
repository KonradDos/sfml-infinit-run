#include "Movement.hpp"

Movement::Movement(int acceleration, int baseYPosition, int maxJumpHeight) :
    acceleration(acceleration), baseYPosition(baseYPosition), currentYPosition(baseYPosition), maxJumpHeight(maxJumpHeight) {} 

Movement::~Movement() {}

void Movement::Jump() {
    this->goesUp = true;
}

bool Movement::getGoesUpStatus() const {
    return this->goesUp;
}

bool Movement::getGoesDownStatus() const {
    return this->goesDown;
}

int Movement::updateYPosition() {

    if(this->goesUp) {
        if(this->currentYPosition <= this->baseYPosition - this->maxJumpHeight) {
            this->goesUp = false;
            this->goesDown = true;
            return 0;
        } else {
            this->currentYPosition -= this->acceleration;
            return -2*this->acceleration;
        } 
    } else if(this->goesDown) {
        if(this->currentYPosition >= this->baseYPosition) {
            this->goesDown = false;
            return 0;
        } else{
            this->currentYPosition += this->acceleration;
            return this->acceleration*2;
            }
    }
}
