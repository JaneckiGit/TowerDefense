//#include "EventsHandler.hpp"
//#include <GameManager.hpp>
//
//void EventsHandler::initialize() {
//	// Inicjalizacja sterowania graczem
//	PlayerControls::initialize();
//	
//	// Inicjalizacja obsługi myszy
//	auto& inputManager = InputManager::getInstance();
//	inputManager.registerMouseAction({ sf::Mouse::Button::Left, 
//		[](const sf::Vector2i& position) {
//			std::cout << "Left mouse button pressed at: (" << position.x << ", " << position.y << ")" << std::endl;
//		}
//	});
//}
//
//void EventsHandler::eventsHandler(sf::RenderWindow& window)
//{
//	const auto onClose = [&window](const sf::Event::Closed&)
//	{
//		window.close();
//	};
//	const auto onResize = [&window](const sf::Event::Resized&)
//	{
//		// Pobierz nowy rozmiar okna
//		sf::Vector2u newSize = window.getSize();
//		
//		// Oblicz docelowy rozmiar zachowujący proporcje
//		float targetRatio = WINDOW_RATIO;
//		
//		// Określ, który wymiar dostosować na podstawie aktualnego rozmiaru okna
//		if (newSize.x / static_cast<float>(newSize.y) > targetRatio) {
//			// Okno jest za szerokie, dostosuj szerokość
//			newSize.x = static_cast<unsigned int>(newSize.y * targetRatio);
//		} else {
//			// Okno jest za wysokie, dostosuj wysokość
//			newSize.y = static_cast<unsigned int>(newSize.x / targetRatio);
//		}
//		
//		// Ustaw nowy rozmiar
//		window.setSize(newSize);
//
//		sf::View view = window.getView();
//		view.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT }); // Stały rozmiar świata gry
//		view.setCenter({ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }); // Środek świata gry
//		window.setView(view);
//		
//		std::cout << "Resized with ratio: " << newSize.x << "x" << newSize.y << std::endl;
//	};
//	const auto onKeyPressed = [](const sf::Event::KeyPressed& keyPressed) {
//		InputManager::getInstance().handleKeyEvent(keyPressed);
//	};
//	const auto onMousePressed = [&window](const sf::Event::MouseButtonPressed& mousePressed) {
//		// Pobierz pozycję myszy w współrzędnych okna
//		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//		
//		// Konwertuj do współrzędnych świata używając aktualnego widoku
//		sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
//		
//		// Przekaż współrzędne świata do menedżera wejścia
//		InputManager::getInstance().handleMouseEvent(mousePressed, sf::Vector2i(worldPos.x, worldPos.y));
//	};
//
//	window.handleEvents(onClose, onResize, onKeyPressed, onMousePressed); // Obsłuż zdarzenia
//}
#include "EventsHandler.hpp"
#include <GameManager.hpp>

void EventsHandler::initialize() {
	// Inicjalizacja sterowania graczem
	PlayerControls::initialize();

	// Inicjalizacja obsługi myszy
	auto& inputManager = InputManager::getInstance();
	inputManager.registerMouseAction({ sf::Mouse::Button::Left,
		[](const sf::Vector2i& position) {
			std::cout << "Left mouse button pressed at: (" << position.x << ", " << position.y << ")" << std::endl;
		}
		});
}

// Tylko fragment EventsHandler.cpp - zastąp aktualną implementację eventsHandler
void EventsHandler::eventsHandler(sf::RenderWindow& window)
{
    // Sprawdź, czy okno jest nadal otwarte
    if (!window.isOpen()) {
        return;
    }

    // Obsługa zamknięcia okna
    sf::Event closeEvent;
    while (window.pollEvent(closeEvent))
    {
        if (closeEvent.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    // Obsługa klawiszy WSAD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        PlayerControls::moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        PlayerControls::moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        PlayerControls::moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        PlayerControls::moveRight();
    }

    // Obsługa kliknięcia myszy
    static bool wasLeftMousePressed = false;
    bool isLeftMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    if (isLeftMousePressed && !wasLeftMousePressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

        std::cout << "Left mouse button pressed at: (" << worldPos.x << ", " << worldPos.y << ")" << std::endl;

        // Jeśli posiadasz metodę handleMouseClick w InputManager, możesz ją wywołać tutaj
    }

    wasLeftMousePressed = isLeftMousePressed;
}