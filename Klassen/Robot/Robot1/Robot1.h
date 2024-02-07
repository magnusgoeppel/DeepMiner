#ifndef DEEPMINER_ROBOT1_H
#define DEEPMINER_ROBOT1_H

#include "../Robot.h"

class Robot1 : public Robot
{
    public:
        using Robot::Robot;
        void mine() override;

    private:
};


#endif //DEEPMINER_ROBOT1_H
