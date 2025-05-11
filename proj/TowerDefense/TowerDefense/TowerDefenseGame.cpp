//#include "TowerDefenseGame.hpp"
//
//TowerDefenseGame::TowerDefenseGame(unsigned int width, unsigned int height, const char* title)
//    : GameManager(width, height, title)
//{
//    // Inicjalizacja obiektów specyficznych dla gry
//    sf::RectangleShape* shape = new sf::RectangleShape({ 100, 100 });
//    shape->setFillColor(sf::Color::Green);
//    shape->setPosition({ width / 2.f - 50, height / 2.f - 50 });
//    shapes.push_back(shape);
//    
//    getWindow().setFramerateLimit(60);
//}
//
//void TowerDefenseGame::handleEvents()
//{
//    EventsHandler::eventsHandler(getWindow());
//}
//
//void TowerDefenseGame::update()
//{
//    // Implementacja logiki aktualizacji specyficznej dla gry
//}
//
////void TowerDefenseGame::render()
////{
//    // Wywołanie metody render z klasy bazowej
//    //GameManager::render();
//    
//    // Dodatkowe renderowanie, jeśli potrzebne
//
////}
// 
//// TowerDefenseGame.cpp (modyfikacja)
//
//// W konstruktorze, gdy renderujemy PAUZA, usuwamy tekst i używamy prostokąta:
//void TowerDefenseGame::render()
//{
//    getWindow().clear(sf::Color(40, 40, 40)); // Ciemny szary
//
//    if (gameState == GameState::MENU) {
//        // Renderowanie menu
//        menu.render(getWindow());
//    }
//    else if (gameState == GameState::PLAYING || gameState == GameState::PAUSED) {
//        // Renderowanie elementów gry
//        GameManager::render();
//
//        // Jeśli gra jest spauzowana, wyświetl komunikat PAUZA
//        if (gameState == GameState::PAUSED) {
//            // Półprzezroczyste tło
//            sf::RectangleShape overlay;
//            overlay.setSize({ static_cast<float>(WINDOW_WIDTH), static_cast<float>(WINDOW_HEIGHT) });
//            overlay.setFillColor(sf::Color(0, 0, 0, 150)); // Czarny z przezroczystością
//            getWindow().draw(overlay);
//
//            // Zamiast tekstu PAUZA używamy prostokąta
//            sf::RectangleShape pauseIndicator;
//            pauseIndicator.setSize({ 200.0f, 80.0f });
//            pauseIndicator.setFillColor(sf::Color::Red);
//            pauseIndicator.setPosition({
//                (WINDOW_WIDTH - 200.0f) / 2.0f,
//                (WINDOW_HEIGHT - 80.0f) / 2.0f
//                });
//            getWindow().draw(pauseIndicator);
//        }
//    }
//
//    getWindow().display();
//}

// Nowa implementacja TowerDefenseGame.cpp
// TowerDefenseGame.cpp
#include "TowerDefenseGame.hpp"
#include <iostream>

TowerDefenseGame::TowerDefenseGame(unsigned int width, unsigned int height, const char* title)
    : GameManager(width, height, title), gameState(GameState::MENU),
    playerMoney(100), playerLives(20), currentWave(1),
    wasEscapePressed(false), wasLeftMousePressed(false)
{
    // Inicjalizacja menu
    if (!menu.initialize()) {
        std::cerr << "Failed to initialize menu!" << std::endl;
    }

    // Dodanie przycisków do menu - z poprawionymi pozycjami dla lepszej widoczności
    float buttonWidth = 200.0f;
    float buttonHeight = 50.0f;
    float startX = (width - buttonWidth) / 2.0f;
    float startY = 200.0f;
    float spacing = 70.0f;

    // Przycisk Start
    menu.addButton(
        sf::Vector2f(startX, startY),
        sf::Vector2f(buttonWidth, buttonHeight),
        "Start",
        [this]() { startGame(); }
    );

    // Przycisk Wczytaj
    menu.addButton(
        sf::Vector2f(startX, startY + spacing),
        sf::Vector2f(buttonWidth, buttonHeight),
        "Wczytaj",
        [this]() { loadGame(); }
    );

    // Przycisk Zapisz
    menu.addButton(
        sf::Vector2f(startX, startY + 2 * spacing),
        sf::Vector2f(buttonWidth, buttonHeight),
        "Zapisz",
        [this]() { saveGame(); }
    );

    // Konfiguracja okna
    getWindow().setFramerateLimit(60);

    // Inicjalizacja przykładowego obiektu gry (testowo)
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(100, 100));
    shape->setFillColor(sf::Color::Green);
    shape->setPosition(sf::Vector2f(width / 2.f - 50, height / 2.f - 50));
    shapes.push_back(shape);
}

void TowerDefenseGame::handleEvents()
{
    // Obsługa zamknięcia okna - sprawdź, czy są jakieś zdarzenia w kolejce
    // W SFML 3.0 metoda pollEvent mogła się zmienić
    // Użyjmy alternatywnego podejścia

    // Sprawdzamy, czy okno zamknięto poza pętlą (np. przez kliknięcie przycisku X)
    if (!getWindow().isOpen()) {
        return;
    }

    // Obsługa klawisza Escape (przełączanie pauzy)
    bool isEscapePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

    if (isEscapePressed && !wasEscapePressed) {
        if (gameState == GameState::PLAYING) {
            gameState = GameState::PAUSED;
        }
        else if (gameState == GameState::PAUSED) {
            gameState = GameState::PLAYING;
        }
    }

    wasEscapePressed = isEscapePressed;

    // Obsługa menu
    if (gameState == GameState::MENU) {
        // Używamy sf::Mouse::getPosition dla kompatybilności z SFML 3.0
        sf::Vector2i mousePos = sf::Mouse::getPosition(getWindow());
        menu.handleMouseMove(mousePos);

        // Obsługa kliknięcia
        bool isLeftMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        if (isLeftMousePressed && !wasLeftMousePressed) {
            menu.handleMouseClick(mousePos);
        }

        wasLeftMousePressed = isLeftMousePressed;
    }

    // Standardowa obsługa zdarzeń w trybie gry
    if (gameState == GameState::PLAYING) {
        // Użycie istniejącego EventsHandlera
        EventsHandler::eventsHandler(getWindow());
    }
}

void TowerDefenseGame::update()
{
    // Aktualizacja logiki gry tylko w trybie gry
    if (gameState == GameState::PLAYING) {
        // Tu będzie logika gry w przyszłości
    }
}

void TowerDefenseGame::render()
{
    getWindow().clear(sf::Color(40, 40, 40)); // Ciemny szary

    if (gameState == GameState::MENU) {
        // Renderowanie menu
        menu.render(getWindow());
    }
    else if (gameState == GameState::PLAYING || gameState == GameState::PAUSED) {
        // Renderowanie elementów gry
        GameManager::render();

        // Jeśli gra jest spauzowana, wyświetl komunikat PAUZA
        if (gameState == GameState::PAUSED) {
            // Półprzezroczyste tło
            sf::RectangleShape overlay;
            overlay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
            overlay.setFillColor(sf::Color(0, 0, 0, 150)); // Czarny z przezroczystością
            getWindow().draw(overlay);

            // Zamiast tekstu PAUZA używamy prostokąta
            sf::RectangleShape pauseIndicator;
            pauseIndicator.setSize(sf::Vector2f(200.0f, 80.0f));
            pauseIndicator.setFillColor(sf::Color::Red);
            pauseIndicator.setPosition(sf::Vector2f(
                (WINDOW_WIDTH - 200.0f) / 2.0f,
                (WINDOW_HEIGHT - 80.0f) / 2.0f
            ));
            getWindow().draw(pauseIndicator);
        }
    }

    getWindow().display();
}

// Implementacja akcji menu
void TowerDefenseGame::startGame()
{
    std::cout << "Starting game..." << std::endl;
    gameState = GameState::PLAYING;
}

void TowerDefenseGame::saveGame()
{
    std::cout << "Saving game..." << std::endl;

    if (gameState != GameState::PLAYING && gameState != GameState::PAUSED) {
        std::cout << "No game in progress to save!" << std::endl;
        return;
    }

    try {
        std::ofstream saveFile("savegame.txt");
        if (saveFile.is_open()) {
            // Zapisujemy podstawowe dane gry
            saveFile << playerMoney << " "
                << playerLives << " "
                << currentWave << std::endl;

            std::cout << "Game saved successfully!" << std::endl;
        }
        else {
            std::cerr << "Could not open save file!" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error saving game: " << e.what() << std::endl;
    }
}

void TowerDefenseGame::loadGame()
{
    std::cout << "Loading game..." << std::endl;

    try {
        std::ifstream saveFile("savegame.txt");
        if (saveFile.is_open()) {
            // Wczytujemy podstawowe dane gry
            saveFile >> playerMoney >> playerLives >> currentWave;

            std::cout << "Game loaded successfully!" << std::endl;
            std::cout << "Money: " << playerMoney
                << ", Lives: " << playerLives
                << ", Wave: " << currentWave << std::endl;

            // Przejście do trybu gry
            gameState = GameState::PLAYING;
        }
        else {
            std::cerr << "Could not open save file!" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading game: " << e.what() << std::endl;
    }
}