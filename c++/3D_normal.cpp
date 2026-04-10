#include "raylib.h"
#include <iostream>
#include <random>
#include "3D_utils.hpp"

using namespace std;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type


    DisableCursor();                    // Limit cursor to relative movement inside the window
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    int n = 400;
    int mean = 0;
    int std = 2;
    // vector<vector<float>> nor = norm(n, mean, std);
    
    vector<vector<float>> grid = calc_normal_grid(n);


    mt19937 rng2(random_device{}());
    normal_distribution<float> dist2(mean, 5);

    for (int k = 0; k < n; k++)
    {
        float x = dist2(rng2);
        float y = dist2(rng2);
        float z = dist2(rng2);

        for (int j = 0; j < grid.size(); j++)
        {
            float start = grid.at(j).at(0);
            float end = grid.at(j).at(1);
            cout << "start: " << start << endl;
            cout << "end: " << end << endl;
            cout << "x: " << x << endl;
            
            if (x >= start && x < end) {grid.at(j).at(2) += 1; cout << "bingo, x = " << x << endl;}
            if (y >= start && y < end) {grid.at(j).at(3) += 1; cout << "bingo, x = " << x << endl;}
            if (z >= start && z < end) {grid.at(j).at(4) += 1; cout << "bingo, x = " << x << endl;}

            cout << endl;
        }
        
    }
    
    // for (int i = 0; i < grid.size(); i++)
    // {
    //     cout << grid.at(i).at(2) << endl;
    // }

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

            ClearBackground(BLACK);

            BeginMode3D(camera);

                
                DrawGrid(10, 1.0f);
                // for (int i = 0; i < n; i++)
                // {
                //     // DrawSphere({nor.at(0).at(i), nor.at(1).at(i), 0}, 0.2, Color(GREEN));
                // }

                for (int i = 0; i < grid.size(); i++)
                {
                    for (int j = 0; j < grid.at(i).at(2); j++)
                    {
                        DrawCircle3D({grid.at(i).at(0), static_cast<float>(j), 0}, 0.5, {0,0,0}, 0, Color(GREEN));
                    }
                    for (int j = 0; j < grid.at(i).at(2); j++)
                    {
                        DrawCircle3D({grid.at(i).at(0), static_cast<float>(-j), 0}, 0.5, {0,0,0}, 0, Color(GREEN));
                    }
                    for (int k = 0; k < grid.at(i).at(3); k++)
                    {
                            DrawCircle3D({grid.at(i).at(0), 0, static_cast<float>(k)}, 0.5, {0,0,0}, 0, Color(GREEN));
                    }
                    for (int u = 0; u < grid.at(i).at(4); u++)
                    {
                            DrawCircle3D({grid.at(i).at(0), 0, static_cast<float>(-u)}, 0.5, {0,0,0}, 0, Color(GREEN));
                    }
                }

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
