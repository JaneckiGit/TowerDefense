#include "TowerDefenseGame.hpp"
#include "general.hpp"
#include "EventsHandler.hpp"

int main()
{
    TowerDefenseGame game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    // Inicjalizacja obsługi zdarzeń
    EventsHandler::initialize();

    game.run();

    return 0;
}