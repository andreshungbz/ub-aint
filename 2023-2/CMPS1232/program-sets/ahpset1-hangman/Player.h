// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Player Class Header

#ifndef AHPS1_HANGMAN_PLAYER_H
#define AHPS1_HANGMAN_PLAYER_H

#include <string>

class Player {
public:
    Player(std::string username, unsigned int level = 1);
    void setDifficultyLevel(unsigned int level);
    int getDifficultyLevel();
    void setUsername(std::string name);
    std::string getUsername();
    void setGuesses(unsigned int numGuesses);
    std::string generateStatistics();
    void resetGuessesArray();
private:
    int guessesArray[10]; // keeps track of the 10 most recent game scores
    char username[20];
    unsigned int difficultyLevel;
    static const unsigned int MAX_DIFFICULTY_LEVEL {3};
};


#endif //AHPS1_HANGMAN_PLAYER_H
