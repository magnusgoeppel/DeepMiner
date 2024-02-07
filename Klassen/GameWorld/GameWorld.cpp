#include <iostream>
#include <random>
#include "GameWorld.h"
#include "algorithm"

using namespace std;

void GameWorld::initField()
{
    for (int x = 0; x < field.size(); ++x)
    {
        for (int y = 0; y < field[x].size(); ++y)
        {
            fill(field[x][y].begin(), field[x][y].end(), '.');
        }
    }
    addEffectValues();
}

void GameWorld::printField()
{
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                Spielfeld                                                                                                               " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

    for (int z = 0; z < field[0][0].size(); ++z)
    {
        if (z == 1)
        {
            cout << " ";
        }
        cout << "Ebene " << z << "               ";
    }
    cout << endl;

    for (int y = 0; y < field[0].size(); ++y)
    {
        for (int z = 0; z < field[0][0].size(); ++z)
        {
            for (int x = 0; x < field.size(); ++x)
            {
                if (field[x][y][z] == '1' || field[x][y][z] == '2' || field[x][y][z] == '3')
                {
                    cout << "-";
                }
                else{
                    cout << " ";
                }
                cout << field[x][y][z] << " ";
            }
            // Wenn die Ebene nicht die letzte ist, dann wird ein Abstand von 5 Leerzeichen eingefügt
            if (z < field[0][0].size() - 1)
            {
                cout << "       ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void GameWorld::setField(int x, int y, int z, char value)
{
    field[x][y][z] = value;
}



char GameWorld::getField(int x, int y, int z) const
{
    if (x >= 0 && x < field.size() &&
        y >= 0 && y < field[0].size() &&
        z >= 0 && z < field[0][0].size())
    {
        return field[x][y][z];
    }
    else
    {
        throw out_of_range("Die angegebenen Koordinaten liegen außerhalb des Spielfelds.");
    }
}

void GameWorld::randomizeField()
{
    srand(time(NULL));

    for (int x = 0; x < 5; ++x)
    {
        for (int y = 0; y < 5; ++y)
        {
            // Mische die z-Werte zufällig
            shuffle(field[x][y].begin(), field[x][y].end(), default_random_engine(rand()));
        }
    }
}

void GameWorld::sortFieldASC()
{
    for (int x = 0; x < 5; ++x)
    {
        for (int y = 0; y < 5; ++y)
        {
            sort(field[x][y].begin(), field[x][y].end());
        }
    }
}

void GameWorld::sortFieldDESC()
{
    for (int x = 0; x < 5; ++x)
    {
        for (int y = 0; y < 5; ++y)
        {
            sort(field[x][y].begin(), field[x][y].end(), greater<char>());
        }
    }
}

void GameWorld::addEffectValues()
{
    // Zufallsgenerator initialisieren
    default_random_engine gen(std::random_device{}());
    uniform_int_distribution<int> dist(0, 4);
    uniform_int_distribution<int> effectDist(0, 2);

    // Vektor von möglichen Effektwerten
    vector<char> effectValues = {'1', '2', '3'};

    for (int i = 0; i < 10; ++i)
    {
        int x = dist(gen);
        int y = dist(gen);
        int z = dist(gen);
        char effectValue = effectValues[effectDist(gen)]; // -1, -2 oder -3 als Effektwert
        field[x][y][z] = effectValue;
    }
}

bool GameWorld::checkForWin()
{
        for (int x = 0; x < field.size(); ++x)
        {
            for (int y = 0; y < field[x].size(); ++y)
            {
                for (int z = 0; z < field[x][y].size(); ++z)
                {
                    if (field[x][y][z] == '.' || field[x][y][z] == '1' || field[x][y][z] == '2' || field[x][y][z] == '3')
                    {
                        return false;
                    }
                }
            }
        }
        return true;
};