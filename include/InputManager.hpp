#pragma once
#include "API.hpp"
#include "KeyHandler.hpp"
#include "MouseHandler.hpp"
#include <SFML/Graphics.hpp>

class EXPORT_API InputManager {
private:
    static InputManager* instance;
    KeyHandler keyHandler;
    MouseHandler mouseHandler;

    InputManager() = default;
    ~InputManager() = default;

public:
    // Singleton pattern
    static InputManager& getInstance();
    
    // Usuwamy możliwość kopiowania i przypisywania
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;

    // Metody do rejestracji handlerów
    void registerKeyAction(const KeyAction& action);
    void registerMouseAction(const MouseAction& action);

    // Metody do obsługi zdarzeń
    void handleKeyEvent(const sf::Event::KeyPressed& event);
    void handleMouseEvent(const sf::Event::MouseButtonPressed& event, const sf::Vector2i& position);
}; 