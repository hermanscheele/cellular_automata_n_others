#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	int n = 80;
	int count = 5200;
	vector<vector<int>> grid = init_grid(n);
	fill_random(grid, count);
	render_grid(grid);

	unsigned int wind_size = 1000;
	sf::RenderWindow window(sf::VideoMode({wind_size, wind_size}), "SFML works!");

	int border = 10;
	sf::Vector2f size = {8, 8};

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				float x = static_cast<float>(i * border);
				float y = static_cast<float>(j * border);

				sf::Vector2f pos = {x + border, y + border};
				sf::RectangleShape rect(size);

				if (grid[i][j] == 1)    rect.setFillColor(sf::Color::Green);
				else                      rect.setFillColor(sf::Color::Black);

				rect.setPosition(pos);
        		window.draw(rect);
			}
		}

		
        window.display();
		this_thread::sleep_for(chrono::milliseconds(30));
		apply_rule(grid);

    }

	return 0;
}
