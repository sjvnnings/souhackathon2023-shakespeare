//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H
#define SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H

#include <string>
#include "../Items/Item.h"

using namespace Game::Items;

namespace Game::Character{
    class Character {
        private:
            float energy;
            std::string name;
            bool isDead;

        public:
            Item** items;

            Character(std::string name);
            void SetEnergy(float energy);
            void ModifyEnergy(float addedEnergy);
            void SetIsDead(bool isDead);
            std::string GetName();
            float GetEnergy();
            bool GetIsDead();

    };
}


#endif //SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H
