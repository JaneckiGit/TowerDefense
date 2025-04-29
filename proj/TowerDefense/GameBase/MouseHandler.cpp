#include "MouseHandler.hpp"

MouseHandler::MouseHandler() = default;

MouseHandler::MouseHandler(std::vector<MouseAction> actions) : mouseActions(actions) {}

void MouseHandler::addMouseAction(const MouseAction& action)
{
	mouseActions.emplace_back(action);
}

void MouseHandler::handleMouseClick(const sf::Event::MouseButtonPressed& mousePressed, const sf::Vector2i& position)
{
	for (const auto& action : mouseActions)
	{
		if (mousePressed.button == action.button)
		{
			action.callback(position);
		}
	}
}