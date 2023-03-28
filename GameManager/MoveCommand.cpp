//
// Created by Brayden Edwards on 3/28/23.
//

#include "MoveCommand.h"
#include <iostream>
#include <string>

namespace Game {
    void MoveCommand::execute(Game::GameManager *gm) {
        const string delimiter = " ";
        std::string invalidMoveMessage = "An invalid move hath been made, 'tis clear,\n"
                                         "Pray try again with care and thou shalt hear.\n";
        std::string x = params.substr(0, params.find(delimiter));
        std::string y = params.substr(params.find(delimiter) + 1, params.length() - 1);
        int xInt = std::stoi(x) - 1;
        int yInt = std::stoi(y) - 1;
        bool adjacentCell = false;

        if(xInt >= 0 && xInt < gm->GetMap()->GetX() && yInt >= 0 && yInt < gm->GetMap()->GetY()) {
            if(abs((xInt - gm->playerCharacter->cellx) + (yInt - gm->playerCharacter->celly)) == 1){
                adjacentCell = true;
            }
            else {
                std::cout << invalidMoveMessage;
            }

            if(adjacentCell == true && gm->GetMap()->GetCell(xInt, yInt)->characterCount == 0){
                gm->GetMap()->GetCell(gm->playerCharacter->cellx, gm->playerCharacter->celly)->RemoveCharacter(gm->playerCharacter);
                gm->GetMap()->GetCell(xInt, yInt)->AddCharacter(gm->playerCharacter);
            }
        }
        else {
            std::cout << invalidMoveMessage;
        }
    } // end of "MoveCommand" function
} // Game