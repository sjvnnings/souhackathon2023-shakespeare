//
// Created by Brayden Edwards on 3/28/23.
//

#include "AttackCommand.h"

namespace Game {
    void Game::AttackCommand::execute(Game::GameManager *gm) {
        int x = gm->playerCharacter->cellx;
        int y = gm->playerCharacter->celly;

        Cell* cell = gm->GetMap()->GetCell(x, y);

        bool canAttack = false;

        for(int x2 = -1; x2 <= 1; x2++){
            for(int y2 = -1; y2 <= 1; y2++){
                Cell* adjacentCell = gm->GetMap()->GetCell(x + x2, y + y2);
                if(adjacentCell == cell || adjacentCell == nullptr)
                    continue;

                canAttack = canAttack || adjacentCell->characterCount != 0;
                for(int i = 0; i < adjacentCell->characterCount; i++){
                    canAttack = canAttack || adjacentCell->characters[i]->GetIsDead();
                }
            }
        }
        gm->playerCharacter->isAttacking = canAttack;
        wasSuccess = canAttack;

        if(!canAttack){
            std::cout << "Nobody to attack!" << std::endl;
        }
    } // end of "execute" function
} // Game

