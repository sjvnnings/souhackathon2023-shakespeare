//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_MOVECOMMAND_H
#define SOUHACKATHON2023_SHAKESPEARE_MOVECOMMAND_H

#include "Command.h"

namespace Game {

    class MoveCommand: public Command {
    public:
        void execute(Game::GameManager* gm) override;
        bool IsHelper() override { return false; }
    };

} // Game

#endif //SOUHACKATHON2023_SHAKESPEARE_MOVECOMMAND_H
