#include "TowerDefenseGame.hpp"

TowerDefenseGame::TowerDefenseGame(unsigned int width, unsigned int height, const char* title)
    : GameManager(width, height, title)
{
    // Inicjalizacja obiektów specyficznych dla gry
    sf::RectangleShape* shape = new sf::RectangleShape({ 100, 100 });
    shape->setFillColor(sf::Color::Green);
    shape->setPosition({ width / 2.f - 50, height / 2.f - 50 });
    shapes.push_back(shape);
    
    getWindow().setFramerateLimit(60);
}

void TowerDefenseGame::handleEvents()
{
    EventsHandler::eventsHandler(getWindow());
}

void TowerDefenseGame::update()
{
    // Implementacja logiki aktualizacji specyficznej dla gry
}

void TowerDefenseGame::render()
{
    // Wywołanie metody render z klasy bazowej
    GameManager::render();
    
    // Dodatkowe renderowanie, jeśli potrzebne
} 