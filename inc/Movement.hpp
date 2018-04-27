#ifndef Movement_hpp
#define Movement_hpp

class Movement {
    public:
        Movement(int acceleration, int baseYPosition, int maxJumpHeight);
        ~Movement();

        int updateYPosition();
        int updateXPosition();
        
        void Jump();
        
        bool getGoesUpStatus() const;
        bool getGoesDownStatus() const;

    private:
        const int acceleration;
        const int baseYPosition;

        int currentYPosition;
        int maxJumpHeight;

        bool goesUp = false;
        bool goesDown = false;
};

#endif
