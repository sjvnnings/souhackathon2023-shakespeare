//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_CELL_H
#define SOUHACKATHON2023_SHAKESPEARE_CELL_H

#include "../Character/Character.h"

using namespace Game::Characters;

namespace Game::Map {
    class Cell {
    private:

    public:
        Character* characters[MAX_CHARACTERS];
        int characterCount = 0;

        Fluid* fluid = nullptr;
        float fluidAmount = 0.0;

        Cell();

        void AddCharacter(Character* character);
        void RemoveCharacter(Character* character);
    };
}

#endif //SOUHACKATHON2023_SHAKESPEARE_CELL_H
