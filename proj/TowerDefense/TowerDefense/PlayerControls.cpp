#include "PlayerControls.hpp"

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


KeyHandler PlayerControls::getKeyHandler() {
	KeyHandler keyHandler;
	keyHandler.addKeyAction({ sf::Keyboard::Scancode::W, moveUp });
	keyHandler.addKeyAction({ sf::Keyboard::Scancode::S, moveDown });
	keyHandler.addKeyAction({ sf::Keyboard::Scancode::A, moveLeft });
	keyHandler.addKeyAction({ sf::Keyboard::Scancode::D, moveRight });
	return keyHandler;
}
