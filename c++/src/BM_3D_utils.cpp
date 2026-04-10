#include "BM_3D_utils.hpp"
#include <random>
#include <cmath>


vector<vector<vector<float>>> brownian_motion(int n_steps, int n_paths, double dt)
{
    mt19937 rng(random_device{}());
    normal_distribution<float> dist(0.0, sqrt(dt));
    vector<vector<vector<float>>> paths;

    for (int i = 0; i < n_paths; i++)
    {
        vector<vector<float>> path_xy;
        path_xy.push_back({0.f, 0.f});
        float cumsum_x = 0.f;
        float cumsum_y = 0.f;

        for (int j = 0; j < n_steps - 1; j++)
        {   
            float step_x = dist(rng);
            float step_y = dist(rng);
            cumsum_x += step_x;
            cumsum_y += step_y;

            path_xy.push_back({cumsum_x, cumsum_y});
        }

        paths.push_back(path_xy);
    }

    return paths;
}