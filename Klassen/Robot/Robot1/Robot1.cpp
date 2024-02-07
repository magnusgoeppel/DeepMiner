#include <iostream>
#include "Robot1.h"

using namespace std;

void Robot1::mine()
{
    gameWorld -> setField(lastX, lastY, lastZ, field_value); // Setze das letzte Feld auf den gespeicherten Wert

    if (checkForEffect1())
    {
        prevent_mine();
        return;
    }

    // Führe den normalen Ablauf der mine()-Funktion aus
    for (int z = 9; z >= 0; --z)
    {
        if(gameWorld ->getField(lastX, lastY, z) == '.')
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


