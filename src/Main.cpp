#include <SFML/Graphics.hpp>
#include <array>

template <int Width, int Height>
class Grid
{
public:
	constexpr Grid();
//private:
	std::array<double, Width * Height> data;
	sf::VertexArray quads;
};

template<int Width, int Height>
constexpr Grid<Width, Height>::Grid() : quads(sf::Quads, (Width) * (Height) * 4)
{
	for (int i = 0; i < Width - 1; i++)
	{
		for (int j = 0; j < Height - 1; j++)
		{
			quads[(i * Height + j) * 4].position = sf::Vector2f(100 * i + 0.f, 100 * j + 0.f);
			quads[(i * Height + j) * 4 + 1].position = sf::Vector2f(100 * i + 100.f, 100 * j + 0.f);
			quads[(i * Height + j) * 4 + 2].position = sf::Vector2f(100 * i + 100.f, 100 * j + 100.f);
			quads[(i * Height + j) * 4 + 3].position = sf::Vector2f(100 * i + 0.f, 100 * j + 100.f);
					   
			quads[(i * Height + j) * 4].color = sf::Color::Red;
			quads[(i * Height + j) * 4 + 1].color = sf::Color::Blue;
			quads[(i * Height + j) * 4 + 2].color = sf::Color::White;;
			quads[(i * Height + j) * 4 + 3].color = sf::Color::Yellow;
		}
	}
}


int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Load a sprite to display
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear(sf::Color::White);

		//sf::VertexArray triangle(sf::Quads, 8);
		//
		//triangle[0].position = sf::Vector2f(10.f, 10.f);
		//triangle[1].position = sf::Vector2f(100.f, 10.f);
		//triangle[2].position = sf::Vector2f(100.f, 100.f);
		//triangle[3].position = sf::Vector2f(10.f, 100.f);
		//
		//
		//triangle[4].position = sf::Vector2f(10.f, 10.f + 100);
		//triangle[5].position = sf::Vector2f(100.f, 10.f + 100);
		//triangle[6].position = sf::Vector2f(100.f, 100.f + 100);
		//triangle[7].position = sf::Vector2f(10.f, 100.f + 100);
		//
		//triangle[0].color = sf::Color::Red;
		//triangle[1].color = sf::Color::Blue;
		//triangle[2].color = sf::Color::White;
		//triangle[3].color = sf::Color::Yellow;
		//triangle[4].color = sf::Color::Blue;
		//triangle[5].color = sf::Color::Red;
		//triangle[6].color = sf::Color::White;
		//triangle[7].color = sf::Color::Yellow;

		Grid<4, 4> grid;

		window.draw(grid.quads);

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}