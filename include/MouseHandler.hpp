#pragma once
#include "API.hpp"
#include <iostream>
#include <vector>
#include <functional>
#include <SFML/Window.hpp>

struct MouseAction {
    sf::Mouse::Button button;
    std::function<void(const sf::Vector2i&)> callback;
};

class EXPORT_API MouseHandler {
private:
    std::vector<MouseAction> mouseActions;

public:
    MouseHandler() = default;
    MouseHandler(std::vector<MouseAction> actions);

    void addMouseAction(const MouseAction& action);
    void handleMouseClick(const sf::Event::MouseButtonPressed& mousePressed, const sf::Vector2i& position);
}; 