#include "KeyHandler.hpp"

KeyHandler::KeyHandler(std::vector<KeyAction> actions) : keyActions(actions) {}

void KeyHandler::addKeyAction(const KeyAction& action)
{
	keyActions.push_back(action);
}

void KeyHandler::handleKey(const sf::Event::KeyPressed& keyPressed)
{
	for (const auto& action : keyActions)
	{
		if (action.scancode == keyPressed.scancode)
		{
			action.callback();
		}
	}
}