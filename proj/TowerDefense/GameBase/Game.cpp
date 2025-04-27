#include "Game.h"

Game::Game(unsigned int width, unsigned int height, const char* title) : window(sf::VideoMode({ width, height }), title)
{
	std::cout << "Window has been created" << std::endl;
}

sf::RenderWindow& Game::getWindow()
{
	return window;
}

void Game::run()
{
    while (window.isOpen())
    {
		eventsHandler(window); // Handle events
        update();
        render();
    }
}

void Game::update()
{
	// Update game logic here

}

void Game::render()
{
	// Render game objects here
	window.clear();
	for (const auto& shape : shapes)
	{
		window.draw(*shape);
	}
	window.display();
}
