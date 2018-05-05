#ifndef Movement_hpp
#define Movement_hpp

#include <SFML/Graphics.hpp>

class Movement {
    public:
        Movement(int acceleration, int baseSpeed, int baseYPosition, int maxJumpHeight);
        ~Movement();

        int updateYPosition();
        int updateXPosition(int position);
        
        bool getGoesUpStatus() const;
        bool getGoesDownStatus() const;

        void Jump();
        void resetStatus();

    private:
        const int acceleration;
        const int baseYPosition;
        const int baseSpeed;

        int currentSpeed;
        int currentYPosition;
        int maxJumpHeight;

        bool goesUp = false;
        bool goesDown = false;

        int tmp = 0;
};

#endif
