#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> init_grid(int n);

void render_grid(vector<vector<int>> grid);

void apply_rule(vector<vector<int>>& grid);

void fill_random(vector<vector<int>>& grid, int count);