//
// Created by sammy on 3/28/2023.
//

#include "GameManager.h"

#define SYSTEM_COUNT 0

namespace Game {
    GameManager::GameManager(int x, int y) {
        map = new Map::Map(x, y);

        systems = new System*[SYSTEM_COUNT]{

        };
    }

    GameManager::~GameManager() {
        delete map;
        delete[] systems;
    }
} // Game