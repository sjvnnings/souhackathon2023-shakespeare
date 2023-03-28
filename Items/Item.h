//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_ITEM_H
#define SOUHACKATHON2023_SHAKESPEARE_ITEM_H

#include <string>

using namespace std;

namespace Game {
    namespace Items {

        class Fluid{
        public:
            float viscosity = 0.0;
        };

        class Item {
        public:
            float sharpness = 0.0;
            float mass = 1.0; //Kilograms
            float sturdiness = 1.0;

            Item* subItem = nullptr; //Item contained with this item.
            Fluid* subFluid = nullptr; //Fluid contained within this object.

            string name;
        };

    } // Game
} // Items

#endif //SOUHACKATHON2023_SHAKESPEARE_ITEM_H
