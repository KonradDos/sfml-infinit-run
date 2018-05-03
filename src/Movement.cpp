#include "Movement.hpp"

Movement::Movement(int acceleration, int baseSpeed, int baseYPosition, int maxJumpHeight) :
    acceleration(acceleration), baseYPosition(baseYPosition), currentYPosition(baseYPosition), maxJumpHeight(maxJumpHeight),
    currentSpeed(acceleration), baseSpeed(baseSpeed) {} 

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
            this->currentYPosition -= 4*this->acceleration;
            return -4*this->acceleration;
        } 
    } else if(this->goesDown) {
        if(this->currentYPosition >= this->baseYPosition) {
            this->goesDown = false;
            return 0;
        } else {
            this->currentYPosition += this->acceleration * 4;
            return this->acceleration * 4;
        }
    }
}

int Movement::updateXPosition(int position) {

    if(position != 0 && position != tmp && position % 1000 == 0) this->currentSpeed += this->acceleration;

    this->tmp = position;
    return this->currentSpeed;
}

void Movement::resetStatus(){
    this->goesDown = false;
    this->goesUp = false;
    this->currentSpeed = this->baseSpeed;
}