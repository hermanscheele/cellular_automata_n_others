#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

vector<Vector3> calc_cell_positions(int n, float border);

vector<Vector3> calc_cell_positions_2D(int n, float border);

vector<vector<float>> calc_normal_grid(int n);

vector<vector<float>> norm(int n, int mean, int std);