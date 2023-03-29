//
// Created by sammy on 3/28/2023.
//

#include <iostream>
#include <map>
#include "GameManager.h"

#include "HelpCommand.h"
#include "../System/Systems/AIDecisionSystem.h"
#include "PrintMapCommand.h"
#include "MoveCommand.h"
#include "../System/Systems/CheckEscapeSystem.h"
#include "../System/Systems/AttackSystem.h"
#include "AttackCommand.h"

#define SYSTEM_COUNT 3

using namespace std;
using namespace Game;
using namespace Game::Systems;

PrintMapCommand* mapCmd = new PrintMapCommand;

map<string, Command*> commandMap = {
        {"Help", new HelpCommand},
        {"Map", mapCmd},
        {"Move", new MoveCommand},
        {"Attack", new AttackCommand}
};

Character* allCharacters[5] = {
    new Character("Marcus Brutus", "Brutus, Marcus, met his tragic demise."),
        new Character("Gaius Cassius Longinus", "Longinus Cassius met his fateful end."),
        new Character("Servilius Casca", "Casca Servilius met his mortal end."),
        new Character("Tillius Cimber", "Cimber Tillius met his final fate."),
        new Character("Trebonius", "Trebonius, alas, met his fatal end.")
};

namespace Game {
    GameManager::GameManager(int x, int y) {
        srand(time(NULL));

        map = new Map::Map(x, y);

        systems = new System*[SYSTEM_COUNT]{
            new AttackSystem(),
            new AIDecisionSystem(),
            new CheckEscapeSystem()
        };

        systemCount = SYSTEM_COUNT;

        //Random number of enemies between 2 and 4.
        int charCount = rand() % 3 + 2;

        characters = new Character*[charCount + 1]{
            new Character("Julius Caesar", "")
        };

        characters[0]->playerControlled = true;
        map->GetCell(rand() % x, rand() % y)->AddCharacter(characters[0]);
        playerCharacter = characters[0];

        for(int i = 1; i < charCount + 1; i++){
            Character* character = nullptr;

            //Ensure that randomly selected character is unique (i.e. not already in the characters array.
            while(character == nullptr) {
                character = allCharacters[rand() % 5];

                for(int i2 = 1; i2 < i; i2++){
                    if(character == characters[i2])
                        character = nullptr;
                }
            }

            character->target = characters[0];

            Cell* cell = map->GetCell(rand() % x, rand() % y);

            while(cell->characterCount != 0)
                cell = map->GetCell(rand() % x, rand() % y);

            cell->AddCharacter(character);
            characters[i] = character;
        }

        Cell* exitCell = map->GetCell(rand() % x, rand() % y);
        while(exitCell->characterCount != 0)
            exitCell = map->GetCell(rand() % x, rand() % y);

        exitCell->isEscape = true;

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

    void GameManager::EndGame(){
        if(map->isVictory) {
            std::cout << "Hail Julius Caesar, thou hast escaped\n"
                         "Thine enemies' grasp, take care and stay safe\n"
                         "Thou dost live to fight another day\n"
                         "With cunning wit and sword, thy foes dismayed.\n" << std::endl;
        }else{
            std::cout << "We mourn the loss of Julius Caesar's life,\n"
                         "Slain by his very enemies in strife.\n"
                         "May Mark Anthony avenge thee with might,\n"
                         "And bring thy foes to justice with his right.\n" << std::endl;
        }
    }

    void GameManager::ExecuteSimulation() {
        for(int i = 0; i < systemCount; i++){
            systems[i]->execute(map);
            if(map->isGameOver){
                EndGame();
                return;
            }
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

        bool newTurn = true;

        while(!map->isGameOver) {
            if(newTurn)
                mapCmd->execute(this);
            newTurn = false;

            Command *command = UserInput();

            if(command != nullptr){
                command->execute(this);

                if(!command->IsHelper()) {
                    ExecuteSimulation();
                    newTurn = true;
                }

            }
        }
    }

    Game::Map::Map *GameManager::GetMap() {
        return map;
    }


} // Game