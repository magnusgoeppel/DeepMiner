#ifndef DEEPMINER_GAMEMANAGER_H
#define DEEPMINER_GAMEMANAGER_H
#include "../GameWorld/GameWorld.h"
#include "../Robot/Robot.h"
#include <unordered_map>
#include <functional>

using namespace std;

class GameManager
{
    public:
        GameManager() ;
        ~GameManager();

        void startGame();
        void chooseRobot();
        void moveRobot();
        void changeField();

        unordered_map<int, function<Robot*()>> createRobots();

    private:
        GameWorld *gameWorld;
        Robot *robot;
};

#endif //UE04_DEEPMINER_GAMEMANAGER_H
