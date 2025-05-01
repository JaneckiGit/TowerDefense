#pragma once  
#include "API.hpp"  
#include <iostream>  
#include <vector>
#include <functional>
#include <SFML/Window.hpp> 


struct KeyAction {
	sf::Keyboard::Scancode scancode;
	std::function<void()> callback;
};

class EXPORT_API KeyHandler {
private:
	std::vector<KeyAction> keyActions;

public:
	KeyHandler() = default;
	KeyHandler(std::vector<KeyAction> actions);

	void addKeyAction(const KeyAction& key);
	void handleKey(const sf::Event::KeyPressed& keyPressed);
};