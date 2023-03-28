//
// Created by sammy on 3/28/2023.
//

#include <iostream>
#include "AttackSystem.h"
#include "../../Map/Cell.h"

using namespace Game::Map;

namespace Game {
    namespace Systems {
        void AttackSystem::execute(Game::Map::Map *map) {
            for(int x = 0; x < map->GetX(); x++){
                for(int y = 0; y < map->GetY(); y++){
                    Cell* cell = map->GetCell(x, y);
                    for(int i = 0; i < cell->characterCount; i++){
                        Character* character = cell->characters[i];
                        if(character->isAttacking){
                            for(int x2 = -1; x2 <= 1; x2++){
                                for(int y2 = -1; y2 <= 1; y2++){
                                    Cell* adjacentCell = map->GetCell(x + x2, y + y2);
                                    if(adjacentCell == cell || adjacentCell == nullptr)
                                        continue;

                                    for(int i2 = 0; i2 < adjacentCell->characterCount; i2++){
                                        adjacentCell->characters[i2]->SetIsDead(true);
                                        std::cout << adjacentCell->characters[i2]->GetDeathMessage() << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } // Game
} // Systems