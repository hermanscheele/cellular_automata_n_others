#include "raylib.h"
#include "BM_3D_utils.hpp"
#include <thread>
#include <chrono>


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type


    DisableCursor();                    // Limit cursor to relative movement inside the window
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    int n_steps = 1000;
    int n_paths = 10;
    double dt = 0.02;

    vector<vector<vector<float>>> paths = brownian_motion(n_steps, n_paths, dt); 

    vector<Color> colors = {Color(RED), Color(GREEN), Color(BLUE), Color(BLACK), Color(ORANGE)};




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

                for (int i = 0; i < n_paths; i++)
                {   
                    float t_step = 0.f;
                    
                    for (int j = 1; j < n_steps; j++)
                    {   
                        Vector3 start_pos = {t_step, paths.at(i).at(j-1).at(0), paths.at(i).at(j-1).at(1)};
                        t_step += dt;
                        Vector3 end_pos = {t_step, paths.at(i).at(j).at(0), paths.at(i).at(j).at(1)};

                        DrawLine3D(start_pos, end_pos, colors.at(i % colors.size()));
                    }
                }            
                
                DrawGrid(10, 1.0f);

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