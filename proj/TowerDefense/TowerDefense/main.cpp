#include "GameManager.h"  
#include <SFML/Graphics.hpp>

int main()  
{  
    GameManager gameManager;
    gameManager.Initialize();  

    // Corrected sf::VideoMode constructor usage
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Tower Defense Game");

    // Main game loop
    while (window.isOpen())
    {
	    while (const std::optional event = window.pollEvent())
	    {
		    if (event->is<sf::Event::Closed>())
			    window.close();
	    }
        // Clear screen
        window.clear();

        // Draw the sprite
        //window.draw(sprite);

        // Draw the string
        //window.draw(text);

        // Update the window
        //window.display();
    }
    return 0;  
}