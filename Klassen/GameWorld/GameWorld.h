#ifndef DEEPMINER_GAMEWORLD_H
#define DEEPMINER_GAMEWORLD_H
#include <vector>

using namespace std;

class GameWorld
{
    public:
    GameWorld() : field(5, vector<vector<char>>(5, vector<char>(10))) {}
    ~GameWorld() {};

    void initField();
    void printField();

    void setField(int x, int y, int z, char value);
    char getField(int x, int y, int z) const;

    void randomizeField();
    void sortFieldASC();
    void sortFieldDESC();

    void addEffectValues();
    bool checkForWin();

    private:
        vector<vector<vector<char>>> field;
};

#endif //DEEPMINER_GAMEWORLD_H
