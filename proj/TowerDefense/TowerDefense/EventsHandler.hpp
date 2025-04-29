#include "PlayerControls.hpp"  
#include "general.hpp"  
#include <SFML/Graphics.hpp>  
#include <MouseHandler.hpp>

class EventsHandler {  
private:  
	static KeyHandler playerKeyHandler;
	static MouseHandler mouseHandler;

public:  
	static void eventsHandler(sf::RenderWindow& window);  
	static void initializeMouseHandlers();
};  

