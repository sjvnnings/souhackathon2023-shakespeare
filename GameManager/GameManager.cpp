//
// Created by sammy on 3/28/2023.
//

#include <iostream>
#include <map>
#include "GameManager.h"

#include "HelpCommand.h"
#include "../System/Systems/AIDecisionSystem.h"

#define SYSTEM_COUNT 1

using namespace std;
using namespace Game;
using namespace Game::Systems;

map<string, Command*> commandMap = {
        {"Help", new HelpCommand}
};

namespace Game {
    GameManager::GameManager(int x, int y) {
        map = new Map::Map(x, y);

        systems = new System*[SYSTEM_COUNT]{
            new AIDecisionSystem()
        };

        systemCount = SYSTEM_COUNT;

        characters = new Character*[MAX_CHARACTERS]{
            new Character("Julius Caesar"),
            new Character("Brutus")
        };
        characters[0]->playerControlled = true;

        map->GetCell(0,0)->AddCharacter(characters[0]);
        map->GetCell(5, 5)->AddCharacter(characters[1]);

        characters[1]->target = characters[0];

        playerCharacter = characters[0];

        characterCount = 1;
    }

    GameManager::~GameManager() {
        delete map;

        for(int i = 0; i < systemCount; i++)
            delete systems[i];
        delete[] systems;

        for(int i = 0; i < characterCount; i++)
            delete characters[i];
        delete[] characters;

        for(int i = 0; i < itemCount; i++)
            delete items[i];
        delete[] items;
    }

    void GameManager::ExecuteSimulation() {
        for(int i = 0; i < systemCount; i++){
            systems[i]->execute(map);
        }
    }

    Command* GameManager::UserInput(){
        const string delimiter = " ";

        string input = "";
        cout << endl;
        cout << "What shall you do, O greatest ruler grand?" << endl;
        getline(cin, input);

        //TODO: Actually handle player input.
        string action = input.substr(0, input.find(delimiter));
        Command* command = commandMap[action];

        if(!commandMap.contains(action) || command == nullptr){
            cout << "Unknown Command: \"" << action << "\"" << endl;
            return nullptr;
        }

        input.erase(0, input.find(delimiter) + delimiter.length());
        command->set_params(input);
        return command;
    }

    void GameManager::Start() {
        cout << "Great Caesar, on all sides traitors wait,\r\n"
                "With blades and schemes to seal your final fate.\r\n"
                "Yet, in the room's far end, a door invites,\r\n"
                "Perhaps escape awaits if you survive." << endl;

        while(true) {
            Command *command = UserInput();

            if(command != nullptr){
                command->execute(this);
                ExecuteSimulation();
            }
        }
    }

    Game::Map::Map *GameManager::GetMap() {
        return map;
    }


} // Game