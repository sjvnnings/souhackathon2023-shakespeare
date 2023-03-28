//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_HELPCOMMAND_H
#define SOUHACKATHON2023_SHAKESPEARE_HELPCOMMAND_H

#include "Command.h"

namespace Game {

    class HelpCommand : public Command{
    public:
        void execute(Game::GameManager* gm) override;
        bool IsHelper() { return true; }
    };

} // Game

#endif //SOUHACKATHON2023_SHAKESPEARE_HELPCOMMAND_H
