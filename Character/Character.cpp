//
// Created by Brayden Edwards on 3/28/23.
//

#include "Character.h"
#include <string>
using namespace Game::Characters;

Character::Character(std::string name, std::string deathMessage, Item** initialItems, int initialItemCount) {
    this->name = name;
    this->deathMessage = deathMessage;
    energy = 1;
    isDead = false;


    for(int i = 0; i < initialItemCount && i < MAX_ITEMS; i++){
        items[i] = initialItems[i];
    }

    itemCount = initialItemCount;
} // end of "Character" constructor


void Character::SetEnergy(float energy) { // Intended for an unused system. This function was designed to track the level of energy each character has. Once the energy was at 0, the character died.
    if(energy <= 1) {
        this->energy = energy;
    }
    // if energy is less than or equal to 0, the character dies
    if(energy <= 0) {
        SetIsDead(true);
    }
} // end of "SetHealth" function


void Character::ModifyEnergy(float addedEnergy) { // Intended for an unused system. This function was designed to change the levels of a given character's energy.
    energy += addedEnergy; // Intended to take negative and positive values
    if(energy <= 0) { // once the character's energy was at or less than 0, the character would die.
        SetIsDead(true);
    }
} // end of "ModifyEnergy" function


void Character::SetIsDead(bool isDead) { // this function returns if the player is dead
    this->isDead = isDead;
} // end of "SetIsDead" function


std::string Character::GetName() {
    return name;
} // end of "GetName" function

std::string Character::GetDeathMessage() {
    return deathMessage;
} // end of "GetName" function

float Character::GetEnergy() {
    return energy;
} // end of "GetHealth" function


bool Character::GetIsDead() {
    return isDead;
} // end of "GetIsDead" function


void Character::SetCellCoords(int x, int y) { // this function sets the x and y location of the given character.
    cellx = x;
    celly = y;
} // end of "SetCellCoord" function



