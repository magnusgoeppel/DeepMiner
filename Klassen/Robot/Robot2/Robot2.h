#ifndef DEEPMINER_ROBOT2_H
#define DEEPMINER_ROBOT2_H

#include "../Robot.h"

class Robot2 : public Robot
{
    public:
        using Robot::Robot;
        void mine() override;

    private:
};


#endif //DEEPMINER_ROBOT2_H
