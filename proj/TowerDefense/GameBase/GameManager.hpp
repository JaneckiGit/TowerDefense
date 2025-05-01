#pragma once  
#include <iostream>  
#include "API.hpp"  
#include "KeyHandler.hpp"
#include <vector>
#include <SFML/Graphics.hpp>  

class EXPORT_API GameManager
{
private:
	sf::RenderWindow window;

protected:
	std::vector<sf::RectangleShape*> shapes; // Wektor kształtów do narysowania

	// Metody wirtualne, które mogą być nadpisane przez klasy pochodne
	virtual void handleEvents();
	virtual void update();
	virtual void render();

public:
	GameManager(unsigned int width, unsigned int height, const char* title);
	virtual ~GameManager() = default;
	
	sf::RenderWindow& getWindow();
	void run();
};