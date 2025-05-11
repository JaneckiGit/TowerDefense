//#pragma once
//#include <GameManager.hpp>
//#include "EventsHandler.hpp"
//
//class TowerDefenseGame : public GameManager
//{
//protected:
//    void handleEvents() override;
//    void update() override;
//    void render() override;
//
//public:
//    TowerDefenseGame(unsigned int width, unsigned int height, const char* title);
//}; 
// TowerDefenseGame.hpp
// TowerDefenseGame.hpp
// TowerDefenseGame.hpp
#pragma once
#include <GameManager.hpp>
#include "EventsHandler.hpp"
#include "Menu.hpp"
#include <fstream>

class TowerDefenseGame : public GameManager
{
private:
    // Definiujemy GameState wewn¹trz klasy
    enum class GameState {
        MENU,
        PLAYING,
        PAUSED
    };

    Menu menu;
    GameState gameState;

    // Dane gry do zapisu/odczytu
    int playerMoney;
    int playerLives;
    int currentWave;

    // Zmienne do obs³ugi stanu myszy i klawiatury
    bool wasEscapePressed;
    bool wasLeftMousePressed;

    // Akcje menu
    void startGame();
    void saveGame();
    void loadGame();

protected:
    void handleEvents() override;
    void update() override;
    void render() override;

public:
    TowerDefenseGame(unsigned int width, unsigned int height, const char* title);
};