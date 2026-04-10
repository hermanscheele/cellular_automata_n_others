#include <iostream>
#include <vector>
#include "include/3D_utils.hpp"
#include "include/utils.hpp"
#include "raylib.h"
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main(void)
{
    const int screenWidth  = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Cell Automaton 3D");

    Camera3D camera = { 0 };
    camera.position   = (Vector3){ 130.0f, -20.0f, 100.0f };
    camera.target     = (Vector3){  39.5f,  39.5f,   0.0f };
    camera.up         = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy       = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    int n     = 80;
    int count = (n * n) + 100;
    float cell_size = 0.6f;
    float border    = 1.0f;

    vector<vector<int>> grid = init_grid(n);
    fill_random(grid, count);

    fs::create_directory("frames_3d");

    SetTargetFPS(60);

    int frame        = 0;
    int total_frames = 300;

    while (!WindowShouldClose() && frame < total_frames)
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                    {
                        Vector3 pos = { (float)(j * border), (float)(i * border), 1.0f };
                        Color c = grid[i][j] == 1 ? GREEN : (Color){230,230,230,255};
                        DrawCube(pos, cell_size, cell_size, cell_size, c);
                    }

                DrawGrid(10, 1.0f);
                apply_rule(grid);

            EndMode3D();
        EndDrawing();

        Image img = LoadImageFromScreen();
        ExportImage(img, ("frames_3d/frame_" + to_string(frame) + ".png").c_str());
        UnloadImage(img);
        frame++;
    }

    CloseWindow();
    return 0;
}
