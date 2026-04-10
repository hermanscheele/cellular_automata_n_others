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
    sf::RenderWindow window(sf::VideoMode({wind_size, wind_size}), "Cell Automaton");

    int border = 1;
    float cell_size = (float)(wind_size - border * n) / n;

    fs::create_directory("frames_2d");

    int frame = 0;
    int total_frames = 60;

    while (window.isOpen() && frame < total_frames)
    {
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>()) window.close();

        window.clear(sf::Color::Black);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                float x = j * (cell_size + border);
                float y = i * (cell_size + border);

                sf::RectangleShape rect({cell_size, cell_size});
                rect.setPosition({x, y});
                rect.setFillColor(grid[i][j] == 1 ? sf::Color::Green : sf::Color::Black);
                window.draw(rect);
            }
        }

        window.display();

        sf::Texture texture;
        texture.resize({wind_size, wind_size});
        texture.update(window);
        sf::Image image = texture.copyToImage();
        image.saveToFile("frames_2d/frame_" + to_string(frame) + ".png");

        apply_rule(grid);
        frame++;
    }

    window.close();
    return 0;
}
