//
// Created by Brayden Edwards on 3/28/23.
//

#include "Character.h"
#include <string>
using namespace Game::Character;

Character::Character(std::string name) {
    this->name = name;
    energy = 1;
    isDead = false;
} // end of "Character" constructor


void Character::SetEnergy(float energy) {
    if(energy <= 1) {
        this->energy = energy;
    }
    if(energy <= 0) {
        SetIsDead(true);
    }
} // end of "SetHealth" function


void Character::ModifyEnergy(float addedEnergy) {
    energy += addedEnergy;
    if(energy <= 0) {
        SetIsDead(true);
    }
} // end of "ModifyEnergy" function


void Character::SetIsDead(bool isDead) {
    this->isDead = isDead;
} // end of "SetIsDead" function


std::string Character::GetName() {
    return name;
} // end of "GetName" function


float Character::GetEnergy() {
    return energy;
} // end of "GetHealth" function


bool Character::GetIsDead() {
    return isDead;
} // end of "GetIsDead" function


