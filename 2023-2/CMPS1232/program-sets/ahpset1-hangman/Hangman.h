// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Header

#ifndef AHPSET1_HANGMAN_HANGMAN_H
#define AHPSET1_HANGMAN_HANGMAN_H


#include "Player.h"
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <random>
#include <vector>

class Hangman {
public:
    const static int ALPHABET_SIZE = 26; // num of rows for alphabet array
    const static int ASCII_ROWS = 7;
    const static int ASCII_COLS = 8;

    Hangman(std::string filename, std::string username);

    int selectGameLevel();

    int generateRandomNumber();

    std::string selectRandomWord(int random_number);

    void loadWordList(std::string fileName);

    void startGame();

    void printMessage(std::string message, bool printTop = true, bool printBottom = true);

    void drawHangman(int guessCount = 0);

    void resetAvailableLetters();

    void printAsciiMessage(std::string message);

    void printAvailableLetters(std::string taken);

    bool checkWin(std::string wordToGuess, std::string guessesSoFar);

    bool processResults(std::string wordToGuess, int guessAttempts, bool hasWon);

    void setDifficultyLevel(unsigned diffLevel);

    unsigned getDifficultyLevel();

    void setMaxAllowedAttempts(unsigned allowedAttempts);

    unsigned getMaxAllowedAttempts();

    unsigned attemptsMadeSoFar(std::string wordToGuess, std::string guessesSoFar);

private:
    Player player;
    std::vector<std::string> wordVector;
    unsigned difficultyLevel;
    unsigned maxAllowedAttempts;
    char alphabetArray[ALPHABET_SIZE + 1];
    constexpr static char G[ASCII_ROWS][ASCII_COLS] = {" ##### ", // Row=0
                                                       " #     ", // Row=1
                                                       " #     ", // Row=2
                                                       " # ### ", // Row=3
                                                       " #   # ", // Row=4
                                                       " #   # ", // Row=5
                                                       " ##### "}; // Row=6
};


#endif //AHPSET1_HANGMAN_HANGMAN_H
