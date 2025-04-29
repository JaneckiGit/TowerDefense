#include <Game.hpp>
#include "general.hpp"  
#include "EventsHandler.hpp"
#include <SFML/Graphics.hpp>

int main()  
{  
   Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

   // Initialize mouse handlers
   EventsHandler::initializeMouseHandlers();
   
   // Uncomment this line to use the custom event handler
    game.eventsHandler = EventsHandler::eventsHandler;

   // Create a shape at the center of the screen
   sf::RectangleShape* shape = new sf::RectangleShape({ 100, 100 }); 
   shape->setFillColor(sf::Color::Green);
   shape->setPosition({ WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50 }); // Center the shape

   game.getWindow().setFramerateLimit(60); // Set the frame rate limit

   game.shapes.push_back(shape); // Add a shape to the vector
   game.run(); // Start the game loop
   
   // Clean up the allocated memory
   //delete shape;
   
   return 0;  
}