//
// Created by Brayden Edwards on 3/28/23.
//

#include "PrintMapCommand.h"
#include "GameManager.h"

using namespace Game;

void PrintMapCommand::execute(GameManager *gm) {
    int x = gm->GetMap()->GetX();
    int y = gm->GetMap()->GetY();

    for(int row = 0; row < x + 1; row++) {
        for(int column = 0; column < y + 1; column++) {

            if(row >= 0 && column - 1 >= 0 && gm->GetMap()->GetCell(column - 1, row)->characterCount > 0) {
                std::cout << " C ";
            }
            else {
                if(column == 0) {
                    if(row + 1 == y + 1) {
                        std::cout << "   ";
                    }
                    else if(row + 1 > 9) {
                        std::cout << row + 1;
                    }
                    else {
                        std::cout << row + 1 << " ";
                    }
                }
                else if(row + 1 == x + 1) {
                    if(column > 9) {
                        std::cout << column << " ";
                    }
                    else {
                        std::cout << column << "  ";
                    }
                }
                else {
                    std::cout << " . ";
                }
            }
        } // end of loop (i)
        std::cout << std::endl;
    } // end of loop (j)

} // end of "PrintMapCommand" function
