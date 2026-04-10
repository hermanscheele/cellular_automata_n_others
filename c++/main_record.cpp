#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "include/utils.hpp"
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    int n = 80;
    int count = 5200;
    vector<vector<int>> grid = init_grid(n);
    fill_random(grid, count);

    unsigned int wind_size = 600;

    int border = 1;
    float cell_size = (float)(wind_size - border * n) / n;

    fs::create_directory("frames_2d");

    sf::RenderTexture rt;
    rt.resize({wind_size, wind_size});

    int total_frames = 60;

    for (int frame = 0; frame < total_frames; frame++)
    {
        rt.clear(sf::Color::Black);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                float x = j * (cell_size + border);
                float y = i * (cell_size + border);

                sf::RectangleShape rect({cell_size, cell_size});
                rect.setPosition({x, y});
                rect.setFillColor(grid[i][j] == 1 ? sf::Color::Green : sf::Color::Black);
                rt.draw(rect);
            }
        }

        rt.display();
        sf::Image image = rt.getTexture().copyToImage();
        image.saveToFile("frames_2d/frame_" + to_string(frame) + ".png");

        apply_rule(grid);
    }

    return 0;
}
