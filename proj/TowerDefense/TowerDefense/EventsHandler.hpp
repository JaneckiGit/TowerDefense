#pragma once
#include "PlayerControls.hpp"  
#include "general.hpp"  
#include <SFML/Graphics.hpp>  
#include <InputManager.hpp>

class EventsHandler {
public:  
	static void eventsHandler(sf::RenderWindow& window);  
	static void initialize();
};  

