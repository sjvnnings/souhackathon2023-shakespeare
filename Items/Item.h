//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_ITEM_H
#define SOUHACKATHON2023_SHAKESPEARE_ITEM_H

#include <string>

using namespace std;

namespace Game {
    namespace Items {

        class Item {
        public:
            float sharpness = 0.0;
            float mass = 1.0; //Kilograms

            string name;
        };

    } // Game
} // Items

#endif //SOUHACKATHON2023_SHAKESPEARE_ITEM_H
