#include "utils.hpp"
#include <random>

vector<vector<int>> init_grid(int n)
{
    vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grid[i][j] = 0;
		}
	}
    return grid;
}

void render_grid(vector<vector<int>> grid)
{	
	int n = grid.size();
    for (auto row : grid)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == 0)             { cout << "(" << row[i]; }
			else if (i == (n - 1))  { cout << ", " << row[i] << ")";}
			else 		            { cout << ", " << row[i]; } 
		}
		cout << endl; 
	}
}


void fill_random(vector<vector<int>>& grid, int count)
{
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(0, grid.size() - 1);

	for (int i = 0; i < count; i++)
	{
		int x = dist(rng);
		int y = dist(rng);

		grid[x][y] = 1;
	}
}



void apply_rule(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> buffer = grid;  // copy

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;

            // ceiling
            if (i == 0) {
                if (j == 0) {
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j+1] == 1 ? 1 : 0;
                }
                else if (j == n - 1) {
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j-1] == 1 ? 1 : 0;
                }
                else {
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j-1] == 1 ? 1 : 0;
                }
            }
            // floor
            else if (i == n - 1) {
                if (j == 0) {
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i-1][j+1] == 1 ? 1 : 0;
                }
                else if (j == n - 1) {
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i-1][j-1] == 1 ? 1 : 0;
                }
                else {
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i-1][j+1] == 1 ? 1 : 0;
                    count += grid[i-1][j-1] == 1 ? 1 : 0;
                }
            }
            // interior rows
            else {
                if (j == 0) {
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i-1][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j+1] == 1 ? 1 : 0;
                }
                else if (j == n - 1) {
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i-1][j-1] == 1 ? 1 : 0;
                    count += grid[i+1][j-1] == 1 ? 1 : 0;
                }
                else {
                    count += grid[i-1][j] == 1 ? 1 : 0;
                    count += grid[i+1][j] == 1 ? 1 : 0;
                    count += grid[i][j-1] == 1 ? 1 : 0;
                    count += grid[i][j+1] == 1 ? 1 : 0;
                    count += grid[i-1][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j+1] == 1 ? 1 : 0;
                    count += grid[i+1][j-1] == 1 ? 1 : 0;
                    count += grid[i-1][j-1] == 1 ? 1 : 0;
                }
            }

            // apply rule
            if (grid[i][j] == 0 && count == 3)
                buffer[i][j] = 1;
            else if (grid[i][j] == 1 && (count == 2 || count == 3))
                buffer[i][j] = 1;
            else
                buffer[i][j] = 0;
        }
    }

    grid = buffer;
}
