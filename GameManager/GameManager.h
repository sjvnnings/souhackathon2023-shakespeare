//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H
#define SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H

#include "../System/System.h"
#include "../Map/Map.h"
#include "Command.h"
#include "../Character/Character.h"

using namespace Game::Systems;
using namespace Game::Map;
using namespace Game::Characters;

namespace Game {
    class Command;

    class GameManager {
    private:
        System** systems = nullptr;
        int systemCount = 0;

        Game::Map::Map* map;

        Character** characters;
        int characterCount = 0;

        Item** items;
        int itemCount = 0;
    protected:
        void ExecuteSimulation();

    public:
        Character* playerCharacter;

        GameManager(int x, int y);
        ~GameManager();

        void Start();
        Command* UserInput();

        Game::Map::Map* GetMap();

        void EndGame();
    };

} // Game

#endif //SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H
