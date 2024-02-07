#ifndef DEEPMINER_ROBOT_H
#define DEEPMINER_ROBOT_H

#include "../GameWorld/GameWorld.h"

class Robot
{
    public:
    Robot(GameWorld* gameWorld);

    Robot();

    virtual ~Robot() {};

        virtual void mine() = 0;

        int getX() const;
        int getY() const;
        int getZ() const;

        int getPoints() const;

        void setX(int x);
        void setY(int y);

        void setLastX(int x);
        void setLastY(int y);
       
        bool checkForEffect1();
        bool checkForEffect2();
        bool checkForEffect3();

        void prevent_mine();
        void teleportToLowestValue();
        void doublePoints();


    protected:
        int x;
        int y;
        int z;

        int lastX;
        int lastY;
        int lastZ;

        int points;

        char field_value;

        GameWorld* gameWorld;
};


#endif //DEEPMINER_ROBOT_H
