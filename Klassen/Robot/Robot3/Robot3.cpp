#include <iostream>
#include "Robot3.h"

using namespace std;

void Robot3::mine()
{
    gameWorld -> setField(lastX, lastY, lastZ, field_value);

    if (checkForEffect1())
    {
        prevent_mine();
        return;
    }

    for (int z = 0; z <= 9; ++z)
    {
        if(gameWorld -> getField(lastX, lastY, z) == '.')
        {
            gameWorld -> setField(lastX, lastY, z, ' ');
            ++points;
            break;
        }
    }
    field_value = gameWorld->getField(x, y, z); // Speichere den aktuellen Feldwert
    if(checkForEffect2())
    {
        gameWorld -> setField(lastX, lastY, z, ' ');
        teleportToLowestValue();
    }
    else if(checkForEffect3())
    {
        doublePoints();
    }
    gameWorld->setField(x, y, z, 'R'); // Setze die Position des Roboters
}