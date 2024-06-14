# Deep Miner

Deep Miner is a simulated mining game where players control a robot to extract resources in a three-dimensional playing field. The goal of the game is to mine all available resources while overcoming various challenges.

## Game Description

At the start of the game, the player chooses one of three different robots, each with unique abilities. The playing field is a three-dimensional grid with hidden resources. Players must strategically mine resources efficiently, collect points, and achieve the game objectives.

## Structure

The project is divided into several modules:

- **GameManager**: Manages the game flow, including initializing the game and controlling the game cycle.
- **GameWorld**: Responsible for rendering the playing field and managing the game logic.
- **Robot**: An abstract base class for the robots controlled by players.
- **Robot1**, **Robot2**, **Robot3**: Specializations of the Robot class, each implementing different abilities and strategies for the game.

## Requirements

- C++ Compiler

## Game Instructions

- **Robot Selection**: At the beginning of the game, choose one of three robots. Each robot has unique abilities.
- **Navigation**: Move the robot through the playing field to mine resources. Use the control commands (w, a, s, d) for movement.
- **Resource Mining**: The goal is to mine all available resources efficiently and collect points.
- **Special Tiles**: Watch out for special tiles with unique effects:
    - **Effect Tile '1'**: Prevents mining in the current round.
    - **Effect Tile '2'**: Teleports the robot to the lowest value on the playing field.
    - **Effect Tile '3'**: Doubles the robot's points.
- **Game Objective**: The aim of the game is to mine all tiles and achieve the highest possible score.
