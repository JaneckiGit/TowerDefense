#include <Game.h>
#include "general.hpp"  
#include "EventsHandler.hpp"
#include <SFML/Graphics.hpp>

int main()  
{  
   Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

   game.eventsHandler = EventsHandler::eventsHandler; // Set the main loop function

   auto shape = sf::RectangleShape({ 100, 100 }); // Create a shape
   shape.setFillColor(sf::Color::Green); // Set the color of the shape

   game.getWindow().setFramerateLimit(60); // Set the frame rate limit

   game.shapes.push_back({ &shape }); // Add a shape to the vector
   game.run(); // Start the game loop
   return 0;  
}