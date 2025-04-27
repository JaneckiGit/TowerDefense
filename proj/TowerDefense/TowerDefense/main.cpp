#include "Game.h"  
#include "general.h"  
#include "PlayerControls.h"
#include <SFML/Graphics.hpp>

auto playerControls = PlayerControls::getControls();

void eventsHandler(sf::RenderWindow& window)  
{  
	const auto onClose = [&window](const sf::Event::Closed&)
	{
		window.close();
	};

	const auto onResize = [&window](const sf::Event::Resized&)
	{
			// Window size
			sf::Vector2u size = window.getSize();

			// Ration 4:3
			float ratio = WINDOW_RATIO;

			if (size.x / static_cast<float>(size.y) > ratio) {
				size.x = static_cast<unsigned int>(size.y * ratio);
			}
			else {
				size.y = static_cast<unsigned int>(size.x / ratio);
			}

			// Set the new size
			std::cout << "Resized to: " << size.x << "x" << size.y << std::endl;
			window.setSize(size);
	};

	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
	{
		playerControls.handleKey(keyPressed); // Handle key events
	};

	window.handleEvents(onClose, onResize, onKeyPressed); // Handle events
}

int main()  
{  
   Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

   auto controls = PlayerControls::getControls(); // Initialize player controls

   game.eventsHandler = eventsHandler; // Set the main loop function

   auto shape = sf::RectangleShape({ 100, 100 }); // Create a shape
   shape.setFillColor(sf::Color::Green); // Set the color of the shape

   game.getWindow().setFramerateLimit(60); // Set the frame rate limit

   game.shapes.push_back({ &shape }); // Add a shape to the vector
   game.run(); // Start the game loop  
   return 0;  
}