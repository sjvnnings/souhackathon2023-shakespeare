//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H
#define SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H

#include "../System/System.h"

using namespace Game::Systems;

namespace Game {

    class GameManager {
    private:
        System* systems = nullptr;
        int systemCount = 0;

        //TODO: Add map reference
    public:
        GameManager();
    };

} // Game

#endif //SOUHACKATHON2023_SHAKESPEARE_GAMEMANAGER_H
