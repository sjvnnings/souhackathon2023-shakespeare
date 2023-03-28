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
} // end of "GenerateMap" function


void Map::DeleteMap() {
    delete[] map;
} // end of "DeleteMap" function


Cell* Map::GetCell(int x, int y) {
    return &(map[this->x * y + x]);
} // end of "GetCell" function



