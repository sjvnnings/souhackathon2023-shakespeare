//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_ATTACKCOMMAND_H
#define SOUHACKATHON2023_SHAKESPEARE_ATTACKCOMMAND_H

#include "Command.h"

namespace Game {
    class AttackCommand : public Command {
    private:
        bool wasSuccess = false;
    public:
        void execute(Game::GameManager* gm) override;
        bool IsHelper() override { return !wasSuccess; }
    };
} // Game



#endif //SOUHACKATHON2023_SHAKESPEARE_ATTACKCOMMAND_H
