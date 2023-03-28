//
// Created by sammy on 3/28/2023.
//

#include <iostream>
#include "../../Map/Cell.h"
#include "CheckEscapeSystem.h"

using namespace Game::Map;

namespace Game {
    namespace Systems {
        void CheckEscapeSystem::execute(Game::Map::Map *map) {
            for(int x = 0; x < map->GetX(); x++){
                for(int y = 0; y < map->GetY(); y++){
                    Cell* cell = map->GetCell(x, y);
                    for(int i = 0; i < cell->characterCount; i++){
                        Character* character = cell->characters[i];
                        if(character->playerControlled && cell->isEscape){
                            std::cout << "Victory!" << std::endl;
                        }
                    }
                }
            }
        }
    } // Game
} // Systems