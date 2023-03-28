cmake_minimum_required(VERSION 3.22.3)
project(souhackathon2023_shakespeare)

set(CMAKE_CXX_STANDARD 23)

add_executable(souhackathon2023_shakespeare main.cpp Map/Map.cpp Map/Map.h Map/Cell.cpp Map/Cell.h)
