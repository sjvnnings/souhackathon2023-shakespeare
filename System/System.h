//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H
#define SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H

#include "../Map/Map.h"

namespace Game {
    namespace Systems {

        class System {
        public:
            virtual void execute(Game::Map::Map* map) = 0;
        };

    } // Game
} // Systems

#endif //SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H
