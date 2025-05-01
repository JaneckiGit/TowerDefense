#include "InputManager.hpp"

InputManager* InputManager::instance = nullptr;

InputManager& InputManager::getInstance() {
    if (!instance) {
        instance = new InputManager();
    }
    return *instance;
}

void InputManager::registerKeyAction(const KeyAction& action) {
    keyHandler.addKeyAction(action);
}

void InputManager::registerMouseAction(const MouseAction& action) {
    mouseHandler.addMouseAction(action);
}

void InputManager::handleKeyEvent(const sf::Event::KeyPressed& event) {
    keyHandler.handleKey(event);
}

void InputManager::handleMouseEvent(const sf::Event::MouseButtonPressed& event, const sf::Vector2i& position) {
    mouseHandler.handleMouseClick(event, position);
} 