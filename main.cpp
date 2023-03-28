#include <iostream>
#include "GameManager/GameManager.h"

#define DEFAULT_MAP_X 16
#define DEFAULT_MAP_Y 16

using namespace Game;

GameManager* game;

int main() {
    game = new GameManager(DEFAULT_MAP_X, DEFAULT_MAP_Y);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
