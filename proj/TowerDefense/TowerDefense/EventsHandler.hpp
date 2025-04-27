#include "PlayerControls.hpp"  
#include "general.hpp"  
#include <SFML/Graphics.hpp>  

class EventsHandler {  
private:  
static KeyHandler playerKeyHandler;

public:  
static void eventsHandler(sf::RenderWindow& window);  
};  

