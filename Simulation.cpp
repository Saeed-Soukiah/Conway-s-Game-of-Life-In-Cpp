#include "Simulation.h"
#include <vector>
#include <utility>

// Draws the current state of the grid
void Simulation::Draw()
{
    grid.Draw();
}

// Sets the value of a specific cell
void Simulation::setcellvalue(int row, int column, int value)
{
    grid.setvalue(row, column, value);
}

// Counts the number of live neighbors around a specific cell
int Simulation::countliveneighours(int row, int column)
{
    int liveneighours = 0;
    std::vector<std::pair<int, int>> neighouroffsets = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (const auto& offset : neighouroffsets) {
        int neighbourrow = (row + offset.first + grid.getrows()) % grid.getrows();
        int neighbourcolumn = (column + offset.second + grid.getcolumns()) % grid.getcolumns();
        liveneighours += grid.getvalue(neighbourrow, neighbourcolumn);
    }
    return liveneighours;
}

// Updates the state of the simulation based on the rules
void Simulation::update()
{
    if (isrunning()) {
        for (int row = 0; row < grid.getrows(); row++) {
            for (int column = 0; column < grid.getcolumns(); column++) {
                int liveneighours = countliveneighours(row, column);
                int cellvalue = grid.getvalue(row, column);

                if (cellvalue == 1) {
                    // Cell dies if it has fewer than 2 or more than 3 live neighbors
                    tempgrid.setvalue(row, column, (liveneighours > 3 || liveneighours < 2) ? 0 : 1);
                }
                else {
                    // Cell becomes alive if it has exactly 3 live neighbors
                    tempgrid.setvalue(row, column, (liveneighours == 3) ? 1 : 0);
                }
            }
        }
        grid = tempgrid; // Update the grid with the new state
    }
}

// Clears the grid to its initial state
void Simulation::cleargrid()
{
    if (!isrunning()) {
        grid.clear();
    }
}

// Creates a random state in the grid
void Simulation::createrandomstate()
{
    if (!isrunning()) {
        grid.fillrandom();
    }
}

// Toggles the state of a specific cell
void Simulation::togglecell(int row, int column)
{
    grid.togglecell(row, column);
}
