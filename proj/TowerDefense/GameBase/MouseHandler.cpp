#include "MouseHandler.hpp"


MouseHandler::MouseHandler(std::vector<MouseAction> actions) : mouseActions(actions) {}

void MouseHandler::addMouseAction(const MouseAction& action)
{
	mouseActions.push_back(action);
}

void MouseHandler::handleMouseClick(const sf::Event::MouseButtonPressed& mousePressed, const sf::Vector2i& position)
{
	for (const auto& action : mouseActions)
	{
		if (action.button == mousePressed.button)
		{
			action.callback(position);
		}
	}
}