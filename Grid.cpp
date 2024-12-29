#include <raylib.h>
#include "Grid.h"

// Draws the grid
void Grid::Draw()
{
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{ 0, 255, 0, 255 } : Color{ 55, 55, 55, 255 };
            DrawRectangle(column * cellsize, row * cellsize, cellsize - 1, cellsize - 1, color);
        }
    }
}

// Sets the value of a specific cell
void Grid::setvalue(int row, int column, int value)
{
    if (iswithinbounds(row, column)) {
        cells[row][column] = value;
    }
}

// Gets the value of a specific cell
int Grid::getvalue(int row, int column)
{
    if (iswithinbounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}

// Checks if the given cell is within the grid bounds
bool Grid::iswithinbounds(int row, int column)
{
    return row >= 0 && row < rows && column >= 0 && column < columns;
}

// Fills the grid with random values
void Grid::fillrandom()
{
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int randomValue = GetRandomValue(0, 4);
            cells[row][column] = (randomValue == 4) ? 1 : 0;
        }
    }
}

// Clears the grid to its initial state
void Grid::clear()
{
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cells[row][column] = 0;
        }
    }
}

// Toggles the value of a specific cell
void Grid::togglecell(int row, int column)
{
    if (iswithinbounds(row, column)) {
        cells[row][column] = !cells[row][column];
    }
}
