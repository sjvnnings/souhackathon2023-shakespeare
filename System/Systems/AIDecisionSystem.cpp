//
// Created by sammy on 3/28/2023.
//

#include "AIDecisionSystem.h"

using namespace Game::Map;

namespace Game {
    namespace Systems {
        void AIDecisionSystem::execute(Game::Map::Map *map) {
            for(int x = 0; x < map->GetX(); x++){
                for(int y = 0; y < map->GetY(); y++){
                    Cell* cell = map->GetCell(x, y);
                    for(int i = 0; i < cell->characterCount; i++){
                        Character* character = cell->characters[i];
                        if(character->playerControlled || character->target == nullptr)
                            continue;

                        int targetX = character->target->cellx;
                        int targetY = character->target->celly;

                        int charX = character->cellx;
                        int charY = character->celly;

                        if(abs((targetX - charX) + (targetY - charY)) == 1){
                            map->isGameOver = true;
                            map->isVictory = false;
                        }else{
                            int newX = targetX == charX ? charX : charX + (targetX - charX > 0 ? 1 : -1);
                            int newY = newX != charX ? charY : charY + (targetY - charY > 0 ? 1 : -1);

                            cell->RemoveCharacter(character);
                            map->GetCell(newX, newY)->AddCharacter(character);
                        }
                    }
                }
            }
        }
    } // Game
} // Systems