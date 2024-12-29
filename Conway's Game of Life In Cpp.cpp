/* 
* Game of Life Simulation * 
* This program simulates Conway's Game of Life using a grid of cells. 
* Users can interact with the simulation by toggling cells, starting, stopping, 
* and adjusting the speed of the simulation. 
* 
* Author: Saeed Soukiah
* Date: December 29, 2024 
*/

#include <iostream>
#include "raylib.h"
#include "Simulation.h"

int main()
{
    // Define the window color
    Color Grey = { 29, 29, 29, 255 };

    // Define the window dimensions and other constants
    const int Window_width = 750;
    const int Window_height = 750;
    const int cellsize = 25;
    int FPS = 12;

    // Initialize the window with specified width, height, and title
    InitWindow(Window_width, Window_height, "Game Of Life");

    // Set the target frames per second
    SetTargetFPS(FPS);

    // Create a Simulation object with the specified dimensions and cell size
    Simulation simulation(Window_width, Window_height, cellsize);

    // Main simulation loop, continues until the window should close
    while (!WindowShouldClose()) {
        // 1. Event Handling: Handling user input

        // Handle mouse button down event to toggle cells
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseposition = GetMousePosition(); // Get mouse position
            int row = mouseposition.y / cellsize; // Calculate row based on mouse y-position
            int column = mouseposition.x / cellsize; // Calculate column based on mouse x-position
            simulation.togglecell(row, column); // Toggle the cell at the specified position
        }

        // Handle key press events
        if (IsKeyPressed(KEY_ENTER)) {
            simulation.start(); // Start the simulation
            SetWindowTitle("Game of Life Is Running..."); // Update the window title
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            simulation.stop(); // Stop the simulation
            SetWindowTitle("Game of Life Is Stopped..."); // Update the window title
        }
        else if (IsKeyPressed(KEY_UP)) {
            FPS += 2; // Increase the frames per second
            SetTargetFPS(FPS); // Update the target FPS
            std::cout << FPS << std::endl; // Print the new FPS value to the console
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            if (FPS > 5) {
                FPS -= 2; // Decrease the frames per second
                SetTargetFPS(FPS); // Update the target FPS
                std::cout << FPS << std::endl; // Print the new FPS value to the console
            }
        }
        else if (IsKeyPressed(KEY_R)) {
            simulation.createrandomstate(); // Create a random state in the grid
        }
        else if (IsKeyPressed(KEY_C)) {
            simulation.cleargrid(); // Clear the grid
        }

        // 2. Update State: Update the simulation state
        simulation.update();

        // 3. Drawing Objects: Draw the current state of the simulation
        BeginDrawing(); // Begin drawing
        ClearBackground(Grey); // Clear the background with the specified color
        simulation.Draw(); // Draw the simulation grid
        EndDrawing(); // End drawing
    }

    // Close the window and terminate the application
    CloseWindow();
}
