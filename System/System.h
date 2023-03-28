//
// Created by sammy on 3/28/2023.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H
#define SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H

namespace Game {
    namespace Systems {

        class System {
            //TODO: Pass map as parameter.
            virtual void execute() = 0;
        };

    } // Game
} // Systems

#endif //SOUHACKATHON2023_SHAKESPEARE_SYSTEM_H
