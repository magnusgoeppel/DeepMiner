#include <iostream>
#include <unordered_map>
#include <functional>
#include <limits>
#include <random>
#include "GameManager.h"
#include "../GameWorld/GameWorld.h"
#include "../Robot/Robot1/Robot1.h"
#include "../Robot/Robot2/Robot2.h"
#include "../Robot/Robot3/Robot3.h"

using namespace std;

GameManager::GameManager()
{
    gameWorld = new GameWorld();
    startGame();
}

GameManager::~GameManager()
{
    delete gameWorld;
    delete robot;
}

void GameManager::startGame()
{
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                          Willkommen im Deep Miner                                                                                                      " << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    cin.get();
    system("cls");

    chooseRobot();

    gameWorld -> initField();
    gameWorld -> setField(robot -> getX(), robot -> getY(), robot -> getZ(), 'R');
    gameWorld -> printField();

    moveRobot();
}

unordered_map<int, function<Robot*()>> GameManager::createRobots()
{
    unordered_map<int, function<Robot *()>> robots =
            {
                    {1, [this]() { return new Robot1(gameWorld); }},
                    {2, [this]() { return new Robot2(gameWorld); }},
                    {3, [this]() { return new Robot3(gameWorld); }},
            };
    return robots;
}

void GameManager::chooseRobot()
{
    int chooseRobot;
    cout << "Waehle einen Roboter aus: (1, 2, 3)" << endl;
    cin >> chooseRobot;

    auto robots = createRobots();
    auto it = robots.find(chooseRobot);

    if (it != robots.end())
    {
        robot = it -> second();
    }
    else
    {
        cout << "Falsche Eingabe!" << endl;
        this -> chooseRobot();
    }
    system("cls");
}

void GameManager::moveRobot()
{
    while (true)
    {
        if(gameWorld -> checkForWin())
        {
            cout << "Punkte: " << robot -> getPoints() << endl << endl;
            cout << "Der Roboter hat alle Felder abgebaut" << endl;
            break;
        }

        cout << "Punkte: " << robot -> getPoints() << endl;
        char direction;
        cout << "In welche Richtung soll der Roboter bewegt werden? (w, a, s, d)" << endl;
        cin >> direction;

        bool moveSuccessful = false;

        unordered_map<char, function<void(Robot&)>> move =
        {
            {'w', [&moveSuccessful](Robot& robot)
                  {
                      if (robot.getY() > 0)
                      {
                          robot.setLastX(robot.getX());
                          robot.setLastY(robot.getY());
                          robot.setY(robot.getY() - 1);
                          moveSuccessful = true;
                      }
                      else
                      {
                          cout << "Der Roboter kann nicht weiter nach oben gehen!" << endl;
                          cin.get();
                      }
                  }},
            {'a', [&moveSuccessful](Robot& robot)
                  {
                      if (robot.getX() > 0)
                      {
                          robot.setLastX(robot.getX());
                          robot.setLastY(robot.getY());
                          robot.setX(robot.getX() - 1);
                          moveSuccessful = true;
                      }
                      else
                      {
                          cout << "Der Roboter kann nicht weiter nach links gehen!" << endl;
                          cin.get();
                      }
                  }},
            {'s', [&moveSuccessful](Robot& robot)
                  {
                      if (robot.getY() < 4)
                      {
                          robot.setLastX(robot.getX());
                          robot.setLastY(robot.getY());
                          robot.setY(robot.getY() + 1);
                          moveSuccessful = true;
                      }
                      else
                      {
                          cout << "Der Roboter kann nicht weiter nach unten gehen!" << endl;
                          cin.get();
                      }
                  }},
            {'d', [&moveSuccessful](Robot& robot)
                  {
                      if (robot.getX() < 4)
                      {
                          robot.setLastX(robot.getX());
                          robot.setLastY(robot.getY());
                          robot.setX(robot.getX() + 1);
                          moveSuccessful = true;
                      }
                      else
                      {
                          cout << "Der Roboter kann nicht weiter nach rechts gehen!" << endl;
                          cin.get();
                      }
                  }}
        };
        cin.get();

        auto it = move.find(direction);

        if (it != move.end())
        {
            it -> second(*robot);

            cout << it -> first << endl;

            if (moveSuccessful)
            {
                robot->mine();
            }
        }
        else
        {
            cout << "Falsche Eingabe!" << endl;
            cin.get();
            system("cls");
            gameWorld -> printField();
            continue;
        }

        if (robot -> getPoints() % 50 == 0)
        {
            changeField();
        }

        system("cls");
        gameWorld -> printField();
    }
}

void GameManager::changeField()
{
    // Erstelle einen Standard-Zufallszahlengenerator
    default_random_engine generator;

    // Erstelle eine gleichmäßige Verteilung von Ganzzahlen im Bereich [1, 3]
    uniform_int_distribution<int> distribution(0, 2);

    // Generiere eine zufällige Ganzzahl im Bereich [1, 3]
    int random_number = distribution(generator);

    // Erstelle einen Vektor mit Funktionszeigern, der auf die Funktionen zeigt
    vector<function<void()>> functions =
    {
            [&]() { gameWorld->randomizeField(); },
            [&]() { gameWorld->sortFieldASC(); },
            [&]() { gameWorld->sortFieldDESC(); },
    };

    // Rufe die ausgewählte Funktion basierend auf der generierten Zufallszahl auf
    functions[random_number]();
}

