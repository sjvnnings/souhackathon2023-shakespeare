cmake_minimum_required(VERSION 3.22.3)
project(souhackathon2023_shakespeare)

set(CMAKE_CXX_STANDARD 23)

add_executable(souhackathon2023_shakespeare main.cpp Map/Map.cpp Map/Map.h Map/Cell.cpp Map/Cell.h GameManager/GameManager.cpp GameManager/Command.cpp GameManager/Command.h GameManager/HelpCommand.cpp GameManager/HelpCommand.h Items/Item.cpp Items/Item.h Character/Character.h Character/Character.cpp System/Systems/AIDecisionSystem.cpp System/Systems/AIDecisionSystem.h)
