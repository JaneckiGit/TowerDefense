// Menu.cpp
#include "Menu.hpp"
#include <iostream>

Menu::Menu()
{
}

bool Menu::initialize()
{
    // Inicjalizacja prostego paska tytu³owego
    titleBar.setSize(sf::Vector2f(400.0f, 60.0f));
    titleBar.setPosition(sf::Vector2f((WINDOW_WIDTH - 400.0f) / 2.0f, 50.0f));
    titleBar.setFillColor(sf::Color(200, 50, 50)); // Czerwony pasek tytu³owy

    return true;
}

void Menu::render(sf::RenderWindow& window)
{
    // Rysowanie paska tytu³owego
    window.draw(titleBar);

    // Rysowanie wszystkich przycisków
    for (auto& item : items) {
        window.draw(item.shape);
        window.draw(item.labelBackground);
    }
}

void Menu::addButton(const sf::Vector2f& position, const sf::Vector2f& size,
    const std::string& label, std::function<void()> action)
{
    MenuItem item;
    item.shape.setPosition(position);
    item.shape.setSize(size);
    item.shape.setFillColor(sf::Color(100, 100, 200)); // Niebieski
    item.shape.setOutlineThickness(2.0f);
    item.shape.setOutlineColor(sf::Color(50, 50, 150)); // Ciemniejszy niebieski

    // Zamiast tekstu, dodajemy kolorowe prostok¹ty w zale¿noœci od typu przycisku
    if (label == "Start") {
        item.labelBackground.setSize(sf::Vector2f(size.x * 0.6f, size.y * 0.4f));
        item.labelBackground.setFillColor(sf::Color::Green);
    }
    else if (label == "Wczytaj") {
        item.labelBackground.setSize(sf::Vector2f(size.x * 0.6f, size.y * 0.4f));
        item.labelBackground.setFillColor(sf::Color::Yellow);
    }
    else if (label == "Zapisz") {
        item.labelBackground.setSize(sf::Vector2f(size.x * 0.6f, size.y * 0.4f));
        item.labelBackground.setFillColor(sf::Color::Cyan);
    }
    else {
        item.labelBackground.setSize(sf::Vector2f(size.x * 0.6f, size.y * 0.4f));
        item.labelBackground.setFillColor(sf::Color::White);
    }

    // Wyœrodkowanie prostok¹ta etykiety
    item.labelBackground.setPosition(sf::Vector2f(
        position.x + (size.x - item.labelBackground.getSize().x) / 2.0f,
        position.y + (size.y - item.labelBackground.getSize().y) / 2.0f
    ));

    item.label = label; // Zapisujemy etykietê tylko do celów debugowania
    item.action = action;
    item.isHovered = false;

    items.push_back(item);

    std::cout << "Added button: " << label << std::endl;
}

void Menu::handleMouseMove(const sf::Vector2i& mousePos)
{
    for (auto& item : items) {
        // Sprawdzenie czy kursor jest nad przyciskiem
        sf::FloatRect bounds = item.shape.getGlobalBounds();
        bool hovering = bounds.contains(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)));

        // Zmiana koloru gdy kursor jest nad przyciskiem
        if (hovering && !item.isHovered) {
            item.shape.setFillColor(sf::Color(120, 120, 220)); // Jaœniejszy niebieski
            item.isHovered = true;
        }
        else if (!hovering && item.isHovered) {
            item.shape.setFillColor(sf::Color(100, 100, 200)); // Normalny niebieski
            item.isHovered = false;
        }
    }
}

void Menu::handleMouseClick(const sf::Vector2i& mousePos)
{
    for (auto& item : items) {
        sf::FloatRect bounds = item.shape.getGlobalBounds();
        if (bounds.contains(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))) {
            std::cout << "Button clicked: " << item.label << std::endl;
            if (item.action) {
                item.action(); // Wywo³anie funkcji przypisanej do przycisku
            }
            break; // Obs³uga tylko jednego klikniêcia
        }
    }
}