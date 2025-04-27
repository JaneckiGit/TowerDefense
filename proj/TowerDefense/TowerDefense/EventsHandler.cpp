#include "EventsHandler.hpp"

KeyHandler EventsHandler::playerKeyHandler = PlayerControls::getKeyHandler();

void EventsHandler::eventsHandler(sf::RenderWindow& window)
{
	const auto onClose = [&window](const sf::Event::Closed&)
	{
		window.close();
	};
	const auto onResize = [&window](const sf::Event::Resized&)
	{
		// Window size
		sf::Vector2u size = window.getSize();

		// Resize the window to maintain the aspect ratio
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
		playerKeyHandler.handleKey(keyPressed); // Handle key events
	};
	window.handleEvents(onClose, onResize, onKeyPressed); // Handle events
}
