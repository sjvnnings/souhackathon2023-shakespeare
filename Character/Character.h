//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H
#define SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H

#include <string>
#include "../Items/Item.h"

#define MAX_ITEMS 16
#define MAX_CHARACTERS 16

using namespace Game::Items;

namespace Game::Characters{
    class Character {
        private:
            float energy;
            std::string name;
            bool isDead;

        public:
            Item* items[MAX_ITEMS];
            int itemCount = 0;

            bool playerControlled = false;

            Character(std::string name, Item** initialItems = nullptr, int initialItemCount = 0);
            void SetEnergy(float energy);
            void ModifyEnergy(float addedEnergy);
            void SetIsDead(bool isDead);
            std::string GetName();
            float GetEnergy();
            bool GetIsDead();

    };
}


#endif //SOUHACKATHON2023_SHAKESPEARE_CHARACTER_H
