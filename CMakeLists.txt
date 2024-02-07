cmake_minimum_required(VERSION 3.25)
project(DeepMiner)

set(CMAKE_CXX_STANDARD 20)

add_executable(DeepMiner main.cpp Klassen/GameManager/GameManager.h Klassen/GameManager/GameManager.cpp Klassen/Robot/Robot.h Klassen/GameWorld/GameWorld.cpp Klassen/GameWorld/GameWorld.h Klassen/Robot/Robot1/Robot1.cpp Klassen/Robot/Robot1/Robot1.h Klassen/Robot/Robot2/Robot2.cpp Klassen/Robot/Robot2/Robot2.h Klassen/Robot/Robot3/Robot3.cpp Klassen/Robot/Robot3/Robot3.h Klassen/Robot/Robot.cpp)
