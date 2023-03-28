//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_PRINTMAPCOMMAND_H
#define SOUHACKATHON2023_SHAKESPEARE_PRINTMAPCOMMAND_H
#include "Command.h"
#include "GameManager.h"

namespace Game {
    class PrintMapCommand: public Command{
    public:
        void execute(GameManager *gm) override;
    };
}

#endif //SOUHACKATHON2023_SHAKESPEARE_PRINTMAPCOMMAND_H
