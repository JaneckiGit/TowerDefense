#include "PlayerControls.hpp"

void PlayerControls::initialize() {
	auto& inputManager = InputManager::getInstance();
	
	inputManager.registerKeyAction({ sf::Keyboard::Scancode::W, moveUp });
	inputManager.registerKeyAction({ sf::Keyboard::Scancode::S, moveDown });
	inputManager.registerKeyAction({ sf::Keyboard::Scancode::A, moveLeft });
	inputManager.registerKeyAction({ sf::Keyboard::Scancode::D, moveRight });
}

void PlayerControls::moveUp()
{
	std::cout << "Move Up" << std::endl;
}

void PlayerControls::moveDown()
{
	std::cout << "Move Down" << std::endl;
}

void PlayerControls::moveLeft()
{
	std::cout << "Move Left" << std::endl;
}	

void PlayerControls::moveRight()
{
	std::cout << "Move Right" << std::endl;
}
