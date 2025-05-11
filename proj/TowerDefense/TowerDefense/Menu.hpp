// Menu.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <string>
#include "general.hpp"

class Menu
{
private:
    struct MenuItem {
        sf::RectangleShape shape;
        sf::RectangleShape labelBackground; // T³o dla etykiety
        std::string label; // Etykieta przycisku (do debugowania)
        std::function<void()> action;
        bool isHovered;
    };

    std::vector<MenuItem> items;
    sf::RectangleShape titleBar; // Prosty pasek tytu³owy

public:
    Menu();
    ~Menu() = default;

    bool initialize();
    void render(sf::RenderWindow& window);

    void addButton(const sf::Vector2f& position, const sf::Vector2f& size,
        const std::string& label, std::function<void()> action);

    void handleMouseMove(const sf::Vector2i& mousePos);
    void handleMouseClick(const sf::Vector2i& mousePos);
};