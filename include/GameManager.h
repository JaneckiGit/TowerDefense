#pragma once
#include <iostream>
#include "API.h"
#include "KeyHandler.h"
#include <SFML/Graphics.hpp>

class EXPORT_API GameManager
{
private:
	sf::RenderWindow window;

public:
	GameManager(unsigned int width, unsigned int height, const char* title);
};