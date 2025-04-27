#include "KeyHandler.h"

KeyHandler::KeyHandler() = default;
KeyHandler::KeyHandler(std::vector<KeyAction> actions) : keyActions(actions) {}

void KeyHandler::addKeyAction(const KeyAction& action)
{
	keyActions.emplace_back(action);
}

void KeyHandler::handleKey(const sf::Event::KeyPressed& keyPressed)
{
	for (const auto& action : keyActions)
	{
		if (keyPressed.scancode == action.scancode)
		{
			action.callback();
		}
	}
}