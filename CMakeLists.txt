cmake_minimum_required(VERSION 3.20)
project(HomeEnergyCalculator C)

set(CMAKE_C_STANDARD 11)

add_executable(HomeEnergyCalculator
        main.c
        definitions.c)
