// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// main.cpp

// IMPORTANT: when compiling using QT Creator and the ahpset1-hangman.pro project file
// on the UB school computers, the build process may hang half-way through. To fix that,
// simply make a non-affecting edit to the ahpset1-hangman.pro file e.g. # remove a comment
// then building will work. Afterward, remove the edit and the build should succeed.

// NOTE: the folder that holds all the source files and the wordlist.txt must be named ahpset1-hangman

#include <iostream>
#include "Hangman.h"

int main() {
    std::cout << "Welcome to The Hangman Game!\n";

    Hangman game{"wordlist.txt", "andreshung"};
    game.startGame();

    return 0;
}
