// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// main.cpp

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

    Hangman test2{"wordList.txt", "packetroo"};

    int randomNumber{test2.generateRandomNumber()};
    std::cout << "Hangman random number: " << randomNumber << '\n';
    std::cout << "Word from random number: " << test2.selectRandomWord(randomNumber) << '\n';

    return 0;
}