//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_ATTACKSYSTEM_H
#define SOUHACKATHON2023_SHAKESPEARE_ATTACKSYSTEM_H

#include "../System.h"
#include "../../Map/Map.h"

namespace Game {
    namespace Systems {

        class AttackSystem : public System {
        public:
            void execute(Game::Map::Map* map) override;
        };

    } // Game
} // Systems

#endif //SOUHACKATHON2023_SHAKESPEARE_ATTACKSYSTEM_H
