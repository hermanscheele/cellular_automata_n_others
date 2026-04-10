#include <iostream>
#include <vector>
#include "3D_utils.hpp"
#include "raylib.h"
#include "utils.hpp"
#include <thread>
#include <chrono>

using namespace std;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 30.0f, 30.0f, 30.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type



    int n = 80;
    int count = (n * n) + 100;
    float cell_size = 0.6f;
    float border = 1.0f;

    // vector<Vector3> all_cube_pos = calc_cell_positions(n, border);
    // vector<Vector3> all_cube_pos = calc_cell_positions_2D(n, border);

    vector<vector<int>> grid = init_grid(n);
    fill_random(grid, count);

    render_grid(grid);




    DisableCursor();                    // Limit cursor to relative movement inside the window
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------



    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {   


                        float x = (i * border);
                        float y = j * border;
                        float z = 1.0f;

                        Vector3 pos = {y, x, z};
                        
                        if (grid[i][j] == 1)  DrawCube(pos, cell_size, cell_size, cell_size, GREEN);
                        else                  DrawCube(pos, cell_size, cell_size, cell_size, WHITE);
                    }
                }

            

                DrawGrid(10, 1);
                apply_rule(grid);
                // this_thread::sleep_for(chrono::milliseconds(150));

            EndMode3D();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}