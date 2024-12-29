#ifndef SIMULATION_H
#define SIMULATION_H

#pragma once
#include "Grid.h"

// The Simulation class manages the state and rules of the simulation
class Simulation
{
public:
    Simulation(int width, int height, int cellsize)
        : grid(width, height, cellsize), tempgrid(width, height, cellsize), run(false) {
    }

    // Draws the current state of the grid
    void Draw();

    // Sets the value of a specific cell
    void setcellvalue(int row, int column, int value);

    // Counts the number of live neighbors around a specific cell
    int countliveneighours(int row, int column);

    // Updates the state of the simulation based on the rules
    void update();

    // Checks if the simulation is running
    bool isrunning() { return run; }

    // Starts the simulation
    void start() { run = true; }

    // Stops the simulation
    void stop() { run = false; }

    // Clears the grid to its initial state
    void cleargrid();

    // Creates a random state in the grid
    void createrandomstate();

    // Toggles the state of a specific cell
    void togglecell(int row, int column);

private:
    Grid grid;      // The main grid
    Grid tempgrid;  // Temporary grid used for updates
    bool run;       // Indicates whether the simulation is running
};

#endif // SIMULATION_H
