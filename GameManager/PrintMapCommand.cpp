//
// Created by Brayden Edwards on 3/28/23.
//

#include "PrintMapCommand.h"
#include "GameManager.h"

using namespace Game;

void PrintMapCommand::execute(GameManager *gm) {
    // Variables
    int x = gm->GetMap()->GetX();
    int y = gm->GetMap()->GetY();

    // for loops loop through the entire map checking for parameters.
    for(int row = 0; row < x + 1; row++) {
        for(int column = 0; column < y + 1; column++) {
            // Variables
            Cell* cell = gm->GetMap()->GetCell(column - 1, row);
            std::string symbol = " C ";
            bool isValidCell = (row >= 0 && column - 1 >= 0);

            if(isValidCell && cell->characterCount > 0) { // Checking if row and column are valid cells in the loop and if there are characters at that cell.
                for(int i = 0; i < cell->characterCount; i++){  // looping through the characters at a given cell and removing them if they are dead, or adding "J" if they are Julius Caesar.
                    if(cell->characters[i] == gm->playerCharacter){
                        symbol = " J ";
                    }
                    else if(cell->characters[i]->GetIsDead()){
                        symbol = " . ";
                    }
                }

                std::cout << symbol; // outputting the proper output based on above conditions
            }
            else if(isValidCell && cell->isEscape){ // if the cell is the escape cell, outputting a bracket at that location.
                std::cout << " ] ";
            }
            else { // if the cell has no characters and is not the escape cell.
                // printing numbers if the column equals 0 or the row is on its final iteration. Else, printing " . " to show an empty location.
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
                else if(row + 1 == x + 1) { // checking if row is on its final iteration
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
        std::cout << std::endl; // printing a new line after each iteration of column
    } // end of loop (j)

} // end of "PrintMapCommand" function
