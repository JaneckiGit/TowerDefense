#include "GameManager.hpp"

GameManager::GameManager(unsigned int width, unsigned int height, const char* title) : window(sf::VideoMode({ width, height }), title)
{
	std::cout << "Window has been created" << std::endl;
}

sf::RenderWindow& GameManager::getWindow()
{
	return window;
}

void GameManager::run()
{
    while (window.isOpen())
    {
		handleEvents();
        update();
        render();
    }
}

void GameManager::handleEvents()
{
	const auto onClose = [this](const sf::Event::Closed&)
	{
		window.close();
	};
}

void GameManager::update()
{
	// Base implementation - can be overridden by derived classes
}

void GameManager::render()
{
	// Render game objects here
	window.clear();
	for (const auto& shape : shapes)
	{
		window.draw(*shape);
	}
	window.display();
}
