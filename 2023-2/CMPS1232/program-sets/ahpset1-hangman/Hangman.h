// CMPS1232 Principles of Programming 2
// Program Set 1 - Hangman Game
// Date Due: 2024-04-21
// Name: Andres Hung

// Hangman Class Header

#ifndef AHPSET1_HANGMAN_HANGMAN_H
#define AHPSET1_HANGMAN_HANGMAN_H


#include "Player.h"
#include <cctype>
#include <chrono>
#include <cstdlib>
// #include <ctime>
#include <fstream>
#include <limits>
#include <stdio.h>
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
    char alphabetArray[ALPHABET_SIZE]; // NOTE: removed original + 1 as it is not needed

    // ASCII letter definitions are located in Hangman.cpp
    constexpr static char G[ASCII_ROWS][ASCII_COLS] {" ##### ", // Row=0
                                                     " #     ", // Row=1
                                                     " #     ", // Row=2
                                                     " # ### ", // Row=3
                                                     " #   # ", // Row=4
                                                     " #   # ", // Row=5
                                                     " ##### "}; // Row=6

    constexpr static char A[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char M[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ## ## ",
                                                     " # # # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char E[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### "};

    constexpr static char O[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char V[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     "  # #  ",
                                                     "   #   "};

    constexpr static char R[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " # #   ",
                                                     " #  #  ",
                                                     " #   # "};

    constexpr static char Y[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     "  # #  ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   "};

    constexpr static char U[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char W[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " # # # ",
                                                     " ## ## ",
                                                     " #   # "};

    constexpr static char N[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ##  # ",
                                                     " # # # ",
                                                     " #  ## ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char exclamation[ASCII_ROWS][ASCII_COLS] {"   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "       ",
                                                               "   #   ",
                                                               "   #   "};

    constexpr static char space[ASCII_ROWS][ASCII_COLS] {"       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       "};
};


#endif // AHPSET1_HANGMAN_HANGMAN_H
