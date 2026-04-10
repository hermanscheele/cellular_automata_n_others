#include "3D_utils.hpp"
#include "raylib.h"
#include <random>
#include <cmath>

vector<Vector3> calc_cell_positions(int n, float border)
{

    vector<Vector3> all_cube_pos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                float x = i * border;
                float y = j * border;
                float z = k * border;
                Vector3 cube_pos = {x, z, y};
                all_cube_pos.push_back(cube_pos);
            }
        }
    }

    return all_cube_pos;
}


vector<Vector3> calc_cell_positions_2D(int n, float border)
{

    float z = 1.0f * border;
    vector<Vector3> all_cube_pos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float x = i * border;
            float y = j * border;
            Vector3 cube_pos = {x, y, z};
            all_cube_pos.push_back(cube_pos);        
        }
    }

    return all_cube_pos;
}



vector<vector<float>> calc_normal_grid(int n)
{
    float start = -20.f;
    float end = 20.f;
    int slices = (abs(start) + abs(end) + 1);

    float start_pos = start;
    float end_pos = start_pos + 1;

    vector<vector<float>> grid;
    for (int i = 0; i < slices; i++)
    {   

        vector<float> pos = {start_pos, end_pos, 0, 0, 0};
        grid.push_back(pos);

        start_pos += 1;
        end_pos += 1;
    }
    

    // for (int i = 0; i < grid.size(); i++)
    // {
    //     cout << grid.at(i).at(0);
    // }

    
    return grid;
}



// vector<vector<float>> norm(int n, int mean, int std)
// {
//     vector<vector<float>> norms;

//     mt19937 rng(random_device{}());
//     normal_distribution<float> dist(mean, std);
//     float z = 0.f;
//     float y = 0.f;

//     vector<float> x_i;
//     vector<float> y_i;
//     vector<float> z_i;

//     for (int i = 0; i < n; i++)
//     {
//         x_i.push_back(dist(rng));
//         y_i.push_back(dist(rng));
//         z_i.push_back(dist(rng));
//     }

//     norms.push_back(x_i);
//     norms.push_back(y_i);
//     norms.push_back(z_i);

//     return norms;        
// }