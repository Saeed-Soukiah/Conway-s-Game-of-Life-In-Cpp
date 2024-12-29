#ifndef GRID_H
#define GRID_H

#pragma once
#include <vector>

// The Grid class represents the grid of cells in the simulation
class Grid
{
public:
    Grid(int width, int height, int cellsize)
        : rows(height / cellsize), columns(width / cellsize), cellsize(cellsize), cells(rows, std::vector<int>(columns, 0)) {
    }

    // Draws the grid
    void Draw();

    // Sets the value of a specific cell
    void setvalue(int row, int column, int value);

    // Gets the value of a specific cell
    int getvalue(int row, int column);

    // Checks if the given cell is within the grid bounds
    bool iswithinbounds(int row, int column);

    // Gets the number of rows in the grid
    int getrows() { return rows; }

    // Gets the number of columns in the grid
    int getcolumns() { return columns; }

    // Fills the grid with random values
    void fillrandom();

    // Clears the grid to its initial state
    void clear();

    // Toggles the value of a specific cell
    void togglecell(int row, int column);

private:
    int rows;                          // Number of rows in the grid
    int columns;                       // Number of columns in the grid
    int cellsize;                      // Size of each cell
    std::vector<std::vector<int>> cells; // 2D vector representing the grid cells
};

#endif // GRID_H
