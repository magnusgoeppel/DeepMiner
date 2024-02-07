#ifndef DEEPMINER_ROBOT3_H
#define DEEPMINER_ROBOT3_H

#include "../Robot.h"


class Robot3 : public Robot
{
    public:
        using Robot::Robot;
        void mine() override;

private:
};

#endif //DEEPMINER_ROBOT3_H
