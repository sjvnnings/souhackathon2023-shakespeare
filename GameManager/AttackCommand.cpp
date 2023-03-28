//
// Created by Brayden Edwards on 3/28/23.
//

#include "AttackCommand.h"

namespace Game {
    void Game::AttackCommand::execute(Game::GameManager *gm) {
        gm->playerCharacter->isAttacking = true;
    } // end of "execute" function
} // Game

