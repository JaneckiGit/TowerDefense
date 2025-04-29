#include "EventsHandler.hpp"
#include <Game.hpp>

KeyHandler EventsHandler::playerKeyHandler = PlayerControls::getKeyHandler();
MouseHandler EventsHandler::mouseHandler;

void EventsHandler::initializeMouseHandlers() {
	// Example mouse click handler
	mouseHandler.addMouseAction({
		sf::Mouse::Button::Left, // Left mouse button
		[](const sf::Vector2i& position) {
			std::cout << "Left mouse button pressed at: (" << position.x << ", " << position.y << ")" << std::endl;
		}
	});
}

void EventsHandler::eventsHandler(sf::RenderWindow& window)
{
	const auto onClose = [&window](const sf::Event::Closed&)
	{
		window.close();
	};
	const auto onResize = [&window](const sf::Event::Resized&)
	{
		// Get the new window size
		sf::Vector2u newSize = window.getSize();
		
		// Calculate the target size that maintains aspect ratio
		float targetRatio = WINDOW_RATIO;
		
		// Determine which dimension to adjust based on the current window size
		if (newSize.x / static_cast<float>(newSize.y) > targetRatio) {
			// Window is too wide, adjust width
			newSize.x = static_cast<unsigned int>(newSize.y * targetRatio);
		} else {
			// Window is too tall, adjust height
			newSize.y = static_cast<unsigned int>(newSize.x / targetRatio);
		}
		
		// Set the new size
		window.setSize(newSize);

		sf::View view = window.getView();
		view.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT }); // Fixed game world size
		view.setCenter({ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }); // Center of the game world
		window.setView(view);
		
		std::cout << "Resized with ratio: " << newSize.x << "x" << newSize.y << std::endl;
	};
	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
	{
		playerKeyHandler.handleKey(keyPressed); // Handle key events
	};
	const auto onMousePressed = [&window](const sf::Event::MouseButtonPressed& mousePressed)
	{
		// Get the mouse position in window coordinates
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		
		// Convert to world coordinates using the current view
		sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
		
		// Pass the world coordinates to the mouse handler
		mouseHandler.handleMouseClick(mousePressed, sf::Vector2i(worldPos.x, worldPos.y));
	};

	window.handleEvents(onClose, onResize, onKeyPressed, onMousePressed); // Handle events
}
