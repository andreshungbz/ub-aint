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
    Player test{"andreshung"};

    std::cout << "username: " << test.getUsername() << '\n';
    std::cout << "difficultyLevel: " << test.getDifficultyLevel() << '\n';

    test.setUsername("andreshungbz");
    test.setDifficultyLevel(3);

    std::cout << "username: " << test.getUsername() << '\n';
    std::cout << "difficultyLevel: " << test.getDifficultyLevel() << '\n';

    test.setGuesses(5);
    test.setGuesses(4);
    test.setGuesses(3);
    test.setGuesses(2);
    test.setGuesses(1);

    std::cout << test.generateStatistics() << '\n';

    Hangman test2{"wordlist.txt", "packetroo"};

    int randomNumber{test2.generateRandomNumber()};
    std::cout << "Hangman random number: " << randomNumber << '\n';
    std::cout << "Word from random number: " << test2.selectRandomWord(randomNumber) << '\n';

    test2.printMessage("");

    return 0;
}
