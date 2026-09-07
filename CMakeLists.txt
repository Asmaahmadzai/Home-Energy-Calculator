cmake_minimum_required(VERSION 4.2)
project(A02_starting_files C)
set(CMAKE_C_STANDARD 11)

include_directories(.)
add_executable(A02_starting_files
        declarations.h
        definitions.c
        main.c)
add_executable(A02_tests test_main.c definitions.c)
