//
// Created by Brayden Edwards on 3/28/23.
//

#include "Cell.h"
#include "Map.h"

using namespace Game::Map;

Map::Map(int x, int y) {
    this->x = x;
    this->y = y;
    GenerateMap(x, y);
} // end of "Map" constructor


int Map::GetX(){
    return x;
} // end of "GetX" function


int Map::GetY() {
    return y;
} // end of "GetY" function


void Map::GenerateMap(int x, int y) {
    map = new Cell [x * y];

    for(int iX = 0; iX < x; iX++){
        for(int iY = 0; iY < y; iY++){
            GetCell(iX, iY)->SetCoords(iX, iY);
            GetCell(iX, iY)->characterCount = 0;
        }
    }
} // end of "GenerateMap" function


void Map::DeleteMap() { // this function deletes the map array including Cell objects
    delete[] map;
} // end of "DeleteMap" function


Cell* Map::GetCell(int x, int y) {
    // ensuring that the user is within the bounds of the array. if not in bounds, return nullptr. Else, return the Cell pointer object
    if(x > this->x || y > this->y || x < 0 || y < 0) {
        return nullptr;
    }
    else {
        return &(map[this->x * y + x]);
    }
} // end of "GetCell" function



