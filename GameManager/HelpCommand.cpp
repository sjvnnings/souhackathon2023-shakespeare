//
// Created by sammy on 3/28/2023.
//

#include "HelpCommand.h"

namespace Game {
    void HelpCommand::execute(Game::GameManager* gm) {
        std::cout << "Help - Prints a list of commands" << std::endl;
        std::cout << "Map - Prints the map" << std::endl;
        std::cout << "Move x y - Moves Caesar to the specified cell (example: Move 3 2)" << std::endl;
        std::cout << "Attack - Kill all enemies in adjacent cells" << std::endl;
    }
} // Game