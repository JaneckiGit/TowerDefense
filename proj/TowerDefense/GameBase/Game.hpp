#pragma once  
#include <iostream>  
#include "API.h"  
#include "KeyHandler.hpp"
#include <vector>
#include <SFML/Graphics.hpp>  

class EXPORT_API Game  
{  
private:  
	sf::RenderWindow window;

public:
	std::vector<sf::RectangleShape*> shapes; //Vector of shapes to be drawn
	std::function<void(sf::RenderWindow&)> eventsHandler; //Main loop function pointer

	Game(unsigned int width, unsigned int height, const char* title);  
	sf::RenderWindow& getWindow();

	void run();
	void update();
	void render();
};
