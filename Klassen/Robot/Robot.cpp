#include <iostream>
#include "Robot.h"

Robot::Robot(GameWorld* gameWorld) : gameWorld(gameWorld)
{
    this -> x = 0;
    this -> y = 0;
    this -> z = 9;

    this -> lastX = 0;
    this -> lastY = 0;
    this -> lastZ = 9;

    this -> points = 0;

    field_value = '.';
}

void Robot::setX(int x)
{
    this -> x = x;
}

void Robot::setY(int y)
{
    this -> y = y;
}

int Robot::getX() const
{
    return x;
}

int Robot::getY() const
{
    return y;
}

int Robot::getZ() const
{
    return z;
}

void Robot::setLastX(int x)
{
    this -> lastX = x;
}

void Robot::setLastY(int y)
{
    this -> lastY = y;
}

int Robot::getPoints() const
{
    return points;
}

void Robot::prevent_mine()
{
    // Überprüfe, ob sich ein Effektwert an irgendeiner z-Koordinate der derzeitigen x- und y-Koordinaten des Roboters befindet.
    for (int z = 0; z <= 9; ++z)
    {
        char effectValue = gameWorld -> getField(lastX, lastY, z);

        if(effectValue == '1')
        {
            cout << "Der Robeter darf diese Runde keinen Wert abbauen.\n";
            // Lösche den alten Roboterstandort
            gameWorld -> setField(lastX, lastY, z, ' ');
            // Setze die Position des Roboters
            gameWorld->setField(x, y, this ->  z, 'R');
            cin.get();
            return;
        }
    }
};

void Robot::teleportToLowestValue()
{
    // Zurücksetzen des Effektfeldes
    for (int z = 0; z < 10; ++z)
    {
        if (gameWorld->getField(lastX, lastY, z) == '2')
        {
            gameWorld->setField(lastX, lastY, z, '.');
            break;
        }
    }

    int minX = 0, minY = 0;
    bool found = false;

    // Durchlaufen Sie das Spielfeld und finden Sie die erste Koordinate mit dem Wert '.' bei z = 9
    for (int x = 0; x < 5; ++x)
    {
        for (int y = 0; y < 5; ++y)
        {
            char currentValue = gameWorld->getField(x, y, 9);
            if (currentValue == '.')
            {
                minX = x;
                minY = y;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }

    // Aktualisieren Sie die Position des Roboters
    gameWorld->setField(lastX, lastY, lastZ, field_value);
    setX(minX);
    setY(minY);
    field_value = gameWorld->getField(minX, minY, lastZ);
    gameWorld->setField(minX, minY, lastZ, 'R');
}

void Robot::doublePoints()
{
    cout << "Die Punkte werden verdoppelt\n" << endl;
    points *= 2;
    cin.get();
}


// In der Robot-Klasse
bool Robot::checkForEffect1()
{
    for (int z = 0; z < 10; ++z)
    {
        if (gameWorld->getField(lastX, lastY, z) == '1')
        {
            return true;
        }
    }
    return false;
};

bool Robot::checkForEffect2()
{
    for (int z = 0; z < 10; ++z)
    {
        if (gameWorld->getField(lastX, lastY, z) == '2')
        {
            return true;
        }
    }
    return false;
};

bool Robot::checkForEffect3()
{
    for (int z = 0; z < 10; ++z)
    {
        if (gameWorld->getField(lastX, lastY, z) == '3')
        {
            return true;
        }
    }
    return false;
};
