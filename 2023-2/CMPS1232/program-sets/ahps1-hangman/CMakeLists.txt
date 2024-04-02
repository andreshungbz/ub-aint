cmake_minimum_required(VERSION 3.27)
project(ahps1_hangman)

set(CMAKE_CXX_STANDARD 11)

add_executable(ahps1_hangman main.cpp
        Player.cpp
        Player.h)
