//
// Created by Brayden Edwards on 3/28/23.
//

#include "PrintMapCommand.h"
#include "GameManager.h"

using namespace Game;

void PrintMapCommand::execute(GameManager *gm) {
    int x = gm->GetMap()->GetX();
    int y = gm->GetMap()->GetY();

    for(int column = 0; column < x + 1; column++) {
        for(int row = 0; row < y + 1; row++) {
            if(row == 0) {
                if(column + 1 == y + 1) {
                   std::cout << "   ";
                }
                else if(column + 1 > 9) {
                    std::cout << column + 1;
                }
                else {
                    std::cout << column + 1 << " ";
                }
            }
            else if(column + 1 == x + 1) {
                if(row > 9) {
                    std::cout << row << " ";
                }
                else {
                    std::cout << row << "  ";
                }
            }
            else {
                std::cout << " . ";
            }
        } // end of loop (i)
        std::cout << std::endl;
    } // end of loop (j)

} // end of "PrintMapCommand" function
