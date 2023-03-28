//
// Created by Brayden Edwards on 3/28/23.
//

#include "Cell.h"

using namespace Game::Map;
using namespace Game::Characters;

Cell::Cell() {

} // end of "Cell" constructor

void Cell::AddCharacter(Character *character) {
    if(characterCount == MAX_CHARACTERS)
        return;

    character->SetCellCoords(x, y);

    characters[characterCount] = character;
    characterCount++;
} // end of "AddCharacter" function

void Cell::RemoveCharacter(Character *character) {
    bool has_found_character = false;

    for(int i = 0; i < characterCount; i++){
        Character* c = characters[i];

        if(has_found_character)
            characters[i - 1] = c;

        if(c == character)
            has_found_character = true;
    }

    if(has_found_character)
        characterCount--;
} // end of "RemoveCharacter" function

void Cell::SetCoords(int x, int y) {
    this->x = x;
    this->y = y;
} // end of "SetCoords" function
