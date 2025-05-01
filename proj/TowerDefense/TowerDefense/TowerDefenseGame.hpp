#pragma once
#include <GameManager.hpp>
#include "EventsHandler.hpp"

class TowerDefenseGame : public GameManager
{
protected:
    void handleEvents() override;
    void update() override;
    void render() override;

public:
    TowerDefenseGame(unsigned int width, unsigned int height, const char* title);
}; 